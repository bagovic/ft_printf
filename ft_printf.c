/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:20:46 by bagovic           #+#    #+#             */
/*   Updated: 2022/01/08 10:10:59 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printnbrs(char wc, char *p)
{
	if (wc == 'p')
		return (ft_putaddress((long long) p));
	else if ((int) wc == 'd')
		return (ft_putnumber((long) p));
	else if (wc == 'i')
		return (ft_putnumber((int)(long) p));
	else if (wc == 'u')
		return (ft_putunsigned((unsigned int)(long) p));
	else if (wc == 'x')
		return (ft_puthex((long long) p, 87));
	else if (wc == 'X')
		return (ft_puthex((long long) p, 55));
	return (0);
}

static int	ft_printwc(va_list valist, char wc)
{
	char	*p;

	if (wc == '%')
	{
		write (1, &wc, 1);
		return (1);
	}
	p = va_arg(valist, char *);
	if ((int) wc == 'c')
	{
		ft_putchar_fd((int)(long)p, 1);
		return (1);
	}
	else if (wc == 's')
	{
		if (p == NULL)
			p = "(null)";
		ft_putstr_fd(p, 1);
		return (ft_strlen(p));
	}
	else
		return (ft_printnbrs(wc, p));
	return (0);
}

static int	ft_flwc(va_list	valist, char *flwc)
{
	int	i;
	int	y;

	i = 0;
	while (flwc[i] != '\0')
	{
		y = 0;
		while (y < 9)
		{
			if (flwc[i] == g_wildcards[y])
				return (ft_printwc(valist, flwc[i]));
			else if (flwc[i] == '\n')
			{
				write(1, "\n", 1);
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}

static int	ft_writeout(const char *format, va_list valist)
{
	char	*flwc;
	int		i;
	int		output_count;

	i = 0;
	output_count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			flwc = ft_substr(format, i + 1, ft_strlen(format) - (i + 1));
			output_count += ft_flwc(valist, flwc);
			free(flwc);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			output_count++;
		}
		i++;
	}
	return (output_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	int		output_count;

	ft_initialize_data();
	output_count = 0;
	va_start(valist, format);
	output_count = ft_writeout(format, valist);
	va_end(valist);
	return (output_count);
}
