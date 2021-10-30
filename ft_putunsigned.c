/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:10:35 by bagovic           #+#    #+#             */
/*   Updated: 2021/10/30 17:14:11 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	ft_reverse_n(long *n)
{
	long	n_reversed;
	int		n_size;

	n_reversed = 0;
	n_size = 0;
	if (*n == 0)
		return (0);
	while (*n != 0)
	{
		n_reversed = n_reversed * 10 + *n % 10;
		*n /= 10;
		n_size++;
	}
	*n = n_reversed;
	return (n_size);
}

void	ft_putunsigned(unsigned long n)
{
	long	nlong;
	int		digit;
	int		nsize;

	nlong = n;
	digit = 0;
	if (nlong == 0)
		write(1, "0", 1);
	if (nlong > __INT_MAX__ || nlong < -2147483648)
		nlong = 0;
	nsize = ft_reverse_n(&nlong);
	while (nsize != 0)
	{
		digit = nlong % 10 + '0';
		write(1, &digit, 1);
		nlong /= 10;
		nsize--;
	}
}
