/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:25 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/26 17:24:10 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Check it char is alphanumeric
//c      --> Char to check
//return --> Success (1)
//return --> Failure (0)

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// #include "ft_isalpha.c"
// #include "ft_isdigit.c"
// int 	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		printf("ft_isalnum: %i\n", ft_isalnum(av[1][0]));
// 		printf("isalnum: %i", isalnum(av[1][0]));
// 	}
// 	return (0);
// }
