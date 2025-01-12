/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:52:33 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/12 17:04:59 by ddo-carm         ###   ########.fr       */
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
	int	fd;

	fd = open_file(av[1], 0);
	if (fd == -1)
	{
		perror("ERROR: opening input file failed");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[1], 1) == -1 || dup2(fd, 0) == -1)
	{
		perror("ERROR: fd failure");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd);
	exec_cmd(av[2], env);
}

//info       --> Create parent routine
//av         --> Arg that indicates the file to open
//pipe_fd    --> Pipe fd[2], o read e o write
//env        --> All environmental variables

void	parent(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	if (fd == -1)
	{
		perror("ERROR: opening output file failed");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[0], 0) == -1 || dup2(fd, 1) == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(fd);
		perror("ERROR: fd failure");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd);
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

	if (ac == 5)
	{
		if (pipe(pipe_fd) == -1)
			exit(EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			child(av, pipe_fd, env);
		else
		{
			waitpid(pid, NULL, 0);
			parent(av, pipe_fd, env);
		}
	}
	else
	{
		ft_printf("Error: Format must be './pipex infile cmd cmd outfile'");
		exit(EXIT_FAILURE);
	}
	return (0);
}
