/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:30:06 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/28 18:03:06 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int nb_char)
{
	write(1, &c, nb_char);
}

int	ft_checknumber(int nb)
{
	if (nb == 0)
	{
		ft_putchar('0', 1);
		return (0);
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	return (1000000000);
}

void	ft_putnbr(int nb)
{
	int	temp;
	int	div;
	int	pass0;

	div = ft_checknumber(nb);
	temp = nb;
	pass0 = 0;
	if (nb < 0 && nb != -2147483648)
	{
		nb *= -1;
		ft_putchar('-', 1);
	}
	while (div != 0)
	{
		temp = nb / div;
		if (temp % 10 != 0)
		{
			pass0 = 1;
		}
		if (pass0 == 1)
		{
			ft_putchar(temp % 10 + '0', 1);
		}
		div = div / 10;
	}
}
