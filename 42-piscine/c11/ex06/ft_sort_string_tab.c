/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:54:56 by ykori             #+#    #+#             */
/*   Updated: 2020/02/27 13:41:59 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
}

void	swap(char **s1, char **s2)
{
	char	*buf;

	buf = *s1;
	*s1 = *s2;
	*s2 = buf;
}

void	ft_sort_string_tab(char **tab)
{
	int		idx;
	int		flag;

	flag = 1;
	if (tab[0] == 0)
		return ;
	while (flag == 1)
	{
		idx = 0;
		flag = 0;
		while (tab[idx + 1] != 0)
		{
			if (ft_strcmp(tab[idx], tab[idx + 1]) > 0)
			{
				swap(&tab[idx], &tab[idx + 1]);
				flag = 1;
			}
			idx++;
		}
	}
}
