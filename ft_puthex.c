/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoumman <mhoumman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:08:49 by mhoumman          #+#    #+#             */
/*   Updated: 2025/11/25 11:29:06 by mhoumman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	int		count;
	char	*hex;
	char	*uhex;

	count = 0;
	hex = "0123456789abcdef";
	uhex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, c);
	if (c == 'x')
		count += ft_putchar(hex[n % 16]);
	if (c == 'X')
		count += ft_putchar(uhex[n % 16]);
	return (count);
}
