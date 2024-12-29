/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:28:16 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/10/31 16:44:42 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Transform an int into a str
//n      --> Int to convert
//return --> Success (New str)
//return --> Failure (NULL)

static size_t	ft_int_counter(int n);
static size_t	ft_is_neg(int n);
static char		*ft_reverse(char *s);
static int		ft_convertneg(int n);

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = ft_is_neg(n);
	len = ft_int_counter(n) + neg + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	i = 0;
	n = ft_convertneg(n);
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[i++] = '-';
	if (i == 0)
		str[i++] = '0';
	str[i] = '\0';
	return (ft_reverse(str));
}

//populates the str from the end
static char	*ft_reverse(char *s)
{
	char	tmp;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(s);
	j = len - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		j--;
		i++;
	}
	return (s);
}

//count how many digits are in the int n
static size_t	ft_int_counter(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

//checks if int is negative or not
static size_t	ft_is_neg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int	ft_convertneg(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

// #include "ft_strlen.c"
// #include "ft_strdup.c"
// #include <stdio.h>
// int	main(void)
// {
// 	printf("n = -123, ft_itoa: %s\n", ft_itoa(-123));
// 	printf("n = 0, ft_itoa: %s\n", ft_itoa(0));
// 	printf("n = 456789, ft_itoa: %s\n", ft_itoa(456789));
// 	printf("n = -2147483648, ft_itoa: %s\n", ft_itoa(-2147483648));
// 	printf("n = 2147483647, ft_itoa: %s\n", ft_itoa(2147483647));
// 	return (0);
// }