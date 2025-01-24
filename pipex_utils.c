/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:29 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/24 16:34:22 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

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
	write(2, &ERR_CMD, 26);
	write(2, cmd, ft_strlen(cmd));
	return (write(2, "\n", 1), free_paths(paths), exit(CMD_NOT_FOUND), NULL);
}

//info     --> Execute a comand
//cmd      --> Comand to be executed
//env      --> All environmental variables
//path     --> Path to the command
//cmd_args --> Array of the args of the command

void	exec_cmd(char *cmd, char **env)
{
	char	*path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
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
	free(path);
	free_paths(cmd_args);
	ft_printf("%s%s\n", ERR_EXECVE, cmd);
	exit(EXIT_FAILURE);
}
