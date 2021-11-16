/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:45:19 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/21 16:33:52 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1len;

	s1len = ft_strlen(s1);
	s1len++;
	s2 = malloc(s1len);
	if (s2 == NULL)
		return (s2);
	ft_strlcpy(s2, s1, s1len);
	return (s2);
}
