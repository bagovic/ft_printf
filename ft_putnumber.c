/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berminagovic <berminagovic@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:10:35 by bagovic           #+#    #+#             */
/*   Updated: 2021/11/16 12:29:52 by berminagovi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	ft_numlen(long long num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num != 0 || len == 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static int	ft_reverse_unsigned_n(long long *n)
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

int	ft_putunsigned(long long n)
{
	int	digit;
	int	nsize;
	int	output_count;

	digit = 0;
	output_count = ft_numlen(n);
	if (n == 0)
		write(1, "0", 1);
	if ((long) n < 0)
		n = 0;
	else if (n > 4294967295)
		n = 4294967295;
	nsize = ft_reverse_unsigned_n(&n);
	while (nsize != 0)
	{
		digit = n % 10 + '0';
		write(1, &digit, 1);
		n /= 10;
		nsize--;
	}
	return (output_count);
}

int	ft_putnumber(long n)
{
	char	*nstr;
	int		output_count;

	nstr = ft_itoa(n);
	output_count = ft_strlen(nstr);
	ft_putstr_fd(nstr, 1);
	free(nstr);
	return (output_count);
}
