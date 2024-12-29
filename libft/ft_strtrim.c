/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:44:01 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/05 18:23:02 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Removes the char in set from the beginning and end of str s1
//s1     --> Str to be trimmed
//set    --> The set of char to trim
//return --> Success (new str)
//return --> Failure (NULL)

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	int			start;
	int			end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup("\0"));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	res = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s1[start], end - start + 2);
	return (res);
}

// #include "ft_strlen.c"
// #include "ft_strchr.c"
// #include "ft_strdup.c"
// #include "ft_strlcpy.c"
// #include "ft_memchr.c"
// #include <stdio.h>
// int	main(int ac, char **av)
// {
// 	if (ac == 3)
// 	{
// 		printf("s1: %s, to trim: %s\n", av[1], av[2]);
// 		printf("result: %s", ft_strtrim(av[1], av[2]));
// 	}
// 	return (0);
// }
