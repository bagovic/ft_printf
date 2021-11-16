/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:52:59 by bagovic           #+#    #+#             */
/*   Updated: 2021/07/14 12:11:56 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destpointer;
	const char	*srcpointer;
	size_t		c;

	destpointer = dest;
	srcpointer = src;
	c = 0;
	if (destpointer == NULL && srcpointer == NULL)
		return (NULL);
	if (destpointer > srcpointer)
	{
		while ((int)--n > -1)
		{
			destpointer[n] = srcpointer[n];
		}
	}
	else
	{
		while (c < n)
		{
			destpointer[c] = srcpointer[c];
			c++;
		}
	}
	return (destpointer);
}
