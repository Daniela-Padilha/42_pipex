/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:05:36 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/28 17:45:27 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Moves n bytes from memory area src to memory area dest
//dest   --> Pointer to the destination memory area
//src    --> Pointer to the source memory area
//n      --> Number of bytes to copy
//return --> Success (dest)
//return --> Failure (dest)

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*src_c;
	char		*dest_c;

	if (dest == src)
		return (dest);
	dest_c = (char *)dest;
	src_c = (const char *)src;
	if (src_c < dest_c && src_c + n > dest_c)
	{
		while (n--)
		{
			*(dest_c + n) = *(src_c + n);
		}
	}
	else
	{
		while (n--)
		{
			*dest_c = *src_c;
			dest_c++;
			src_c++;
		}
	}
	return (dest);
}

// #include <string.h>
// #include "ft_strlen.c"

// int	main(int ac, char **av)
// {
// 	void		*d;
// 	const void	*s;

// 	d = av[1];
// 	s = av[2];
// 	(void)ac;
// 	printf("Before ft_memmove, dest: %s, src: %s\n", av[1], av[2]);
// 	printf("Before memmove, dest: %s. src: %s\n", av[1], av[2]);
// 	ft_memmove(d, s, ft_strlen(av[1]));
// 	memmove(d, s, ft_strlen(av[1]));
// 	printf("After ft_memmove, dest: %s, src: %s\n", av[1], av[2]);
// 	printf("After memmove, dest: %s, src: %s", av[1], av[2]);
// 	return (0);
// }
