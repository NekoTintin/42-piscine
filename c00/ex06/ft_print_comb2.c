/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:56:38 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/18 16:23:10 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	n0;
	int	n1;

	n0 = 0;
	while (n0 <= 98)
	{
		n1 = n0 + 1;
		while (n1 <= 99)
		{
			ft_putchar(n0 / 10 + '0');
			ft_putchar(n0 % 10 + '0');
			ft_putchar(' ');
			ft_putchar(n1 / 10 + '0');
			ft_putchar(n1 % 10 + '0');
			if (n0 < 98 && n1 <= 99)
			{
				write(1, ", ", 2);
			}
			n1++;
		}
		n0++;
	}
}
