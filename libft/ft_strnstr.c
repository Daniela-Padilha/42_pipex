/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:34:55 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/28 15:25:36 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// info   --> Search for the first occurrence of a substring
// big    --> Pointer to the str to be searched
// little --> Pointer to the str to search in big
// len    --> Maximum lenght of the str to be searched
// return --> Sucess (pointer to the substring)
// return --> Failure (NULL)

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!big && !len)
		return (NULL);
	if (!little[0] || little == big)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] == big[i + j] && (i + j) < len)
		{
			if (!little[j + 1])
				return ((char *)(big + i));
			++j;
		}
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include "ft_strlen.c"
// int	main(int ac, char **av)
// {
// 	if (ac > 2)
// 	{   
//  	printf("ft_strnstr: %i\n", ft_strnstr(av[1], av[2], ft_strlen(av[1])));
// 		printf("strnstr: %i", strnstr(av[1], av[2], ft_strlen(av[1])));
// 	}
// 	return(0);
// }