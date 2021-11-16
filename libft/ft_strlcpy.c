/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:09:05 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/20 11:33:36 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_size;
	size_t	c;

	c = 0;
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (size > 0)
	{
		while (c < size - 1 && src[c] != '\0')
		{
			dest[c] = src[c];
			c++;
		}
		dest[c] = '\0';
	}
	return (src_size);
}
