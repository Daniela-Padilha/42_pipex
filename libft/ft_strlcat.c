/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:10:35 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/28 18:29:02 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Concatenate n bytes from src to dst
//dst    --> Pointer to the destination str
//src    --> Pointer to the source str
//size   --> Number of bytes to concatenate
//return --> Success (number of bytes written)

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i] != '\0')
		i++;
	while ((i + j + 1) < size && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*#include <string.h>
#include "ft_strlen.c"
int	main(int ac, char **av)
{
	if (ac > 2)
	{
		printf("Before ft_strlcat: %s\n", av[1]);
		printf("Before strlcat: %s\n", av[1]);
		ft_strlcat(av[1], av[2], ft_strlen(av[2]));
		strlcat(av[1], av[2], ft_strlen(av[2]));
		printf("After ft_strlcat: %s\n", av[1]);
		printf("After strlcat: %s", av[1]);
	}
	return (0);
}*/
