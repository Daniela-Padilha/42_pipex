/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:01:36 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/02 16:21:35 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Show the lenght of the str
//s      --> Pointer to the str
//return --> Success (lenght)

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include <string.h>

//  int     main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		printf("ft_strlen: %zu\n", ft_strlen(av[1]));
// 		printf("strlen: %zu", strlen(av[1]));
// 	}
//     return (0);
// }