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


#include "pipex.h"
#include "libft/libft.h"

// void	create_pipe(int nbr)
// {
// 	int	pipefd[2][nbr];

// 	while (nbr > 0)
// 	{
// 		if (pipe(pipefd) == -1)
// 			return (perror("PIPE ERROR", 1));
// 		nbr--;
// 	}
// 	return ;
// }

pid_t	*create_child(int nbr)
{
	pid_t	*pid;
	int		i;

	pid = calloc(nbr, sizeof(pid_t));
	if (!pid)
		return (perror("MEM ALLOCATION FAILED"), NULL);
	i = 0;
	while (i < nbr)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (perror("FORK ERROR"), free(pid), NULL);
		else if (pid[i] == 0)
		{
			printf("I am the child %d\n", getpid());
			exit(0);
		}
		i++;
	}
	return (pid);
}

int main(void)
{
	int i = 0;
	int nbr = 4;
	pid_t *pid = create_child(i);

    if (!pid)
        return 1;
	while (i < nbr)
	{
		printf("I am the parent: %i\n", pid[i]);
		i++;
		waitpid(pid[i], NULL, 0);
	}
	free(pid);
	return (0);
}