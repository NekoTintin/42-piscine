/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:56:48 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/18 16:21:39 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n0, char n1, char n2)
{
	write(1, &n0, 1);
	write(1, &n1, 1);
	write(1, &n2, 1);
	if (n0 < '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	n0;
	char	n1;
	char	n2;

	n0 = '0';
	n1 = n0 + 1;
	n2 = n1 + 1;
	while (n0 <= '7')
	{
		while (n1 <= '8')
		{
			while (n2 <= '9')
			{
				if (n0 < n1 && n1 < n2)
				{
					ft_putchar(n0, n1, n2);
				}
				n2++;
			}
			n1++;
			n2 = '0';
		}
		n0++;
		n1 = '0';
	}
}
