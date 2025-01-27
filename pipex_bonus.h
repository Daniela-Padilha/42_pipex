/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:46 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/22 14:03:46 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		ac;
	char	**av;
	char	**env;
	int		pipe_fd[2];
}	t_pipex;

# define CMD_NOT_FOUND 127

# define ERR_CMD "Error: command not found: "
# define ERR_ARGS "Error: format must be ./pipex infile cmd cmd outfile\n"
# define ERR_ARGS_BONUS "Error: try ./pipex here_doc LIMITER cmd cmd1 file\n"
# define ERR_PIPE "Error: pipe failure\n"
# define ERR_FORK "Error: fork failure\n"
# define ERR_EXECVE "Error: execve failure for: "
# define ERR_MALLOC "Error: malloc failure in "
# define ERR_OPEN_INPUT "Error: unable to open input file: "
# define ERR_OPEN_OUTPUT "Error: unable to open output file: "

void	exec_cmd(char *cmd, char **env);
void	child(char **av, int *pipe_fd, char **env, int cmd_index);
void	parent(int ac, char **av, int *pipe_fd, char **env, int cmd_index);
char	*get_path(char *cmd, char **env);
void	free_paths(char **paths);
void	handle_here_doc(const char *limiter, int *pipe_fd);
void	main_process(int ac, char **av, char **env, int cmd_index);
pid_t	forking(int *pipe_fd);

#endif