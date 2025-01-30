/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:37:35 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/30 14:49:56 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Free a 3D array

void	free_matrix(void ***matrix)
{
	int	i;
	int	j;

	i = 0;
	if (!matrix || !*matrix)
		return ;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
			free(matrix[i][j++]);
		free(matrix[i++]);
	}
	free(*matrix);
	return ;
}
