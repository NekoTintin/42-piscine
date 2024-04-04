/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:45:00 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/24 20:16:13 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_solve_line(int tab_arg[4], int tab_res[4]);
void	ft_clear_tab(int tab_res[4][4]);

void	ft_solve_tab(int tab_arg[4][4], int tab_res[4][4])
{
	int	i;

	ft_clear_tab(tab_res);
	i = 0;
	while (i < 4)
	{
		ft_solve_line(tab_arg[i], tab_res[i]);
		i++;
	}
}

void	ft_solve_line(int tab_arg[4], int tab_res[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab_arg[i] == 4)
		{
			tab_res[0] = 1;
			tab_res[1] = 2;
			tab_res[2] = 3;
			tab_res[3] = 4;
		}
		i++;
	}
}

void	ft_clear_tab(int tab_res[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab_res[i][j] = 1;
			j++;
		}
		i++;
	}
}
