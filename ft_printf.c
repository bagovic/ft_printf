/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagovic <bagovic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:20:46 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/27 12:37:19 by bagovic          ###   ########.fr       */
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
//cspdiuxX%
static void	ft_print_wildcard(int element, t_list *wildcard)
{
	if ((char) wildcard->content == 'c')
		ft_putchar_fd((char) element, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	t_list	*wildcards;
	char	wc;
	int		i;

	i = 0;
	wildcards = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (ft_check_wildcard(format[++i]) == 1)
			{
				ft_lstadd_back(&wildcards, ft_lstnew(format[i]));
			}
			else
				write(1, &format[--i], 1);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	write(1, wildcards->content, ft_strlen(wildcards->content));
	return (0);
}

int	main(void)
{
	ft_printf("Hello, %corld!", 'W');
	return (0);
}