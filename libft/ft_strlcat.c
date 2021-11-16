/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:48:18 by bagovic           #+#    #+#             */
/*   Updated: 2021/07/15 21:55:05 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	totallen;
	size_t	dstlen;
	size_t	srclen;
	int		c;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	c = dstlen;
	if ((unsigned long) dstlen >= (unsigned long) dstsize)
		return (dstsize + srclen);
	totallen = dstlen + srclen;
	if ((unsigned long) dstsize - (unsigned long) dstlen > 0)
	{
		while (c - dstlen < dstsize - dstlen - 1 && src[c - dstlen] != '\0')
		{
			dst[c] = src[c - dstlen];
			c++;
		}
		dst[c] = '\0';
	}
	return (totallen);
}
