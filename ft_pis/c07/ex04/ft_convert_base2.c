/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:53:39 by ykori             #+#    #+#             */
/*   Updated: 2020/02/19 11:26:48 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		at(char *base, char c)
{
	int		idx;

	idx = 0;
	while (*base != '\0')
	{
		if (*base == c)
			return (idx);
		base++;
		idx++;
	}
	return (-1);
}

char	*init(char *c, int size)
{
	char	*save;

	save = c;
	while (size > 1)
	{
		*c = '\0';
		c++;
		size--;
	}
	return (save);
}

int		check_sp_and_np(char *str, char *from)
{
	while (*str != '+' && *str != '-')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n'\
			|| *str == '\v' || *str == '\f' || *str == '\r')
			str++;
		else if (at(from, *str) > -1)
			return (1);
		else
			return (0);
	}
	while (*str != '\0')
	{
		if (*str == '+' || *str == '-')
			str++;
		else if (at(from, *str) > -1)
			return (1);
		else
			return (0);
	}
	return (1);
}
