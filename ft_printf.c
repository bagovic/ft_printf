/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berminagovic <berminagovic@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< Updated upstream
/*   Created: 2021/09/27 09:20:46 by bagovic           #+#    #+#             */
/*   Updated: 2021/09/30 17:15:19 by bagovic          ###   ########.fr       */
=======
/*   Created: 2021/10/13 12:56:42 by berminagovi       #+#    #+#             */
/*   Updated: 2021/10/21 19:55:47 by berminagovi      ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//cspdiuxX%

static char	*ft_get_wildcards(void)
{
	char	*wildcards;

<<<<<<< Updated upstream
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
=======
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	// write(1, content, 1);
	lst = NULL;
	lst = malloc(sizeof (struct s_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

static	char	*ft_getwc(va_list valist, t_list *print_list, char wildcard)
{
	char	*p;

	p = va_arg(valist, char *);
	if (wildcard == 'c')
	{
		write(5, &p, 1);
		ft_lstadd_back(&print_list, ft_lstnew(&p));
	}
	// else if (wildcard == 's')
	// 	wc = p;
	// // p
	// else if (wildcard == 'd')
	// 	wc = p;
	// else if (wildcard == '%')
	// 	wc = (char *)'%';
	return(NULL);
>>>>>>> Stashed changes
}

static char	ft_check_wildcard(const char *format)
{
	char	*wildcards;
	int		format_i;
	int		wc_i;

	wildcards = ft_get_wildcards();
	format_i = 0;
	while (format[format_i] != '\0')
	{
		if (format[format_i] == '%')
		{
			format_i++;
			wc_i = 0;
			while (wc_i < 9)
			{
				if (format[format_i] == wildcards[wc_i])
					return (1);
				wc_i++;
			}
		}
		format_i++;
	}
	return (0);
}
//cspdiuxX%
static void	ft_print_wildcard(va_list valist, char *wc)
{
	char	*p;

	p = va_arg(valist, char *);
	if ((int) *wc == 'c')
		ft_putchar_fd((char) p, 1);
	else if (*wc == 's')
		ft_putstr_fd(p, 1);
	// else if (*wc == 'p')
	// {}
	else if ((int) *wc == 'd')
		ft_putnbr_fd((int) p, 1);
	else if ((int) *wc == '%')
		ft_putchar_fd((char) p, 1);
}

int	ft_printf(const char *format, ...)
{
	t_list	*wildcards;
	va_list	valist;
	char	*wc;
	int		i;

	i = 0;
	wildcards = NULL;
	if (ft_check_wildcard(format) == 0)
		return (0);
	va_start(valist, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			wc = ft_substr(format, ++i, 1);
			ft_print_wildcard(valist, wc);
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
	ft_printf("Hello%s\n", ", World!");
	return (0);
}