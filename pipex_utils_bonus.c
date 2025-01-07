/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:41:57 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/12/29 18:41:57 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex_bonus.h"
#include "libft/libft.h"

// cleans up and frees the children
void	clean_up(pid_t *pid, int n_child)
{
	while (n_child >= 0)
	{
		waitpid(pid[n_child], NULL, 0);
		n_child--;
	}
	free(pid);
}

// closes both ends of the pipes and frees the pipes
void	destroy_pipes(int **pipes, int n_pipes)
{
	int	i;

	i = 0;
	while (i < n_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

//creates how many pipes as i want
int	**create_pipes(int n_pipes)
{
	int		**pipes;
	int		i;

	pipes = calloc(n_pipes, sizeof(int *));
	if (!pipes)
		return (perror("MEM ALLOCATION FAILED"), NULL);
	i = 0;
	while (i++ < n_pipes)
	{
		pipes[i] = calloc(2, sizeof(int));
		if (!pipes[i])
		{
			while(i-- >= 0)
				free(pipes[i]);
			return (perror("MEM ALLOCATION FAILED"), free(pipes), NULL);
		}
		if (pipe(pipes[i]) == -1)
		{
			destroy_pipes(pipes, i - 1);
			return (perror("PIPE ERROR"), NULL);
		}
	}
	return (pipes);
}

//creates how many children as i want
pid_t	*create_children(int n_child)
{
	pid_t	*pid;
	int		i;

	pid = calloc(n_child, sizeof(pid_t));
	if (!pid)
		return (perror("MEM ALLOCATION FAILED"), NULL);
	i = 0;
	while (i++ < n_child)
	{
		pid[i] = fork();
		if (pid[i] == -1)
		{
			clean_up(pid, i - 1);
			return (perror("FORK ERROR"), NULL);
		}
		else if (pid[i] == 0)
		{
			printf("I am the child %d\n", getpid());
			exit(0);
		}
	}
	return (pid);
}
