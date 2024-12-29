/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:07:18 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/26 14:23:03 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Outputs the str s to fd with a \n
//f      --> File descriptor in which to write
//s      --> The str to write

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	ft_putendl_fd(argv[1], 1);
// 	return (0);
// }
