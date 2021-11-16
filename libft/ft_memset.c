/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:33:37 by bagovic           #+#    #+#             */
/*   Updated: 2021/07/07 14:56:19 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char			*c_pointer;
	unsigned char	cc;
	size_t			counter;

	c_pointer = (char *)b;
	cc = c;
	counter = 0;
	while (counter < len)
	{
		c_pointer[counter] = cc;
		counter++;
	}
	return (c_pointer);
}
