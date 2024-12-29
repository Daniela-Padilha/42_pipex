/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:48:31 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/05 15:29:16 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Search for the first occurence of a char
//s      --> Pointer to the str to be searched
//c      --> Char to search for
//return --> Success (pointer to the first occurence of c)

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

// #include <string.h>
// #include "ft_memchr.c"
// #include "ft_strlen.c"

// int	main(void)
// {
// 	const char	*s = "Drosophila melanogaster";
// 	char		c = 'm';

// 	printf("ft_strchr: %s\n", ft_strchr(s, c));
// 	printf("strchr: %s", strchr(s, c));
// 	return (0);
// }
