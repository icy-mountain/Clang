/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:23:06 by ykori             #+#    #+#             */
/*   Updated: 2020/02/18 13:56:09 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	dot_flag(unsigned char nb, t_format *f)
{
	int thre;
	int	c;

	c = 0;
	thre = 1;
	while (f->flag % fl2pn('-') != 0 && thre < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	while (c++ < thre && f->rtn++ > -1)
		ft_putchar(nb);
	while (f->flag % fl2pn('-') == 0 && thre < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	minus_flag(unsigned char nb, t_format *f)
{
	int	size;

	size = 1;
	ft_putchar(nb);
	f->rtn++;
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	other_flag(unsigned char nb, t_format *f)
{
	int	size;

	size = 1;
	while (f->flag % fl2pn('0') == 0 && size < f->pad-- && f->rtn++ > -1)
		ft_putchar('0');
	while (f->flag % fl2pn('0') != 0 && size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	ft_putchar(nb);
	f->rtn++;
}

void		pf_putchar(int nb, t_format *f)
{
	unsigned char	nbr;

	nbr = (unsigned char)nb;
	if (f->flag % fl2pn('.') == 0)
		dot_flag(nbr, f);
	else if (f->flag % fl2pn('-') == 0)
		minus_flag(nbr, f);
	else
		other_flag(nbr, f);
}
