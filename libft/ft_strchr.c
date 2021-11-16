/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:58:25 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/20 15:21:28 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pointer;
	int		counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] == (char) c)
			break ;
		counter++;
	}
	if (s[counter] == (char) c)
	{
		pointer = (char *)&s[counter];
		return (pointer);
	}
	return (NULL);
}
