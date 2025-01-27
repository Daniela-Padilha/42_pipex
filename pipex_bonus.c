/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:17:22 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/24 17:17:22 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

//info       --> Handle the here doc correctly
//limiter    --> Str that indicates the end of prompt
//pipe_fd    --> Pipe fd[2]

void	handle_here_doc(const char *limiter, int *pipe_fd)
{
	char	*line;

	close(pipe_fd[0]);
	while (1)
	{
		ft_printf("> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipe_fd[1]);
}

//info       --> Create child routine
//av         --> Arg that indicates the file to open
//pipe_fd    --> Pipe fd[2], o read e o write
//env        --> All environmental variables

void	child(char **av, int *pipe_fd, char **env)
{
	int	input_fd;

	close(pipe_fd[0]);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		handle_here_doc(av[2], pipe_fd);
		exit(EXIT_SUCCESS);
	}
	else
		input_fd = open(av[1], O_RDONLY);
	if (input_fd == -1)
	{
		ft_printf("%s%s\n", ERR_OPEN_INPUT, av[1]);
		close(pipe_fd[1]);
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(input_fd, STDIN_FILENO);
	close(pipe_fd[1]);
	close(input_fd);
	exec_cmd(av[2], env);
}
//info       --> Create parent routine
//av         --> Arg that indicates the file to open
//pipe_fd    --> Pipe fd[2], o read e o write
//env        --> All environmental variables
//child_pid	 --> The pid of the child the parent has to wait for

void	parent(char **av, int *pipe_fd, char **env)
{
	int	output_fd;

	close(pipe_fd[1]);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		output_fd = open(av[5], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		output_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		ft_printf("%s%s\n", ERR_OPEN_OUTPUT, av[4]);
		close(pipe_fd[0]);
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(output_fd);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		exec_cmd(av[4], env);
	else
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

	if ((ft_strncmp(av[1], "here_doc", 8) != 0) && (ac < 5))
		return (ft_putstr_fd(ERR_ARGS, 2), 1);
	if ((ft_strncmp(av[1], "here_doc", 8) == 0) && (ac != 6))
		return (ft_putstr_fd(ERR_ARGS_BONUS, 2), 1);
	if (pipe(pipe_fd) == -1)
		return (ft_putstr_fd(ERR_PIPE, 2), 1);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (ft_putstr_fd(ERR_FORK, 2), 1);
	}
	if (pid == 0)
		child(av, pipe_fd, env);
	else if (pid > 0)
		parent(av, pipe_fd, env);
	return (0);
}
