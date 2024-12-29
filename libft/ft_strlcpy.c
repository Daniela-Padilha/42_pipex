/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:10:21 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/28 18:17:08 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Copy n bytes from src to dst
//dst    --> Pointer to the destination string
//src    --> Pointer to the source string
//size   --> Number of bytes to copy
//return --> Success (number of bytes copied)

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <string.h>
// #include <stdio.h>
// #include "ft_strlen.c"

// int	main(int ac, char **av)
// {
// 	if (ac > 2)
//	{
//		printf("Before ft_strlcpy: %s\n", av[1]);
// 		printf("Before strlcpy: %s\n", av[1]);
// 		ft_strlcpy(av[1], av[2], ft_strlen(av[2]));
// 		strlcpy(av[1], av[2], ft_strlen(av[2]));
// 		printf("After ft_strlcpy: %s\n", av[1]);
// 		printf("After strlcpy: %s", av[1]);
//	}
// 	return (0);
// }
