/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:19:01 by ykori             #+#    #+#             */
/*   Updated: 2020/02/16 16:26:17 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reset_twice(int twice[5])
{
	int		idx;

	idx = 0;
	while (idx < 5)
	{
		twice[idx] = 0;
		idx++;
	}
}

int		check_twice(int g_arr[6][6])
{
	int		twice[5];
	int		x;
	int		y;

	reset_twice(twice);
	y = 1;
	while (y < 5)
	{
		x = 1;
		while (x < 5)
		{
			if (twice[g_arr[x][y]] == 1)
				return (0);
			twice[g_arr[x][y]] = 1;
			x++;
		}
		reset_twice(twice);
		y++;
	}
	return (1);
}

int		check_upcol_view(int view, int y, int g_arr[6][6])
{
	int		max;
	int		ans;
	int		idx;

	idx = 1;
	ans = 0;
	max = 0;
	while (idx < 5)
	{
		if (g_arr[idx][y] > max)
		{
			ans++;
			max = g_arr[idx][y];
		}
		idx++;
	}
	if (ans == view)
		return (1);
	else
		return (0);
}

int		check_downcol_view(int view, int y, int g_arr[6][6])
{
	int		max;
	int		ans;
	int		idx;

	idx = 4;
	ans = 0;
	max = 0;
	while (idx > 0)
	{
		if (g_arr[idx][y] > max)
		{
			ans++;
			max = g_arr[idx][y];
		}
		idx--;
	}
	if (ans == view)
		return (1);
	else
		return (0);
}

int		judge_col(int g_arr[6][6])
{
	int		y;

	y = 1;
	if (check_twice(g_arr) == 0)
		return (0);
	while (y < 5)
	{
		if (check_upcol_view(g_arr[0][y], y, g_arr) == 0)
			return (0);
		if (check_downcol_view(g_arr[5][y], y, g_arr) == 0)
			return (0);
		y++;
	}
	return (1);
}
