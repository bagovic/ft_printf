/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:43:25 by bagovic           #+#    #+#             */
/*   Updated: 2021/10/30 13:08:57 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_data(void)
{
	g_wildcards[0] = 'c';
	g_wildcards[1] = 's';
	g_wildcards[2] = 'p';
	g_wildcards[3] = 'd';
	g_wildcards[4] = 'i';
	g_wildcards[5] = 'u';
	g_wildcards[6] = 'x';
	g_wildcards[7] = 'X';
	g_wildcards[8] = '%';
}