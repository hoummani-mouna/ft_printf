/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoumman <mhoumman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:47:18 by mhoumman          #+#    #+#             */
/*   Updated: 2025/11/25 12:12:24 by mhoumman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putahex(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_putahex(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_putadd(void *p)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	ptr = (unsigned long) p;
	count += write(1, "0x", 2);
	count += ft_putahex(ptr);
	return (count);
}
