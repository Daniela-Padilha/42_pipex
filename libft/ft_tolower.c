/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:11:00 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/26 17:37:50 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Convert a char to lowercase
//c      --> Char to convert
//return --> Char in lowercase

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}
// #include <ctype.h>
// #include <stdio.h>
// int	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		printf("ft_tolower: %i\n", ft_tolower(av[1][0]));
// 		printf("tolower: %i", tolower(av[1][0]));
// 	}
// 	return (0);
// }
