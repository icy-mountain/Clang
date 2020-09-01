/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:08:40 by ykori             #+#    #+#             */
/*   Updated: 2020/02/27 14:30:55 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

int		plus(int l, int r);

int		minus(int l, int r);

int		mul(int l, int r);

int		div(int l, int r);

int		mod(int l, int r);

int		calc(char op, int left, int right);

int		write_err(char *str);

char	judge_ope(char *str);

int		ft_atoi(char *str);

void	ft_putnbr(int nbr);

#endif
