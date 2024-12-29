/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:06:20 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/30 17:48:56 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Compare the first n bytes of s1 and s2
//s1     --> Pointer to the first memory area
//s2     --> Pointer to the second memory area
//n      --> Number of bytes to compare
//return --> Success (Difference between both str)

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (c_s1[i] != c_s2[i])
			return (c_s1[i] - c_s2[i]);
		i++;
	}
	return (0);
}

// #include <string.h>
// #include "ft_strlen.c"

// int	main(int ac, char **av)
// {
// 	const void    *s1;
//  const void    *s2;
//
//	s1 = av[1];
//	s2 = av[2];
//	if (av > 2)
//	{
//		printf("ft_memcmp: %i\n", ft_memcmp(s1, s2, ft_strlen(s1)));
// 		printf("memcmp: %i", memcmp(s1, s2, ft_strlen(s1)));
//	}
// 	return(0);
// }
