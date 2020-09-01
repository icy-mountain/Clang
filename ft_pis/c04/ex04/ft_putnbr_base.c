/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:23:06 by ykori             #+#    #+#             */
/*   Updated: 2020/02/18 08:55:49 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_base(int num, int obase)
{
	char	ans;
	long	nbr;

	nbr = num;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < obase)
	{
		ans = nbr % obase > 9 ? nbr % obase + 55 : nbr % obase + '0';
		write(1, &ans, 1);
	}
	else
	{
		ans = nbr % obase > 9 ? nbr % obase + 55 : nbr % obase + '0';
		print_base(nbr / obase, obase);
		write(1, &ans, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		obase;
	char	black_l[128];

	obase = 0;
	while (*base != '\0')
	{
		if (black_l[(int)*base] == '!')
			return ;
		if (*base == '-' || *base == '+')
			return ;
		black_l[(int)*base] = '!';
		obase++;
		base++;
	}
	if (obase <= 1)
		return ;
	print_base(nbr, obase);
}
