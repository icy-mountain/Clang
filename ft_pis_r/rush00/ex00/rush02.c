/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 09:13:24 by ykori             #+#    #+#             */
/*   Updated: 2020/02/09 18:02:43 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_char(int i, int j, int x, int y)
{
	if (i == 0)
	{
		if (j == 0 || j == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else if (i == y - 1)
	{
		if (j == 0 || j == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (j == 0 || j == x - 1)
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
	if (x < 1)
		return ;
	while (i < y)
	{
		while (j < x)
		{
			print_char(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
