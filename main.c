/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berminagovic <berminagovic@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:48:39 by bagovic           #+#    #+#             */
/*   Updated: 2021/11/09 20:52:52 by berminagovi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define INT_MAX __INT_MAX__
#define INT_MIN (-__INT_MAX__ -1)
#define LONG_MAX __LONG_MAX__
#define LONG_MIN (-__LONG_MAX__ -1L)
#define ULONG_MAX (__LONG_MAX__ *2UL+1UL)
#define UINT_MAX (__INT_MAX__ *2U +1U)


	// TEST(24, print(" %x ", LONG_MAX));
	// TEST(25, print(" %x ", LONG_MIN));
	// TEST(27, print(" %x ", ULONG_MAX));
	// TEST(28, print(" %x ", 9223372036854775807LL));
	// TEST(29, print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

void	test_ft_printf()
{
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %x\n", -1));
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %x\n", LONG_MAX));
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %x\n", LONG_MIN));
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %x\n", ULONG_MAX));
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %x\n", 9223372036854775807LL));
}

void	test_printf()
{
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %x\n", -1));
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %x\n", LONG_MAX));
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %x\n", LONG_MIN));
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %x\n", ULONG_MAX));
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %x\n", 9223372036854775807LL));
}

int	main(void)
{
	printf("***PRINTF TEST***\n");
	test_printf();
	printf("---------- \n");
	ft_printf("***FT_PRINTF TEST***\n");
	test_ft_printf();
	// ft_printf("LONG_MAX: %x \n", INT_MAX + 1);
	// ft_printf("LONG_MAX: %d \n", INT_MAX + 1);
	// printf("LONG_MAX: %x\n", INT_MAX + 1);
	// printf("LONG_MAX: %i\n", INT_MAX + 1);
	return (0);
}