/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:49:45 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/31 16:31:17 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Concatenate s1 and s2
//s1     --> The first str
//s2     --> The second str
//return --> Success (new str)
//return --> Failure (NULL)

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*res;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[len_s1] = s2[i];
		len_s1++;
		i++;
	}
	res[len_s1] = '\0';
	return (res);
}

// #include "ft_strlen.c"

// int	main(int ac, char **av)
// {
// 	if (ac == 3)
// 	{
// 		printf("s1: %s, s2: %s\n", av[1], av[2]);
//		printf("result: %s\n", ft_strjoin(av[1], av[2]);
// 	}
// 	return (0);
// }