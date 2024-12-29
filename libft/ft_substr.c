/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:50:47 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/30 18:33:02 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Returns a substr from the str s
//s      --> Str from which to create the substr
//start  --> The start index of the substr in s
//len    --> The lenght of the substr
//return --> Success (the substr)
//return --> Failure (NULL)

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		s_len;
	size_t		i;

	i = 0;
	s_len = ft_strlen(s);
	if (start > ft_strlen(s))
	{
		start = 0;
		len = 0;
	}
	if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

// int	main()
// {
// 	char const		*s = "Hello Dani!!";
// 	unsigned int 	start = 6;
// 	size_t			len = 4;

// 	printf("string: %s, substring: %s", s, ft_substr(s, start, len));
// 	return (0);
// }