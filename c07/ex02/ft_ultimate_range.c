/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:57:37 by qupollet          #+#    #+#             */
/*   Updated: 2024/04/01 14:47:55 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	total_size;
	int	nb_i;
	int	*it;

	nb_i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	total_size = max - min;
	it = malloc(sizeof(int) * total_size);
	if (it == NULL)
		return (-1);
	while (nb_i < total_size)
	{
		it[nb_i] = min + nb_i;
		nb_i++;
	}
	*range = it;
	return (total_size);
}

#include <stdio.h>

int	main(void)
{
	int *range;

	printf("Warn: Any segfault will mean that arrays are not correctly allocated\n");

	printf("5:%d\n", ft_ultimate_range(&range, 0, 5));
	printf("0, 1, 2, 3, 4 : %d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);
	
	printf("0:%d\n", ft_ultimate_range(&range, 3, 3));
	
	printf("2:%d\n", ft_ultimate_range(&range, -1, 1));
	printf("-1, 0 : %d, %d", range[0], range[1]);
}
