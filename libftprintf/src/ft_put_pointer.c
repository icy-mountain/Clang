/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:23:06 by ykori             #+#    #+#             */
/*   Updated: 2020/02/18 13:56:09 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_base(long unsigned int nbr, unsigned int obase, char *base)
{
	if (nbr < obase)
		write(1, &base[nbr], 1);
	else
	{
		print_base(nbr / obase, obase, base);
		write(1, &base[nbr % obase], 1);
	}
}

void		ft_put_pointer(long unsigned int nbr, char *base)
{
	unsigned int	obase;
	char			*save;

	obase = 0;
	while (*base != '\0')
	{
		if (*base == '-' || *base == '+')
			return ;
		save = base;
		while (*(base++) != '\0')
		{
			if (*base == *save)
				return ;
		}
		base = save;
		obase++;
		base++;
	}
	if (obase <= 1)
		return ;
	print_base(nbr, obase, base - obase);
}
