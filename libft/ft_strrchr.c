/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:52:39 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/02 16:32:43 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Search for the last occurence of a char
//s      --> Pointer to the str to be searched
//c      --> Char to search for
//return --> Success (pointer to the last occurence of c)
//return --> Failure (NULL)

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch_c;

	i = 0;
	ch_c = (char)c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] != ch_c)
			i--;
		else
			return ((char *)&s[i]);
	}
	return (NULL);
}

// #include <string.h>

// int	main(void)
// {
// 	const char	*s = "Drosophila melanogaster";
// 	char		ch = 'm';

// 	printf("ft_strrchr: %s\n", ft_strrchr(s, ch));
// 	printf("strrchr: %s", strrchr(s, ch));
// 	return (0);
// }
