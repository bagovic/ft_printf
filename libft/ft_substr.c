/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:09:20 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/22 11:15:11 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		subcount;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		substr = malloc(ft_strlen(s));
	else
		substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	subcount = 0;
	while (subcount < (int)len && start < ft_strlen(s))
	{
		substr[subcount] = s[start];
		subcount++;
		start++;
	}
	substr[subcount] = '\0';
	return (substr);
}
