/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:29:24 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/11 16:10:14 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Split str s by the delimiter c
//s      --> Str to be split
//c      --> Delimiter char
//return --> Success (new array of str)
//return --> Failure (NULL)

static void		*ft_free_mem(char **new_s, size_t word);
static char		**ft_createsubs(char **new_s, char const *s, char c,
					size_t n_words);
static size_t	ft_count_words(char const *str, char c);
static size_t	ft_lensubs(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	char	**new_s;

	if (!s)
		return (NULL);
	n_words = ft_count_words(s, c);
	new_s = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!new_s)
		return (NULL);
	if (n_words > 0)
		new_s = ft_createsubs(new_s, s, c, n_words);
	new_s[n_words] = NULL;
	return (new_s);
}

static void	*ft_free_mem(char **new_s, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free (new_s[i]);
		i++;
	}
	return ((void *)new_s);
}

static char	**ft_createsubs(char **new_s, char const *s, char c, size_t n_words)
{
	size_t	i;
	size_t	j;
	size_t	word;
	size_t	len;

	i = 0;
	word = 0;
	while (word < n_words)
	{
		while (s[i] == c)
			i++;
		len = ft_lensubs(&s[i], c);
		new_s[word] = (char *)malloc(sizeof(char) * (len + 1));
		if (!new_s[word])
			return ((char **)ft_free_mem(new_s, word));
		j = 0;
		while (s[i] && s[i] != c)
			new_s[word][j++] = s[i++];
		new_s[word][j] = '\0';
		word++;
	}
	return (new_s);
}

static size_t	ft_count_words(char const *str, char c)
{
	size_t	word;
	size_t	i;
	int		if_word;

	if_word = 0;
	if (!str)
		return (0);
	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && !if_word)
		{
			if_word = 1;
			word++;
		}
		else if (str[i] == c)
			if_word = 0;
		i++;
	}
	return (word);
}

static size_t	ft_lensubs(char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (s[j] == c)
		j++;
	i = 0;
	while (s[j] && s[j] != c)
	{
		j++;
		i++;
	}
	return (i);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	i = 0;
// 	char	*str = "Hello World";
// 	char **dest = NULL;
// 	char	c = ' ';
// 	dest = ft_split(str, c);
// 	while (dest[i])
// 	{
// 		printf("%s\n", dest[i++]);
// 	}
// 	return (0);
// }