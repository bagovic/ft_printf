/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:52:17 by bagovic           #+#    #+#             */
/*   Updated: 2021/07/07 14:34:15 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*str_counter;
	size_t	counter;

	str_counter = s;
	counter = 0;
	while (counter < n)
	{
		str_counter[counter] = '\0';
		counter++;
	}
}
