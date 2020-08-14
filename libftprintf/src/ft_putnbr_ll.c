/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:28:57 by ykori             #+#    #+#             */
/*   Updated: 2020/02/25 08:53:50 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_ll(long long nb)
{
	char	ans;

	if (nb == LLONG_MIN)
		write(1, "9223372036854775808", 19);
	else if (nb < 0)
		ft_putnbr_ll(-1 * nb);
	else if (nb < 10)
	{
		ans = nb + '0';
		write(1, &ans, 1);
	}
	else
	{
		ft_putnbr_ll(nb / 10);
		ans = nb % 10 + '0';
		write(1, &ans, 1);
	}
}
