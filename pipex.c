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

#include "pipex.h"

//info       --> Handle the here doc correctly
//limiter    --> Str that indicates the end of prompt
//pipe_fd    --> Pipe fd[2], read and write

void	handle_here_doc(t_pipex *pipex)
{
	char		*line;
	const char	*limiter;

	limiter = pipex->av[2];
	close(pipex->pipe_fd[0]);
	while (1)
	{
		ft_printf("pipex here_doc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(pipex->pipe_fd[1], line, ft_strlen(line));
		free(line);
		line = NULL;
	}
	close(pipex->pipe_fd[1]);
}

void	parent(t_pipex *pipex)
{
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
	main_process(pipex);
}

//info       --> Create child routine

void	child(t_pipex *pipex)
{
	int	input_fd;

	close(pipex->pipe_fd[0]);
	if (ft_strncmp(pipex->av[1], "here_doc", 8) == 0 && pipex->cmd_index == 2)
	{
		handle_here_doc(pipex);
		exit(EXIT_SUCCESS);
	}
	if (pipex->cmd_index == 2)
	{
		input_fd = open(pipex->av[1], O_RDONLY);
		if (input_fd == -1)
			errors(ERR_OPEN_INPUT, pipex->av[1], 1);
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[1]);
	exec_cmd(pipex->av[pipex->cmd_index], pipex->env, pipex->pipe_fd, 0);
	exit(EXIT_FAILURE);
}

//info       --> The process to be repeated for each cmd

void	main_process(t_pipex *pipex)
{
	while (pipex->cmd_index < pipex->ac - 2)
	{
		if (pipe(pipex->pipe_fd) == -1)
			ft_putstr_fd(ERR_PIPE, 2);
		pipex->pid = forking(pipex);
		if (pipex->pid == 0)
		{
			close(pipex->pipe_fd[0]);
			child(pipex);
		}
		close(pipex->pipe_fd[1]);
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
		close(pipex->pipe_fd[0]);
		pipex->cmd_index++;
	}
	open_file(pipex);
	dup2(pipex->final_output_fd, STDOUT_FILENO);
	close(pipex->final_output_fd);
	exec_cmd(pipex->av[pipex->cmd_index], pipex->env, pipex->pipe_fd, 0);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		return (ft_putstr_fd(ERR_ARGS, 2), 1);
	if ((ft_strncmp(av[1], "here_doc", 8) == 0 && ac < 6))
		return (ft_putstr_fd(ERR_ARGS_BONUS, 2), 1);
	init_pipex(&pipex, ac, av, env);
	if (pipex.cmd_index == 3)
	{
		if (pipe(pipex.pipe_fd) == -1)
			return (ft_putstr_fd(ERR_PIPE, 2), 1);
		pipex.pid = forking(&pipex);
		if (pipex.pid == 0)
			handle_here_doc(&pipex);
		else
			parent(&pipex);
	}
	else
		main_process(&pipex);
	return (0);
}
