/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:30:00 by ykori             #+#    #+#             */
/*   Updated: 2020/02/24 11:09:33 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int					str_len(char *str)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

void				ft_putnbr(int nb)
{
	char	ans;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-1 * nb);
	}
	else if (nb < 10)
	{
		ans = nb + '0';
		write(1, &ans, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ans = nb % 10 + '0';
		write(1, &ans, 1);
	}
}

void				ft_show_tab(struct s_stock_str *par)
{
	int		size;

	while (par->str != 0)
	{
		size = str_len(par->str);
		write(1, par->str, size);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		size = str_len(par->copy);
		write(1, par->copy, size);
		write(1, "\n", 1);
		par++;
	}
}
