/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:22:39 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/08 19:22:39 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_int(int nbr)
{
	unsigned int	nb;
	int				size;

	size = 0;
	if (nbr < 0)
	{
		nb = -nbr;
		size += ft_print_char('-');
	}
	else
		nb = nbr;
	if (nb >= 10)
	{
		size += ft_print_int(nb / 10);
	}
	size += ft_print_char((nb % 10) + '0');
	return (size);
}

int	ft_print_unsign(unsigned int i)
{
	int	size;

	size = 0;
	if (i >= 10)
		size += ft_print_unsign(i / 10);
	size += ft_print_char((i % 10) + '0');
	return (size);
}
