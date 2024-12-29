/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:07:38 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/26 14:09:22 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Outputs the str s to fd
//fd     --> File descriptor in which to write
//s      --> The str to write

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 		ft_putstr_fd(argv[1], 1);
// 	return (0);
// }
