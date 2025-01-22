/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:11 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/22 14:03:11 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

# define ERR_FILE "Error: no such file or directory: "
# define ERR_ALLOW "Error: permission denied: "
# define ERR_CMD "Error: command not found: "
# define ERR_ARGS "Error: Format must be: ./pipex infile cmd cmd outfile"
# define ERR_PIPE "Error: pipe failure"
# define ERR_FORK "Error: fork failure"
# define ERR_EXECVE "Error: execve failure"
# define ERR_MALLOC "Error: malloc failure in "

void	exec_cmd(char *cmd, char **env);
void	child(char **av, int *pipe_fd, char **env);
void	parent(char **av, int *pipe_fd, char **env);
int		open_file(char *file, int child_or_not);
char	*get_path(char *cmd, char **env);
void	free_paths(char **paths);
void	ft_error(char *msg, char *name);

#endif