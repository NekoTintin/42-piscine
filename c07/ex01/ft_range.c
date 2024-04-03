/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:57:41 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/28 20:50:11 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	total_size;
	int	nb_i;
	int	*ptr;

	nb_i = 0;
	if (min >= max)
		return (NULL);
	total_size = max - min;
	ptr = (int*)malloc(sizeof(int) * total_size);
	if (ptr == NULL)
		return (NULL);
	while (nb_i < total_size)
	{
		ptr[nb_i] = min + nb_i;
		nb_i++;
	}
	return (ptr);
}

#include <stdio.h>

int *ft_range(int min, int max);

int	main(void)
{
	int *range;

	printf("Warn: Don't forget to check that the array is of the correct size manually ! Can't know size of `malloc` arrays\n");
	printf("Warn: Any segfault will mean that arrays are not correctly allocated\n");

	range = ft_range(0, 5);
	printf("0, 1, 2, 3, 4 : %d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);
	
	range = ft_range(3, 3);
	range = ft_range(-1, 1);
	printf("-1, 0 : %d, %d", range[0], range[1]);
}
