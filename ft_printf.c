/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:20:46 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/27 10:54:48 by bagovic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//cspdiuxX%

static char	*ft_get_wildcards(void)
{
	char	*wildcards;

	wildcards = malloc(sizeof (char) * 9);
	wildcards[0] = 'c';
	wildcards[1] = 's';
	wildcards[2] = 'p';
	wildcards[3] = 'd';
	wildcards[4] = 'i';
	wildcards[5] = 'u';
	wildcards[6] = 'x';
	wildcards[7] = 'X';
	wildcards[8] = '%';
	return (wildcards);
}

static char	ft_check_wildcard(const char format)
{
	char	*wildcards;
	int		wc_i;

	wildcards = ft_get_wildcards();
	wc_i = 0;
	while (wc_i < 9)
	{
		if (format == wildcards[wc_i])
			return (1);
		wc_i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		format_i;

	format_i = 0;
	while (format[format_i] != '\0')
	{
		if (format[format_i] == '%')
		{
			if (ft_check_wildcard(format[++format_i]) == 1)
				write(1, &format[format_i], 1);
			else
				write(1, &format[--format_i], 1);
		}
		else
			write(1, &format[format_i], 1);
		format_i++;
	}
	return (0);
}

// int	main(void)
// {
// 	ft_printf("Hello,%sWorld!");
// 	return (0);
// }