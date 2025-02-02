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
#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		ac;
	char	**av;
	char	**env;
	int		cmd_index;
	int		pipe_fd[2];
	pid_t	pid;
	int		final_output_fd;
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

void	child(t_pipex *pipex);
void	parent(t_pipex *pipex);
void	handle_here_doc(t_pipex *pipex);
void	main_process(t_pipex *pipex);
void	exec_cmd(char *cmd, char **env, int *pipe_fd, int i);
char	*get_path(char *cmd, char **env, int i);
pid_t	forking(t_pipex *pipex);
void	init_pipex(t_pipex *pipex, int ac, char **av, char **env);
void	open_file(t_pipex *pipex);

#endif