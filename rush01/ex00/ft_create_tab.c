/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:36:43 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/24 19:48:18 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void	ft_print_tab(int (*c)[4]);

void	ft_create_tab(char *c, int tab[4][4])
{
	int	i;
	int	y;
	int	k;

	i = 0;
	y = 0;
	k = 0;
	while (i < 4)
	{
		while (y < 4)
		{
			if (c[k] != '\0' && c[k] != ' ')
			{
				tab[i][y] = (c[k++] - '0');
				y++;
			}
			else
				k++;
		}
		y = 0;
		i++;
	}
}

/*#include <unistd.h>
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error", 5);
		return (1);
	}
	int	tab[4][4];
	ft_create_tab(argv[1], tab);
    	ft_print_tab(tab);
	
}*/
