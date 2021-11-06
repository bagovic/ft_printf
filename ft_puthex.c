/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berminagovic <berminagovic@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:26:30 by bagovic           #+#    #+#             */
/*   Updated: 2021/11/06 08:54:58 by berminagovi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long long dec)
{
	char	hex[99];
	int		i;
	int		output_count;
	int		temp;

	i = 0;
	while (dec != 0 || i == 0)
	{
		temp = dec % 16;
		if (temp < 0)
			temp *= -1;
		if (temp < 10)
			hex[i] = temp + 48;
		else if (temp >= 10)
			hex[i] = temp + 87;
		dec /= 16;
		i++;
	}
	output_count = i + 2;
	ft_putstr_fd("0x", 1);
	while (--i >= 0)
		write(1, &hex[i], 1);
	return (output_count);
}

int	ft_puthex(unsigned long long dec, int hexcase)
{
	char	hex[99];
	int		i;
	int		output_count;
	int		temp;

	i = 0;
	while (dec != 0 || i == 0)
	{
		temp = dec % 16;
		if (temp < 0)
			temp *= -1;
		if (temp < 10)
			hex[i] = temp + 48;
		else if (temp >= 10)
			hex[i] = temp + hexcase;
		dec /= 16;
		i++;
	}
	output_count = i;
	while (--i >= 0)
		write(1, &hex[i], 1);
	return (output_count);
}
