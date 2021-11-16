/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:11:06 by bagovic           #+#    #+#             */
/*   Updated: 2021/07/15 15:04:40 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1p;
	const unsigned char	*s2p;
	int					counter;

	s1p = s1;
	s2p = s2;
	counter = 0;
	while (counter < (int)n)
	{
		if ((unsigned char)s1p[counter] != (unsigned char)s2p[counter])
			return (s1p[counter] - s2p[counter]);
		counter++;
	}
	return (0);
}
