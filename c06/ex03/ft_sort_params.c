/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:24:57 by qupollet          #+#    #+#             */
/*   Updated: 2024/04/03 17:23:20 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FAIRE STRCMP pour la moulinette
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0') && (s1[i] == s2[i]) && (i + 1) < n)
		i++;
	return (s1[i] - s2[i]);
}

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

int	ft_str_shorter(char *s1, char *s2)
{
	int	size_s1;
	int	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (size_s1 > size_s2)
		return (size_s2);
	else if (size_s2 > size_s1)
		return (size_s1);
	else
		return (size_s1);
}

void	ft_sort_str_tab(char **tab, int size)
{
	int		i;
	int		y;
	char	*temp;

	i = 0;
	y = 0;
	while (i < size)
	{
		while (y < size - 1)
		{
			if (ft_strncmp(tab[y], tab[y + 1],
					ft_str_shorter(tab[y], tab[y + 1])) > 0)
			{
				temp = tab[y];
				tab[y] = tab[y + 1];
				tab[y + 1] = temp;
			}
			y++;
		}
		y = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc <= 1)
		return (1);
	ft_sort_str_tab(argv + 1, argc - 1);
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
