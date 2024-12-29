/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:28:23 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/30 18:34:20 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Apply f function to each char in s
//s      --> Pointer to the string to iterate
//f      --> Function to aplly to each char
//return --> Success (New str created)
//return --> Failure (NULL)

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mod_s;
	size_t	s_len;
	int		i;

	s_len = ft_strlen(s);
	i = 0;
	mod_s = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!mod_s)
		return (NULL);
	while (s[i])
	{
		mod_s[i] = f(i, s[i]);
		i++;
	}
	mod_s[i] = '\0';
	return (mod_s);
}

//#include "ft_toupper.c"
//#include "ft_strlen.c"
// char	ft_test(unsigned int i, char c)
// {
//	if (i > 0)
//		c = ft_toupper(c);
//	return (c);
// }

// int	main(int ac, char **av)
// {
//	char	*res;
//	if (ac > 1)
//		res = ft_strmapi(av[1], ft_test);
// 	if (res != NULL)
// 	{
// 		printf("After ft_strmapi: %s\n", res);
//		free(res);
// 	}
//	else
//		printf("string as argument nedeed.\n");
// 	return (0);
// }