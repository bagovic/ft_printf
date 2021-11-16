/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:44:07 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/19 15:25:12 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static	char	**ft_realloc(char **arr, size_t oldsize, size_t newsize)
{
	char	**arrcpy;

	arrcpy = malloc(oldsize * sizeof (char *));
	ft_memcpy(arrcpy, arr, oldsize * sizeof (char *));
	free(arr);
	arr = malloc(newsize * sizeof (char *));
	ft_memcpy(arr, arrcpy, oldsize * sizeof (char *));
	free(arrcpy);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	start;
	size_t	subs;
	size_t	count;

	start = 0;
	count = -1;
	subs = 1;
	arr = malloc(subs * sizeof (char *));
	if (arr == NULL || s == NULL)
		return (NULL);
	arr[subs - 1] = NULL;
	while (++count <= ft_strlen(s) && s[start] != '\0')
	{
		if (s[start] != c && (s[count] == c || s[count] == '\0'))
		{
			arr = ft_realloc(arr, subs, subs + 1);
			arr[subs - 1] = ft_substr(s, start, count - start);
			arr[++subs - 1] = NULL;
			start = count;
		}
		else if (s[count] != c && s[start] == c)
			start = count;
	}
	return (arr);
}
