/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berminagovic <berminagovic@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:48:39 by bagovic           #+#    #+#             */
/*   Updated: 2021/11/06 09:54:31 by berminagovi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define INT_MAX __INT_MAX__
#define INT_MIN (-__INT_MAX__ -1)
#define LONG_MAX __LONG_MAX__
#define LONG_MIN (-__LONG_MAX__ -1L)
#define ULONG_MAX (__LONG_MAX__ *2UL+1UL)
#define UINT_MAX (__INT_MAX__ *2U +1U)

	// TEST(13, print(" %d ", -9));
	// TEST(14, print(" %d ", -10));
	// TEST(15, print(" %d ", -11));
	// TEST(16, print(" %d ", -14));
	// TEST(17, print(" %d ", -15));
	// TEST(18, print(" %d ", -16));
	// TEST(19, print(" %d ", -99));
	// TEST(20, print(" %d ", -100));
	// TEST(21, print(" %d ", -101));
	// TEST(23, print(" %d ", INT_MIN));
	// TEST(24, print(" %d ", LONG_MAX));
	// TEST(25, print(" %d ", LONG_MIN));
	// TEST(26, print(" %d ", UINT_MAX));
	// TEST(27, print(" %d ", ULONG_MAX));
	// TEST(28, print(" %d ", 9223372036854775807LL));
	// TEST(29, print(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

void	test_ft_printf()
{
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %d\n", -9));
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %d\n", -10));
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %d\n", -15));
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %d\n", -16));
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %d\n", -99));
	ft_printf("OUTPUT_COUNT: %d\n", ft_printf("OUTPUT: %d\n", -101));
}

void	test_printf()
{
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %d\n", -9));
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %d\n", -10));
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %d\n", -15));
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %d\n", -16));
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %d\n", -99));
	printf("OUTPUT_COUNT: %d\n", printf("OUTPUT: %d\n", -101));
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