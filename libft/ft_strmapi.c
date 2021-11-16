/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:17:59 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/19 15:33:35 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strmapi;
	unsigned int	count;

	if (s == NULL)
		return (NULL);
	strmapi = malloc(ft_strlen(s) + 1);
	if (strmapi == NULL)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		strmapi[count] = (*f)(count, s[count]);
		count++;
	}
	strmapi[count] = '\0';
	return (strmapi);
}
