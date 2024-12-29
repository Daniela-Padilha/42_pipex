/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:07:01 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/30 16:48:50 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Outputs the int n to fd
//fd     --> File descriptor in which to write
//n      --> The int to write

void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 		ft_putnbr_fd(argv[1], 1);
// 	return (0);
// }
