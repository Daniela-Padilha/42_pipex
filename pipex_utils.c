/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:52:51 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/08 17:52:53 by ddo-carm         ###   ########.fr       */
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
		fd = open(file, O_RDONLY, 0777);
	if (child_or_not > 0)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(0);
	return (fd);
}

//info       --> Get the environment variable
//name       --> What to search for
//env        --> All environmental variables
//return     --> The environment variable or NULL if it doesn't find it

char	*get_env(char *name, char **env)
{
	char *sub;
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && anv[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

//info       --> Free the strings inside an array one by one
//subs       --> Array of strs to be freed 

void	free_subs(char **subs)
{
	int	i;

	i = 0;
	while(subs[i])
	{
		free(subs[i]);
		i++
	}
	free(subs);
}

//info        --> Get path for the cmd
//cmd         --> Comand to be executed
//env         --> All environmental variables
//beginning   --> Isolates only the env PATH and splits it into strs with the
//                beginning of the path for the cmd
//middle_path --> Adds the "/" to make the middle part of a path
//cmd_args    --> Array of the args of the command
//exec        --> Adds the cmd to the path, completing the executable path
//return      --> The path to the cmd

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**beginning;
	char	*middle_path;
	char	**cmd_args;
	char	*exec;
	
	i = 0;
	beginning = fr_split(get_env("PATH", env), ':');
	cmd_args = ft_split(cmd, " ");
	while (beginning[i])
	{
		middle_path = ft_strjoin(beginning, '/');
		exec = ft_strjoin(middle_path, cmd_args[0]);
		free(middle_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_subs(beginning);
			free_subs(cmd_args);
			return (exec);
		}
		free(exec);
	}
	free_subs(beginning);
	free_subs(cmd_args);
	return (cmd);
}
