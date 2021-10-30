/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:21:41 by bagovic           #+#    #+#             */
/*   Updated: 2021/10/30 17:12:15 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	g_wildcards[9];

void	ft_initialize_data(void);
void	ft_putunsigned(unsigned long n);
int		ft_printf(const char *format, ...);

#endif