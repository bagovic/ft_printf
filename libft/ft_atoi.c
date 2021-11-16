/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:12:01 by bagovic           #+#    #+#             */
/*   Updated: 2021/07/15 21:03:05 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_num(const char *nptr, int c, int sign)
{
	int	num;

	num = 0;
	while (nptr[c] != '\0')
	{
		if (nptr[c] < 48 || nptr[c] > 57)
			return (num * sign);
		num = num * 10 + nptr[c] - 48;
		if (sign == 1 && num < 0)
			return (-1);
		else if (sign == -1 && num * sign > 0)
			return (0);
		c++;
	}
	return (num * sign);
}

int	ft_atoi(const char *nptr)
{
	size_t	c;
	int		sign;

	c = 0;
	sign = 1;
	while (nptr[c] != '\0')
	{
		if (nptr[c] == 45 || nptr[c] == 43)
		{
			if (nptr[c + 1] < 48 || nptr[c + 1] > 57)
				return (0);
			if (nptr[c] == 45)
				sign = -1;
		}
		else if (nptr[c] > 47 && nptr[c] < 58)
			break ;
		else if ((nptr[c] < 9 || nptr[c] > 13) && nptr[c] != 32)
			return (0);
		c++;
	}
	return (ft_num(nptr, c, sign));
}
