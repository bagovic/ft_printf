/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:32:42 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/21 16:00:16 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		ch;
	size_t		cn;
	const char	*subpointer;

	ch = 0;
	cn = 0;
	subpointer = &haystack[0];
	while ((unsigned long) ch < (unsigned long) len && haystack[ch] != '\0')
	{
		if (haystack[ch] == needle[cn])
		{
			if (cn == 0)
				subpointer = &haystack[ch];
			cn++;
		}
		else if (ft_strlen(needle) != cn)
		{
			ch -= cn;
			cn = 0;
		}
		ch++;
	}
	if (cn >= ft_strlen(needle))
		return ((char *)subpointer);
	return (NULL);
}
