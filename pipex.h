/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:54 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/12/27 17:07:54 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

void	exec_cmd(char *cmd, char **env);
void	child(char **av, int *pipe_fd, char **env);
void	parent(char **av, int *pipe_fd, char **env);
int		open_file(char *file, int child_or_not);
char	*get_path(char *cmd, char **env);
void	free_paths(char **paths);

#endif