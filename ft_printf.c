/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:20:46 by bagovic           #+#    #+#             */
/*   Updated: 2021/10/25 17:57:56 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//cspdiuxX%

// static char	ft_check_wildcard(const char *format)
// {
// 	char	*wildcards;
// 	int		format_i;
// 	int		wc_i;

// 	wildcards = ft_get_wildcards();
// 	format_i = 0;
// 	while (format[format_i] != '\0')
// 	{
// 		if (format[format_i] == '%')
// 		{
// 			format_i++;
// 			wc_i = 0;
// 			while (wc_i < 9)
// 			{
// 				if (format[format_i] == wildcards[wc_i])
// 					return (1);
// 				wc_i++;
// 			}
// 		}
// 		format_i++;
// 	}
// 	return (0);
// }
//cspdiuxX%
static void	ft_printwc(va_list valist, char wc)
{
	char	*p;

	if ((int) wc == '%')
	{
		write (1, &wc, 1);
		return ;
	}
	p = va_arg(valist, char *);
	if ((int) wc == 'c')
		ft_putchar_fd((char) p, 1);
	else if (wc == 's')
		ft_putstr_fd(p, 1);
	// else if (*wc == 'p')
	// {}
	else if ((int) wc == 'd')
		ft_putnbr_fd((int) p, 1);
}

static void	ft_flwc(va_list	valist, char *flwc)
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
			{
				ft_printwc(valist, flwc[i]);
				return ;
			}
			y++;
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	char	*flwc;
	int		i;

	ft_initialize_data();
	i = 0;
	va_start(valist, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			flwc = ft_substr(format, i + 1, ft_strlen(format) - (i + 1));
			ft_flwc(valist, flwc);
			i++;
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(valist);
	return (0);
}

int	main(void)
{
	ft_printf("Hello %% %s", "World!");
	// ft_printf("Hello%d%%%c %s\n", 13134, ',', "World!");
	// // printf("Hello %#s", "world!");
	return (0);
}