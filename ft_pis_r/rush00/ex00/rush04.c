/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:47:44 by ynakamur          #+#    #+#             */
/*   Updated: 2020/02/09 21:51:48 by ynakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	choise_char(int row, int col, int row_max, int col_max)
{
	if (row == 0)
	{
		if (col == 0)
			ft_putchar('A');
		else if (col == col_max - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else if (row == row_max - 1)
	{
		if (col == 0)
			ft_putchar('C');
		else if (col == col_max - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else
	{
		if (col == 0 || col == col_max - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (x == 0 || y == 0)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			choise_char(j, i, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
