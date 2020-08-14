/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ui.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:23:06 by ykori             #+#    #+#             */
/*   Updated: 2020/02/18 13:56:09 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	dot_flag(unsigned int nb, char *base, t_format *f)
{
	int	size;

	size = ft_numlen_ui(nb, 16);
	f->rtn += size;
	if (f->flag % fl2pn('#') == 0)
		f->pad -= 2;
	while (f->flag % fl2pn('-') != 0 && f->pred < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	if (f->flag % fl2pn('#') == 0 && (f->rtn += 2) > -1)
	{
		if (base[10] == 'A')
			write(1, "0X", 2);
		if (base[10] == 'a')
			write(1, "0x", 2);
	}
	if (nb == 0 && f->pred == 0 && f->rtn-- > -1)
		return ;
	while (size++ < f->pred && f->rtn++ > -1)
		ft_putchar('0');
	ft_putnbr_base_ui(nb, base);
	while (f->flag % fl2pn('-') == 0 && f->pred < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	minus_flag(unsigned int nb, char *base, t_format *f)
{
	int	size;

	size = ft_numlen_ui(nb, 16);
	if (f->flag % fl2pn('#') == 0 && (f->rtn += 2) > -1)
	{
		if (base[10] == 'A')
			write(1, "0X", 2);
		if (base[10] == 'a')
			write(1, "0x", 2);
		f->pad -= 2;
	}
	f->rtn += size;
	ft_putnbr_base_ui(nb, base);
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	zero_flag(unsigned int nb, char *base, t_format *f)
{
	int	size;

	size = ft_numlen_ui(nb, 16);
	if (f->flag % fl2pn('#') == 0 && (f->rtn += 2) > -1)
	{
		if (base[10] == 'A')
			write(1, "0X", 2);
		if (base[10] == 'a')
			write(1, "0x", 2);
		f->pad -= 2;
	}
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar('0');
	f->rtn += size;
	ft_putnbr_base_ui(nb, base);
}

static void	other_flag(unsigned int nb, char *base, t_format *f)
{
	int	size;

	size = ft_numlen_ui(nb, 16);
	if (f->flag % fl2pn('#') == 0 && (f->rtn += 2) > -1)
	{
		f->pad -= 2;
		while (size < f->pad-- && f->rtn++ > -1)
			ft_putchar(' ');
		if (base[10] == 'A')
			write(1, "0X", 2);
		if (base[10] == 'a')
			write(1, "0x", 2);
	}
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	f->rtn += size;
	ft_putnbr_base_ui(nb, base);
}

void		pf_putnbr_base_ui(unsigned int nb, char *base, t_format *f)
{
	if (f->flag % fl2pn('.') == 0 && nb == 0 && f->pred == 0)
	{
		dot_flag(nb, base, f);
		while (f->flag % fl2pn('-') == 0 && f->pred < f->pad-- && \
			f->rtn++ > -1)
			ft_putchar(' ');
		return ;
	}
	if (f->pred < ft_numlen_ui(nb, 16))
		f->pred = ft_numlen_ui(nb, 16);
	if (f->flag % fl2pn('.') == 0)
		dot_flag(nb, base, f);
	else if (f->flag % fl2pn('-') == 0)
		minus_flag(nb, base, f);
	else if (f->flag % fl2pn('0') == 0)
		zero_flag(nb, base, f);
	else
		other_flag(nb, base, f);
}
