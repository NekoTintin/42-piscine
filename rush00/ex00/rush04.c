/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:36:08 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/17 13:39:03 by alassa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

char	ft_selectchar(int x, int y, int cur_x, int cur_y)
{
	if ((cur_x == 1 && cur_y == 1) || (cur_x == x && cur_y == y))
	{
		return ('A');
	}
	if ((cur_x == 1 && cur_y == y) || (cur_x == x && cur_y == 1))
	{
		return ('C');
	}
	if (cur_x == 1 || cur_x == x || cur_y == 1 || cur_y == y)
	{
		return ('B');
	}
	return (' ');
}

void	rush(int x, int y)
{
	char	nl;
	int		cur_x;
	int		cur_y;

	cur_x = 1;
	cur_y = 1;
	nl = 10;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (cur_y <= y)
	{
		while (cur_x <= x)
		{
			ft_putchar(ft_selectchar(x, y, cur_x, cur_y));
			cur_x++;
		}
		ft_putchar(nl);
		cur_x = 1;
		cur_y++;
	}
}
