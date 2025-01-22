/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:29 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/22 18:00:06 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

//info           --> Open file with specific flags depending on the process 
//					 that we are in
//file           --> Str with the name of the file
//child_or_not   --> Checks if we are in the child process
//return         --> Fd of the file openned, or -1 if error

int	open_file(char *file, int child_or_not)
{
	int	fd;

	if (child_or_not == 0)
		fd = open(file, O_RDONLY, 0111);
	if (child_or_not > 0)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_error(ERR_FILE, file), -1);
	return (fd);
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
	while (ft_strnstr(env[i], "PATH=", 5) == NULL)
		i++;
	paths = ft_split(ft_strtrim(env[i], "PATH="), ':');
	if (!paths)
		return (ft_error(ERR_MALLOC, "ft_split in get_path"), NULL);
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
	write(1, "Error: command not found: \n", 27);
	return (free_paths(paths), NULL);
}

//info     --> Execute a comand
//cmd      --> Comand to be executed
//env      --> All environmental variables
//path     --> Path to the command
//cmd_args --> Array of the args of the command

void	exec_cmd(char *cmd, char **env)
{
	ft_printf("%s\n", ERR_CMD);
	char	*path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		ft_error(ERR_CMD, cmd);
	path = get_path(cmd_args[0], env);
	if (!path)
	{
		free_paths(cmd_args);
		return ;
	}
	if (execve(path, cmd_args, env) == -1)
	{
		free(path);
		free_paths(cmd_args);
		ft_printf("%s\n", ERR_EXECVE);
	}
	free(path);
	free_paths(cmd_args);
}
