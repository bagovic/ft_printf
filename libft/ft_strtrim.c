/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:24:37 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/23 18:21:59 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*frontpointer;
	char	*backpointer;
	int		strlen;

	if (s1 == NULL || set == NULL)
		return (NULL);
	frontpointer = (char *)s1;
	while (*frontpointer && ft_strchr(set, *frontpointer))
		frontpointer++;
	strlen = ft_strlen(frontpointer);
	backpointer = frontpointer + strlen;
	while (strlen && ft_strchr(set, *backpointer))
		backpointer = frontpointer + --strlen;
	return (ft_substr(frontpointer, 0, strlen + 1));
}
