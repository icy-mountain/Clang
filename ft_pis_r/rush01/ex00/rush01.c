/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 09:41:54 by ykori             #+#    #+#             */
/*   Updated: 2020/02/16 19:33:21 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "judge_col.h"
#include "make_data.h"

int		g_ans[24][6] = {
	{4, 1, 2, 3, 4, 1},
	{3, 1, 2, 4, 3, 2},
	{3, 1, 3, 2, 4, 1},
	{3, 1, 3, 4, 2, 2},
	{2, 1, 4, 2, 3, 2},
	{2, 1, 4, 3, 2, 3},
	{3, 2, 1, 3, 4, 1},
	{2, 2, 1, 4, 3, 2},
	{3, 2, 3, 1, 4, 1},
	{3, 2, 3, 4, 1, 2},
	{2, 2, 4, 1, 3, 2},
	{2, 2, 4, 3, 1, 3},
	{2, 3, 1, 2, 4, 1},
	{2, 3, 1, 4, 2, 2},
	{2, 3, 2, 1, 4, 1},
	{2, 3, 2, 4, 1, 2},
	{2, 3, 4, 1, 2, 2},
	{2, 3, 4, 2, 1, 3},
	{1, 4, 1, 2, 3, 2},
	{1, 4, 1, 3, 2, 3},
	{1, 4, 2, 1, 3, 2},
	{1, 4, 2, 3, 1, 3},
	{1, 4, 3, 1, 2, 3},
	{1, 4, 3, 2, 1, 4}
};

int		g_arr[6][6] = {
	{-1, 2, 2, 1, 3, -1},
	{2, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 0, 2},
	{1, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 1},
	{-1, 2, 3, 2, 1, -1},
};

int		set(int ans_idx, int arr_idx, int view_l, int view_r)
{
	int		y;

	y = 1;
	if (g_ans[ans_idx][0] == view_l && g_ans[ans_idx][5] == view_r)
	{
		while (y < 5)
		{
			g_arr[arr_idx][y] = g_ans[ans_idx][y];
			y++;
		}
		return (1);
	}
	else
		return (0);
}

void	print_arr(void)
{
	int		x;
	int		y;
	char	c;

	x = 1;
	while (x < 5)
	{
		y = 1;
		while (y < 5)
		{
			c = g_arr[x][y] + '0';
			write(1, &c, 1);
			if (y != 4)
				write(1, " ", 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

int		main_main(int i, int j, int k, int l)
{
	while (i < 24)
	{
		j = 0;
		while (j < 24 && set(i, 1, g_arr[1][0], g_arr[1][5]))
		{
			k = 0;
			while (k < 24 && set(j, 2, g_arr[2][0], g_arr[2][5]))
			{
				l = 0;
				while (l < 24 && set(k, 3, g_arr[3][0], g_arr[3][5]))
				{
					if (set(l, 4, g_arr[4][0], g_arr[4][5]) == 1)
						if (judge_col(g_arr) == 1)
							return (1);
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (make_data(g_arr, argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (main_main(0, 0, 0, 0) == 1)
	{
		print_arr();
		return (0);
	}
	write(1, "Error\n", 6);
	return (0);
}
