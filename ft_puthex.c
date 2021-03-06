/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:26:30 by bagovic           #+#    #+#             */
/*   Updated: 2022/01/10 16:34:17 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(int dec)
{
	int	hexlen;

	hexlen = 0;
	while (dec != 0 || hexlen == 0)
	{
		dec /= 16;
		hexlen++;
	}
	if (hexlen > 64)
		return (hexlen + 64);
	return (64);
}

int	ft_putaddress(unsigned long long dec)
{
	char	*hex;
	int		i;
	int		output_count;
	int		temp;

	i = 0;
	hex = ft_calloc(ft_hexlen(dec), sizeof (char *));
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
	free(hex);
	return (output_count);
}

int	ft_puthex(unsigned int dec, int hexcase)
{
	char	*hex;
	int		output_count;
	int		i;
	int		temp;

	i = 0;
	hex = ft_calloc(ft_hexlen(dec), sizeof (char *));
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
	i--;
	while (i >= 0)
		write(1, &hex[i--], 1);
	free(hex);
	return (output_count);
}
