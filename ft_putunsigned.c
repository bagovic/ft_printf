/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:10:35 by bagovic           #+#    #+#             */
/*   Updated: 2021/10/31 11:01:26 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	ft_reverse_n(long long *n)
{
	long long	n_reversed;
	int			n_size;

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

void	ft_putunsigned(long long n)
{
	int	digit;
	int	nsize;

	digit = 0;
	if (n == 0)
		write(1, "0", 1);
	if (n < 0)
		n = 0;
	else if (n > 4294967295)
		n = 4294967295;
	nsize = ft_reverse_n(&n);
	while (nsize != 0)
	{
		digit = n % 10 + '0';
		write(1, &digit, 1);
		n /= 10;
		nsize--;
	}
}
