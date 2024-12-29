/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:00:54 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/28 16:17:16 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Copies n bytes from the memory area src to memory area dest
//dest   --> Pointer to the destination memory area
//src    --> Pointer to the source memory area
//n      --> Number of bytes to copy
//return --> Success (dest)
//return --> Failure (NULL)

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src_c;
	char		*dest_c;

	i = 0;
	dest_c = (char *)dest;
	src_c = (const char *)src;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
int     main(void)
{
	void		*p;
	void		*pr;
	const void	*src;
	char		*x = "Hello";
	char		*y = "Hello";
	char		*end = "world";

	p = &x;
	pr = &y;
	src = &end;
	printf("Before ft_memcpy: %s\n", x);
	printf("Before memcpy: %s\n", y);
	ft_memcpy(p, src, size_of(src));
	memcpy(pr, src, sizeof(src));
	printf("After ft_memcpy: %s\n", x);
	printf("After memcpy: %s", y);
    return (0);
}
*/
