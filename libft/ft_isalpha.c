/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:42 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/26 16:55:20 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//info   --> Check if char is alphabetic
//c      --> Char to check
//return --> Success (1)
//return --> Failure (0)

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int     main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		printf("ft_isalpha: %i\n", ft_isalpha(av[1][0]));
// 		printf("isalpha: %i", isalpha(av[1][0]));
// 	}
// 	return (0);
// }
