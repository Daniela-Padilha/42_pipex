/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:42 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/22 14:03:42 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

//info    --> Initialize pipex structure

void	init_pipex(t_pipex *pipex, int ac, char **av, char **env)
{
	pipex->av = av;
	pipex->env = env;
	pipex->ac = ac;
	pipex->cmd_index = 2;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		pipex->cmd_index = 3;
}

//info    --> Create a child and security condition in case of error

pid_t	forking(t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
		ft_putstr_fd(ERR_FORK, 2);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

//info    --> Free all the strings in an array and the array itself
//paths   --> Array of strings to be freed

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

//info        --> Get path for the cmd
//cmd         --> Comand to be executed
//env         --> All environmental variables
//paths       --> Isolates only the env PATH and splits it into strs with the
//                beginning of the path for the cmd
//part_path   --> Adds the "/" to make the middle part of a path
//exec        --> Adds the cmd to the path, completing the executable path
//return      --> The path to the cmd

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*part_path;
	char	*exec;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
		i++;
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (ft_printf("%sft_split in get_path\n", ERR_MALLOC), NULL);
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
			return (free_paths(paths), exec);
		free(exec);
		i++;
	}
	ft_putstr_fd(ERR_CMD, 2);
	write(2, cmd, ft_strlen(cmd));
	return (write(2, "\n", 1), free_paths(paths), exit(CMD_NOT_FOUND), NULL);
}

//info     --> Execute a comand
//cmd      --> Comand to be executed
//env      --> All environmental variables
//path     --> Path to the command
//cmd_args --> Array of the args of the command

void	exec_cmd(char *cmd, char **env, int *pipe_fd, int i)
{
	char	*path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if(!cmd_args[i])
	{
		ft_putstr_fd(ERR_ARGS, 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strchr(cmd_args[0], '/'))
		path = ft_strdup(cmd_args[0]);
	else
		path = get_path(cmd_args[0], env);
	if (!path)
	{
		free_paths(cmd_args);
		exit(EXIT_FAILURE);
	}
	execve(path, cmd_args, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	free(path);
	free_paths(cmd_args);
	ft_printf("%s%s\n", ERR_EXECVE, cmd);
	exit(EXIT_FAILURE);
}
