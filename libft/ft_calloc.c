/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:18:45 by bagovic           #+#    #+#             */
/*   Updated: 2021/07/17 18:43:22 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	c;

	mem = (char *) malloc(size * count);
	if (mem == 0)
		return (NULL);
	c = 0;
	while (c < count * size)
	{
		mem[c] = '\0';
		c++;
	}
	return (mem);
}
