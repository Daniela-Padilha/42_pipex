/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:28:35 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/27 17:28:35 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Apply the funcion f to each char in s
//s      --> Pointer to the str to iterate
//f      --> Function to apply to each char

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

//#include "ft_toupper.c"
// void	ft_test(unsigned int i, char *str)
// {
//	if (i > 0)
//		*str = ft_toupper(*str);
// }

// int	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		ft_striteri(av[1], ft_test);
// 		printf("After ft_striteri: %s", av[1]);
// 	}
// 	return (0);
// }