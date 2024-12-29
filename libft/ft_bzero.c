/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:58:47 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/02 16:25:47 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info --> Set the first n bytes of the memory to 0
//s    --> Pointer to the memory area
//n    --> Number of bytes to set to 0

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_c;

	i = 0;
	s_c = (char *)s;
	while (i < n)
	{
		s_c[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// #include <strings.h>
// int	main(int argc, char **argv)
// {
// 	void	*p;
// 	size_t	n = 2;

// 	p = &argv[1];
// 	if (argc > 1)
// 	{
// 		printf("Before ft_bzero: %s\n", argv[1]);
// 		printf("Before bzero: %s\n", argv[1]);
// 		ft_bzero(p, n);
// 		bzero(p, n);
// 		printf("After ft_bzero: %s\n", argv[1]);
// 		printf("After bzero: %s", argv[1]);
// 	}
// 	return (0);
// }
