/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:38:11 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/07 21:38:11 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

// cleans up and frees the children
void	clean_up(pid_t pid, int n_child)
{
	while (n_child >= 0)
	{
		waitpid(pid[n_child], NULL, 0);
		n_child--;
	}
	free(pid);
}

//create a pipe
int	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("PIPE ERROR");
		return (-1);
	}
	return (0);
}

//create a child
pid_t	create_child(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("FORK ERROR");
		return (-1);
	}
	else if (pid == 0)
	{
		printf("I am the child %d\n", getpid());
		exit(EXIT_SUCCESS);
	}
	return (pid);
}

// int main(void)
// {
// 	int i = 0;
// 	int nbr = 4;
// 	pid_t *pid = create_child(nbr);

//     if (!pid)
//         return (1);
// 	while (i < nbr)
// 	{
// 		if (pid[i] > 0)
// 		{
// 			waitpid(pid[i], NULL, 0);
// 			printf("I am the parent of: %i\n", pid[i]);
// 		}
// 		i++;
// 	}
// 	free(pid);
// 	return (0);
// }