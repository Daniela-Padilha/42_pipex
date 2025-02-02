/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:54:33 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/02 18:20:45 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info --> prints a error message, completes it if necessary, and exits
//			if if_exit is TRUE(1)

void	errors(char *message, char *complete, int if_exit)
{
	if (complete == NULL)
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
		if (if_exit == 1)
			exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd(complete, 2);
		ft_putstr_fd("\n", 2);
		if (if_exit == 1)
			exit(EXIT_FAILURE);
	}
}
