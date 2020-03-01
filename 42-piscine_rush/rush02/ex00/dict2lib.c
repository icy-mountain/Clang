/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict2lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:47:56 by ykori             #+#    #+#             */
/*   Updated: 2020/02/23 22:50:10 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	write_value(char *dict, char *key, char *argv)
{
	char	*value;
	int		size;

	value = search_val(dict, key);
	size = str_len(value, '\n');
	write(1, value, size);
	write_sp(key, argv);
	free(value);
}

int		ft_loopcnv(char *str, int num, char *dict, char *tmp)
{
	if (num == 3 && (*str != '0'))
	{
		tmp[0] = *str;
		write_value(dict, tmp, str);
		write_value(dict, "100", str);
	}
	if ((num == 2) && (*str > '1'))
	{
		tmp[0] = *str;
		tmp[1] = '0';
		write_value(dict, tmp, str);
	}
	if ((num == 2) && (*str == '1'))
	{
		tmp[0] = *str;
		tmp[1] = *(str + 1);
		write_value(dict, tmp, str);
		return (0);
	}
	if ((num == 1) && (*str > '0'))
	{
		tmp[0] = *str;
		write_value(dict, tmp, str);
	}
	return (1);
}

void	ft_cnv(char *str, int num, char *dict)
{
	char	tmp[4];

	while (num > 0)
	{
		ft_init(tmp, 4);
		if (ft_loopcnv(str, num, dict, tmp) == 0)
			return ;
		num--;
		str++;
	}
}

void	write_digit(char *dict, char *argv, int size, int zero_check)
{
	char	*str;
	int		idx;

	str = argv;
	idx = zero_check++;
	while (--zero_check > 0)
	{
		if (*str++ == '0')
			idx--;
	}
	if (zero_check == idx)
		return ;
	if (size % 3 == 0)
		size -= 2;
	else if (size % 3 == 2)
		size -= 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	ft_init(str, size + 1);
	str[0] = '1';
	idx = 1;
	while (idx < size)
		str[idx++] = '0';
	write_value(dict, str, argv);
	free(str);
}

void	read_argv(char *argv, char *dict)
{
	int		size;

	size = str_len(argv, '\0');
	if (size == 1 && *argv == '0')
		write_value(dict, "0", argv);
	while (size > 0)
	{
		if (str_len(argv, '\0') % 3 == 0)
		{
			ft_cnv(argv, 3, dict);
			if (str_len(argv, '\0') > 3)
				write_digit(dict, argv, size, 3);
			size -= 3;
			argv += 3;
		}
		else
		{
			ft_cnv(argv, str_len(argv, '\0') % 3, dict);
			if (str_len(argv, '\0') > 3)
				write_digit(dict, argv, size, str_len(argv, '\0') % 3);
			size -= str_len(argv, '\0') % 3;
			argv += str_len(argv, '\0') % 3;
		}
	}
}
