/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:02:13 by ykori             #+#    #+#             */
/*   Updated: 2020/02/17 12:58:23 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	set_num_udlr(int board[10][10], int r, int c, int num)
{
	int		save_r;
	int		save_c;

	save_r = r;
	save_c = c;
	while (r >= 0)
		board[r--][c] = num;
	r = save_r;
	while (r <= 9)
		board[r++][c] = num;
	r = save_r;
	while (c >= 0)
		board[r][c--] = num;
	c = save_c;
	while (c <= 9)
		board[r][c++] = num;
}

void	set_num_dia(int board[10][10], int r ,int c, int num)
{
	int		save_r;
	int		save_c;

	save_r = r;
	save_c = c;
	while (r >= 0 && c >= 0)
		board[r--][c--] = num;
	r = save_r;
	c = save_c;
	while (r >= 0 && c <= 9)
		board[r--][c++] = num;
	r = save_r;
	c = save_c;
	while (r <= 9 && c >= 0)
		board[r++][c--] = num;
	r = save_r;
	c = save_c;
	while (r <= 9 && c <= 9)
		board[r++][c++] = num;
}

int		rec(int board[10][10], int r, int c, int ans)
{
	printf("now row:%i col:%i ans:%i\n",r,c,ans);
	int x;
	int y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
			printf("%i ",board[x][y++]);
		x++;
		puts("");
	}
	puts("");
	if (board[r][c] == 0)
	{

		set_num_dia(board, r, c, 1);
		set_num_udlr(board, r, c, 1);
		if (c == 9)
		{
			ans++;
			puts("puts!!");
			return (ans);
		}
		if (r != 9 && c != 9)
			rec(board, 0, c + 1, ans);
		if (r == 9 && c == 0)
		{
			rec(board, 0, c + 1, ans);
			return (ans);
		}
		set_num_dia(board, r, c, 0);
		set_num_udlr(board, r, c, 0);
		if (r != 9 && c < 9)
			rec(board, r + 1, c, ans);
	}
	else
	{
		if (r == 9 && c == 0)
		{
			rec(board, 0, c + 1, ans);
			return (ans);
		}
		else if (r != 9)
			rec(board, r + 1, c, ans);
		else if (c != 9)
			rec(board, 0, c + 1, ans);
	}
	return (ans);
}

int		ft_ten_queens_puzzle(void)
{
	int		board[10][10];
	int		row;
	int		col;

	row = -1;
	while (++row < 10)
	{
		col = 0;
		while (col < 10)
			board[row][col++] = 0;
	}

	return (rec(board, 0, 0, 0));
}

int		main(void)
{
	printf("ans : %i\n", ft_ten_queens_puzzle());
	return (0);
}
