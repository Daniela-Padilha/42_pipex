/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:31:17 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/29 18:04:06 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Duplicates the str s
//s      --> Pointer to the str to duplicate
//return --> Success (Pointer to the duplicated str)
//return --> Failure (NULL)

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	size_t	i;
	char	*dest;

	len_s = ft_strlen(s);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (len_s + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// #include "ft_strlen.c"

// int 	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		char	*dup1 = ft_strdup(av[1]);
// 		char	*dup2 = strdup(av[1]);

// 		printf("ft_strdup: %s\n", dup1);
// 		printf("strdup: %s", dup2);
// 		free (dup1);
// 		free (dup2);
// 	}
// 	return (0);
// }