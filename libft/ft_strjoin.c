/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:12:10 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/19 15:27:36 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	s1len;
	size_t	s2len;
	size_t	count;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joinstr = malloc(s1len + s2len + 1);
	if (joinstr == NULL)
		return (NULL);
	count = 0;
	while (count < s1len)
	{
		joinstr[count] = s1[count];
		count++;
	}
	while (count - s1len < s2len)
	{
		joinstr[count] = s2[count - s1len];
		count++;
	}
	joinstr[count] = '\0';
	return (joinstr);
}
