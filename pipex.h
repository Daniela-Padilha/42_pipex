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

#  define BUFFER_SIZE = 10

# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

int		pipeline(void);
void	exec_cmd(int n);
int		write_file(int n);
int		read_file(int n);
void	clean_up(pid_t *pid, int n_child);
int		*create_pipe(void);
pid_t	*create_child(void);


#endif