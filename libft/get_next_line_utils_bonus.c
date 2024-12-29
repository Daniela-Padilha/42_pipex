/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:51:02 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/12/07 13:51:02 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*res;

	len_s1 = ft_strlen_until(s1, '\0');
	len_s2 = ft_strlen_until(s2, '\0');
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
		res[len_s1++] = s2[i++];
	res[len_s1] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen_until(s, '\0') + 1));
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	c_c;
	char	*s_c;

	i = 0;
	c_c = (char)c;
	s_c = (char *)s;
	while (i < n)
	{
		if (s_c[i] == c_c)
			return ((void *)&s_c[i]);
		else
			i++;
	}
	return (NULL);
}

size_t	ft_strlen_until(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;
	size_t	i;
	char	*ptr_c;

	if ((nmemb == 0) || (size == 0))
	{
		nmemb = 1;
		size = 0;
	}
	total = (nmemb * size);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ptr_c = (char *)ptr;
	i = 0;
	while (i < total)
	{
		ptr_c[i] = '\0';
		i++;
	}
	ptr = (void *)ptr_c;
	return (ptr);
}
