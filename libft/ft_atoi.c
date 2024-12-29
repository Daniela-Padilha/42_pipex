/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:51:22 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/02 16:22:09 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Convert a str to an int
//nptr    --> String to convert
//return --> Success (int)
//return --> Failure (0)

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	return (nbr * neg);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include "ft_isdigit.c"

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		printf("atoi: %i\n", atoi(argv[1]));
// 		printf("ft_atoi: %i", ft_atoi(argv[1]));
// 	}
// 	return (0);
// }
