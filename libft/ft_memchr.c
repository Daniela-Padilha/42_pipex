/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:06:06 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/31 16:41:05 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Locate the first occurrence of c in s
//s      --> Pointer to the memory area to search
//c      --> Char to search
//n      --> Number of bytes to search
//return --> Success (Pointer to the matching byte)
//return --> Failure (NULL)

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	c_c;
	char	*s_c;

	i = 0;
	c_c = (char)c;
	s_c = (char *)s;
	while (i < n)
	{
		if (s_c[i] == c_c)
			return ((void *)&s_c[i]);
		else
			i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// #include "ft_strlen.c"

// int	main(void)
// {
// 	const char	*str = "Drosophila melanogaster";
// 	char	ch = 'm';
// 	size_t	i = ft_strlen(str);

// 	printf("ft_memchr: %s\n", (char *)ft_memchr(str, ch, i));
// 	printf("memchr: %s", (char *)memchr(str, ch, i));
// 	return (0);
// }
