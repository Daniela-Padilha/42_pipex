/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:10:49 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/26 17:36:45 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Convert a char to uppercase
//c      --> Char to convert
//return --> Char in uppercase

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		printf("ft_toupper: %i\n", ft_toupper(av[1][0]));
// 		printf("toupper: %i", toupper(av[1][0]));
// 	}
// 	return (0);
// }
