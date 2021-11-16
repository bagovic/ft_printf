/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:06:05 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/20 15:43:26 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1p;
	unsigned char	*s2p;
	int				counter;

	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	counter = 0;
	while ((unsigned long) counter < (unsigned long)n)
	{
		if (s1[counter] != s2[counter])
		{
			if (s1p[counter] > s2p[counter])
				return (1);
			else if (s1p[counter] < s2p[counter])
				return (-1);
		}
		if (s1[counter] == '\0' && s2[counter] != '\0')
			return (-1);
		else if (s1[counter] != '\0' && s2[counter] == '\0')
			return (1);
		else if (s1[counter] == '\0' && s2[counter] == '\0')
			return (0);
		counter++;
	}
	return (0);
}
