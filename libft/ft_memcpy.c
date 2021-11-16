/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:24:00 by bagovic           #+#    #+#             */
/*   Updated: 2021/07/14 11:29:08 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destpointer;
	const char	*srcpointer;
	size_t		c;

	destpointer = dest;
	srcpointer = src;
	if (srcpointer == NULL && destpointer == NULL)
		return (NULL);
	c = 0;
	while (c < n)
	{
		destpointer[c] = srcpointer[c];
		c++;
	}
	return (destpointer);
}
