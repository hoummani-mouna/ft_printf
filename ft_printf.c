/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoumman <mhoumman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 09:21:18 by mhoumman          #+#    #+#             */
/*   Updated: 2025/11/25 12:19:23 by mhoumman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lettre(va_list args, char c, int *count)
{
	if (c == 'c')
		*count += ft_putchar((char) va_arg(args, int));
	else if (c == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		*count += ft_putadd(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		*count += ft_putunbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		*count += ft_puthex(va_arg(args, int), c);
	else if (c == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
			count += ft_putchar(format[i]);
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			lettre(args, format[i], &count);
		}
		i++;
	}
	va_end(args);
	return (count);
}
