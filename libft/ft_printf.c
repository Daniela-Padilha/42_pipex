/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:52:19 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/05 21:52:19 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Produce output according to a format
//format  --> Str that specifies how args are converted for output
//return  --> Success (Number of bytes printed, except '\0')

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	va_start(args, format);
	size = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			size += ft_print_args(args, format[i + 1]);
			i++;
		}
		else
			size += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}

int	ft_print_args(va_list args, char letter)
{
	if (letter == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (letter == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (letter == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	if (letter == 'd' || letter == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (letter == 'u')
		return (ft_print_unsign(va_arg(args, unsigned int)));
	if (letter == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (letter == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	if (letter == '%')
		return (ft_print_char('%'));
	return (0);
}
