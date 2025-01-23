/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:21 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/23 16:20:42 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

//info       --> Create child routine
//av         --> Arg that indicates the file to open
//pipe_fd    --> Pipe fd[2], o read e o write
//env        --> All environmental variables

void	child(char **av, int *pipe_fd, char **env)
{
	int	input_fd;

	input_fd = open_file(av[1], 0);
	if (input_fd == -1)
	{
		ft_printf("%s%s\n", ERR_OPEN_INPUT, av[1]);
		return ;
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1 || dup2(input_fd, STDIN_FILENO) == -1)
	{
		ft_printf("%s\n", ERR_DUP);
		close(input_fd);
		return ;
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(input_fd);
	exec_cmd(av[2], env);
}

//info       --> Create parent routine
//av         --> Arg that indicates the file to open
//pipe_fd    --> Pipe fd[2], o read e o write
//env        --> All environmental variables
//child_pid		 --> The pid of the child the parent has to wait for

void	parent(char **av, int *pipe_fd, char **env, pid_t child_pid)
{
	int	output_fd;

	output_fd = open_file(av[4], 1);
	if (output_fd == -1)
	{
		ft_printf("%s%s\n", ERR_OPEN_OUTPUT, av[4]);
		return ;
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1 || dup2(output_fd, STDOUT_FILENO) == -1)
	{
		ft_printf("%s\n", ERR_DUP);
		close(output_fd);
		return ;
	}
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	close(output_fd);
	waitpid(child_pid, NULL, 0);
	exec_cmd(av[3], env);
}

//info       --> Create parent routine
//ac         --> Argc
//av         --> Argv
//env        --> All environmental variables

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (ac != 5)
		return (ft_printf("%s\n", ERR_ARGS), 1);
	if (pipe(pipe_fd) == -1)
		return (ft_printf("%s\n", ERR_PIPE), 1);
	pid = fork();
	if (pid == -1)
		return (ft_printf("%s\n", ERR_FORK), 1);
	if (pid == 0)
		child(av, pipe_fd, env);
	else if (pid > 0)
		parent(av, pipe_fd, env, pid);
	return (0);
}
