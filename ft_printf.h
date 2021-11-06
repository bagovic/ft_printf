/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berminagovic <berminagovic@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:21:41 by bagovic           #+#    #+#             */
/*   Updated: 2021/11/06 09:35:43 by berminagovi      ###   ########.fr       */
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
void	ft_putunsigned(long long n);
int		ft_putnumber(long n);
int		ft_putaddress(unsigned long long dec);
int		ft_puthex(unsigned long long dec, int hexcase);
int		ft_printf(const char *format, ...);

#endif