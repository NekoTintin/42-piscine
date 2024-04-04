/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:53:34 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/28 12:22:49 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	nb;

	nb = 0;
	while (*str != '\0')
	{
		nb++;
		str++;
	}
	return (nb);
}

int	main(int argc, char **argv)
{
	int	cur_arg;

	cur_arg = 1;
	while (cur_arg < argc)
	{
		write(1, argv[cur_arg], ft_strlen(argv[cur_arg]));
		write(1, "\n", 1);
		cur_arg++;
	}
	return (0);
}
