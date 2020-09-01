/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:12:12 by ykori             #+#    #+#             */
/*   Updated: 2020/02/16 16:26:29 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_argv(char *argv)
{
	int		count_n;
	int		count_sp;
	int		flag;

	flag = 0;
	count_n = 0;
	count_sp = 0;
	while (*argv != '\0')
	{
		if ('1' <= *argv && *argv <= '4' && flag == 0)
		{
			count_n++;
			flag++;
		}
		else if (*argv == ' ' && flag == 1)
		{
			count_sp++;
			flag--;
		}
		else
			return (0);
		argv++;
	}
	return (count_n == 16 && count_sp == 15 ? 1 : 0);
}

void	rm_space(char *argv, char str[17])
{
	int		idx;

	idx = 0;
	while (idx < 16)
	{
		if ('1' <= *argv && *argv <= '4')
		{
			str[idx] = *argv;
			idx++;
		}
		argv++;
	}
}

void	set_col(int g_arr[6][6], char str[17])
{
	int		idx;
	int		y;

	y = 0;
	idx = 0;
	while (idx < 16)
	{
		if (0 <= idx && idx <= 3)
		{
			y = 1;
			while (y < 5)
				g_arr[0][y++] = str[idx++] - '0';
		}
		if (4 <= idx && idx <= 7)
		{
			y = 1;
			while (y < 5)
				g_arr[5][y++] = str[idx++] - '0';
		}
		idx++;
	}
}

void	set_row(int g_arr[6][6], char str[17])
{
	int		idx;
	int		x;

	x = 0;
	idx = 0;
	while (idx < 16)
	{
		if (8 <= idx && idx <= 11)
		{
			x = 1;
			while (x < 5)
				g_arr[x++][0] = str[idx++] - '0';
		}
		if (12 <= idx && idx <= 15)
		{
			x = 1;
			while (x < 5)
				g_arr[x++][5] = str[idx++] - '0';
		}
		idx++;
	}
}

int		make_data(int g_arr[6][6], char *argv)
{
	char	str[17];

	if (check_argv(argv) == 0)
		return (0);
	rm_space(argv, str);
	set_col(g_arr, str);
	set_row(g_arr, str);
	return (1);
}
