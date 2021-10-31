/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:26:30 by bagovic           #+#    #+#             */
/*   Updated: 2021/10/31 16:29:22 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(long dec, int hexcase)
{
	char	hex[99];
	int		i;
	int		output_count;
	int		temp;

	i = 0;
	while (dec != 0)
	{
		temp = dec % 16;
		if (temp < 10)
			hex[i] = temp + 48;
		else if (temp >= 10)
			hex[i] = temp + hexcase;
		dec /= 16;
		i++;
	}
	output_count = i + 2;
	ft_putstr_fd("0x", 1);
	while (--i >= 0)
		write(1, &hex[i], 1);
	return (output_count);
}
