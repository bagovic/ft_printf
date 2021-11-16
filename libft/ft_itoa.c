/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:43:09 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/13 15:45:49 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_countnum(int n)
{
	int	ncount;

	ncount = 0;
	if (n == 0 || n == -0)
		return (1);
	if (n < 0)
		ncount++;
	while (n != 0)
	{
		n /= 10;
		ncount++;
	}
	return (ncount);
}

char	*ft_itoa(int n)
{
	char	*nstr;
	long	nlong;
	int		ncount;

	nlong = n;
	if (nlong > __INT_MAX__ || nlong < -2147483648)
		return (NULL);
	ncount = ft_countnum(n);
	nstr = malloc(ncount + 1);
	if (nstr == NULL)
		return (NULL);
	nstr[ncount] = '\0';
	if (nlong < 0)
	{
		nstr[0] = '-';
		nlong *= -1;
	}
	if (nlong == 0)
		nstr[ncount - 1] = '0';
	while (nlong != 0)
	{
		nstr[--ncount] = (nlong % 10) + '0';
		nlong /= 10;
	}
	return (nstr);
}
