/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:01:21 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/02 16:29:37 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// info   --> Set the first n bytes of the memory area to c
// s      --> Pointer to the memory area
// c      --> Value to be set
// n      --> Number of bytes to be set
// return --> Success (s)

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr_c;

	i = 0;
	ptr_c = (char *)s;
	while (i < n)
	{
		ptr_c[i] = c;
		i++;
	}
	return (s);
}

// #include <string.h>
// #include <stdio.h>
// int     main(int ac, char **av)
// {
// 	void	*p;
// 	size_t	n = 2;

// 	p = av[1];
// 	if (ac > 2)
// 	{
// 		printf("Before ft_memset: %s\n", av[1]);
// 		printf("Before memset: %s\n", av[1]);
// 		ft_memset(p, av[2][0], n);
// 		memset(p, av[2][0], n);
// 		printf("After ft_memset: %s\n", av[1]);
// 		printf("After memset: %s", av[1]);
// 	}
//     return (0);
// }
