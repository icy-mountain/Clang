/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <ykori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:58:59 by ykori             #+#    #+#             */
/*   Updated: 2020/06/23 16:02:00 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_numlen(long long num, int base)
{
	int	deci;

	deci = 1;
	if (num == LLONG_MIN)
		num += 1;
	if (num < 0)
		num *= -1;
	while (num >= base)
	{
		deci += 1;
		num /= base;
	}
	return (deci);
}

int		ft_numlen_ull(unsigned long long num, int base)
{
	int	deci;

	deci = 1;
	while (num >= (unsigned long long)base)
	{
		deci += 1;
		num /= base;
	}
	return (deci);
}

int		ft_numlen_ui(unsigned int num, int base)
{
	int	deci;

	deci = 1;
	while (num >= (unsigned int)base)
	{
		deci += 1;
		num /= base;
	}
	return (deci);
}

int		ft_numlen_i(int num, int base)
{
	int	deci;

	deci = 1;
	if (num == INT_MIN)
		num += 1;
	if (num < 0)
		num *= -1;
	while (num >= base)
	{
		deci += 1;
		num /= base;
	}
	return (deci);
}

int		ft_numlen_lui(long unsigned int num, int base)
{
	int	deci;

	deci = 1;
	while (num >= (long unsigned int)base)
	{
		deci += 1;
		num /= base;
	}
	return (deci);
}
