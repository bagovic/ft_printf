/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:31:24 by bagovic           #+#    #+#             */
/*   Updated: 2021/07/14 19:06:09 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sp;
	int					counter;

	sp = s;
	counter = 0;
	while (counter < (int)n)
	{
		if ((unsigned char)sp[counter] == (unsigned char)c)
			return ((void *)&sp[counter]);
		counter++;
	}
	return (NULL);
}
