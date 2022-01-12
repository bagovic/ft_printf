/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:21:41 by bagovic           #+#    #+#             */
/*   Updated: 2022/01/12 08:12:54 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putunsigned(long long n);
int		ft_putnumber(long n);
int		ft_putaddress(unsigned long long dec);
int		ft_puthex(unsigned int dec, int hexcase);
int		ft_printf(const char *format, ...);

#endif