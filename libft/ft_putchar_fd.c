/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:08:05 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/25 18:13:32 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Outputs the int n to fd
//fd     --> File descriptor in which to write
//c      --> The char to write

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main(int argc, char **argv)
{
	(void)argc;
	ft_putchar_fd(argv[1][0], 1);
	return (0);
}*/