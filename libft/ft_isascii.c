/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:00:01 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/26 16:58:37 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//info   --> Check it char is in the ascii table
//c      --> Char to check
//return --> Success (1)
//return --> Failure (0)

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
// 		printf("ft_isascii: %i\n", ft_isascii(av[1][0]));
// 		printf("isascii: %i", isascii(av[1][0]));
// 	}
// 	return (0);
// }
