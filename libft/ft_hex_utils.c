/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:52:09 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/08 21:52:09 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_util(unsigned long ptr)
{
	int		size;
	char	*hex;

	hex = "0123456789abcdef";
	size = 0;
	if (ptr >= 16)
		size += ft_ptr_util(ptr / 16);
	size += ft_print_char(hex[ptr % 16]);
	return (size);
}

int	ft_print_ptr(unsigned long ptr)
{
	char	*hex;
	int		size;

	hex = "0123456789abcdef";
	if (!ptr)
		return (ft_print_str("(nil)"));
	write (1, "0x", 2);
	size = 2;
	if (ptr >= 16)
		size += ft_ptr_util(ptr / 16);
	size += ft_print_char(hex[ptr % 16]);
	return (size);
}

//lowercase = 1, uppercase = 0
int	ft_print_hex(unsigned int nbr, int lower)
{
	char	*hex;
	int		size;

	size = 0;
	if (lower == 1)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nbr >= 16)
		size += ft_print_hex(nbr / 16, lower);
	size += ft_print_char(hex[nbr % 16]);
	return (size);
}
