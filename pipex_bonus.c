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
//pipe_fd    --> Pipe fd[2], read and write

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
//pipe_fd    --> Pipe fd[2], read and write
//env        --> All environmental variables

void	child(char **av, int *pipe_fd, char **env, int cmd_index)
{
	int	input_fd;

	close(pipe_fd[0]);
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && cmd_index == 2)
	{
		handle_here_doc(av[2], pipe_fd);
		exit(EXIT_SUCCESS);
	}
	if (cmd_index == 2)
	{
		input_fd = open(av[1], O_RDONLY);
		if (input_fd == -1)
		{
			ft_printf("%s%s\n", ERR_OPEN_INPUT, av[1]);
			exit(EXIT_FAILURE);
		}
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	exec_cmd(av[cmd_index], env);
	exit(EXIT_FAILURE);
}

//info       --> Create parent routine
//av         --> Arg that indicates the file to open
//pipe_fd    --> Pipe fd[2], read and write
//env        --> All environmental variables
//child_pid	 --> The pid of the child the parent has to wait for

void	parent(int ac, char **av, int *pipe_fd, char **env, int cmd_index)
{
	int	output_fd;

	close(pipe_fd[1]);
	if (cmd_index == ac - 2)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
			output_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			output_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (output_fd == -1)
		{
			ft_printf("%s%s\n", ERR_OPEN_OUTPUT, av[ac - 1]);
			exit(EXIT_FAILURE);
		}
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	exec_cmd(av[cmd_index], env);
	exit(EXIT_FAILURE);
}

//info       --> Create parent routine
//ac         --> Argc
//av         --> Argv
//env        --> All environmental variables

void	main_process(int ac, char **av, char **env, int cmd_index)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		final_output_fd;

	while (cmd_index < ac - 2)
	{
		if (pipe(pipe_fd) == -1)
			ft_putstr_fd(ERR_PIPE, 2);
		pid = forking(pipe_fd);
		if (pid == 0)
		{
			close(pipe_fd[0]);
			child(av, pipe_fd, env, cmd_index);
		}
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		cmd_index++;
	}
	final_output_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (final_output_fd == -1)
		exit(ft_printf("%s%s\n", ERR_OPEN_OUTPUT, av[ac - 1]));
	dup2(final_output_fd, STDOUT_FILENO);
	close(final_output_fd);
	exec_cmd(av[cmd_index], env);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (ac < 5)
		return (ft_putstr_fd(ERR_ARGS, 2), 1);
	if ((ft_strncmp(av[1], "here_doc", 8) == 0 && ac < 6))
		return (ft_putstr_fd(ERR_ARGS_BONUS, 2), 1);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (pipe(pipe_fd) == -1)
			return (ft_putstr_fd(ERR_PIPE, 2), 1);
		pid = forking(pipe_fd);
		if (pid == 0)
			handle_here_doc(av[2], pipe_fd);
		else
		{
			close(pipe_fd[1]);
			dup2(pipe_fd[0], STDIN_FILENO);
			close(pipe_fd[0]);
			main_process(ac, av, env, 3);
		}
	}
	else
		main_process(ac, av, env, 2);
	return (0);
}
