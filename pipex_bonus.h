/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:42:27 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/07 21:42:27 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

#  define BUFFER_SIZE = 10

# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

int		pipeline(void);
void	exec_cmd(int n);
int		write_file(int n);
int		read_file(int n);
void	clean_up(pid_t *pid, int n_child);
void 	destroy_pipes(int **pipes, int n_pipes);
int		**create_pipes(int n_pipes);
pid_t	*create_children(int n_child);


#endif