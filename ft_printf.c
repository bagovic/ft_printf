/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berminagovic <berminagovic@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:20:46 by bagovic           #+#    #+#             */
/*   Updated: 2021/11/02 15:07:58 by berminagovi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_puthex(unsigned long long dec, int hexcase)
// {
// 	char	hex[99];
// 	int		i;
// 	int		output_count;
// 	int		temp;

// 	i = 0;
// 	while (dec != 0 || i == 0)
// 	{
// 		temp = dec % 16;
// 		if (temp < 0)
// 			temp *= -1;
// 		if (temp < 10)
// 			hex[i] = temp + 48;
// 		else if (temp >= 10)
// 			hex[i] = temp + hexcase;
// 		dec /= 16;
// 		i++;
// 	}
// 	output_count = i + 2;
// 	ft_putstr_fd("0x", 1);
// 	while (--i >= 0)
// 		write(1, &hex[i], 1);
// 	return (output_count);
// }

static int	ft_numlen(long long num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num != 0 || len == 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

//pxX
static int	ft_printwc(va_list valist, char wc)
{
	char	*p;

	if ((int) wc == '%')
	{
		write (1, &wc, 1);
		return (1);
	}
	p = va_arg(valist, char *);
	if ((int) wc == 'c')
	{
		write(1, p, 1);
		return (1);
	}
	else if (wc == 's')
	{
		if (p == NULL)
			p = "(null)";
		ft_putstr_fd(p, 1);
		return (ft_strlen(p));
	}
	else if (wc == 'p')
		return (ft_puthex((long long) p, 87));
	else if ((int) wc == 'd')
	{
		ft_putnbr_fd((long) p, 1);
		return (ft_numlen((long) p));
	}
	else if (wc == 'i')
	{
		ft_putnbr_fd((int) ft_atoi(p), 1);
		return (ft_numlen((int) ft_atoi(p)));
	}
	else if (wc == 'u')
	{
		ft_putunsigned((unsigned int)(long) p);
		return (ft_numlen((unsigned int)(long) p));
	}
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
			y++;
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	char	*flwc;
	int		output_count;
	int		i;

	ft_initialize_data();
	output_count = 0;
	i = 0;
	va_start(valist, format);
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
	va_end(valist);
	return (output_count);
}

// int	main(void)
// {
// 	ft_printf("ULONG_MAX: %p ULONG_MIN: %p \n", (__LONG_MAX__ *2UL+1UL), -(__LONG_MAX__ *2UL+1UL));
// 	printf("ULONG_MAX: %p ULONG_MIN: %p", (__LONG_MAX__ *2UL+1UL), -(__LONG_MAX__ *2UL+1UL));
// 	// ft_printf("0: %p\n", 0);
// 	// printf("0: %p", 0);
// 	return (0);
// }
