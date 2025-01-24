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

# define CMD_NOT_FOUND 127

# define ERR_CMD "Error: command not found: "
# define ERR_ARGS "Error: format must be ./pipex infile cmd cmd outfile\n"
# define ERR_PIPE "Error: pipe failure\n"
# define ERR_FORK "Error: fork failure\n"
# define ERR_EXECVE "Error: execve failure for: "
# define ERR_MALLOC "Error: malloc failure in "
# define ERR_OPEN_INPUT "Error: unable to open input file: "
# define ERR_OPEN_OUTPUT "Error: unable to open output file: "
# define ERR_DUP "Error: dup2 failure\n"

void	exec_cmd(char *cmd, char **env);
void	child(char **av, int *pipe_fd, char **env);
void	parent(char **av, int *pipe_fd, char **env);
char	*get_path(char *cmd, char **env);
void	free_paths(char **paths);

#endif