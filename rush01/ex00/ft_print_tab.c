/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:32:46 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/24 19:50:26 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Write a two-dimensional tab.
void	ft_print_tab(int (*c)[4])
{
	int		i;
	int		y;
	char	cur;

	i = 0;
	y = 0;
	while (i < 4)
	{
		while (y < 4)
		{
			cur = (c[i][y] + '0');
			write(1, &cur, 1);
			if (y == 3)
				write(1, "\n", 1);
			if (y < 3)
				write(1, " ", 1);
			y++;
		}
		y = 0;
		i++;
	}
}
/*
int	main(void)
{
	int	tab[4][4] = {{4, 2, 3, 1}, {1, 3, 2, 4}, {4, 2, 1, 3}, {2, 3, 1, 4}};
	print_tab(tab);
}*/
