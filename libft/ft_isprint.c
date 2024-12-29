/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:00:37 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/26 17:02:18 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//info   --> Check if char is printable
//c      --> Char to check
//return --> Success (1)
//return --> Failure (0)

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// //to teste non printable: ./a.out $(printf '\0')

// int     main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		printf("ft_isprint: %i\n", ft_isprint(av[1][0]));
// 		printf("isprint: %i", isprint(av[1][0]));
// 	}
// 	return (0);
// }
