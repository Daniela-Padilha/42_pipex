/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:00:19 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/26 16:53:58 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//info   --> Check it char is a digit
//c      --> Char to check
//return --> Success (1)
//return --> Failure (0)

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int 	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		printf("ft_isdigit: %i\n", ft_isdigit(av[1][0]));
// 		printf("isdigit: %i", isdigit(av[1][0]));
// 	}
// 	return (0);
// }
