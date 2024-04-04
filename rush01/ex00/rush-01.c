/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:33:15 by bchallat          #+#    #+#             */
/*   Updated: 2024/03/24 19:44:40 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_tab(int (*c)[4]);
void	ft_solve_tab(int tab_arg[4][4], int tab_res[4][4]);
void	ft_create_tab(char *c, int tab[4][4]);

int	main(int argc, char **argv)
{
	int	tab_arg[4][4];
	int	tab_res[4][4];

	if (argc != 2)
		return (1);
	ft_create_tab(argv[1], tab_arg);
	ft_solve_tab(tab_arg, tab_res);
	ft_print_tab(tab_res);
	return (0);
}
