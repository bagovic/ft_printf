/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:29:20 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/20 15:25:16 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = 0;
	while (s[slen] != '\0')
		slen++;
	while (slen >= 0)
	{
		if (s[slen] == (char) c)
			return ((char *)&s[slen]);
		slen--;
	}
	return (0);
}
