/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slipin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:27:01 by slipin            #+#    #+#             */
/*   Updated: 2024/03/30 22:27:05 by slipin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check_zero(char **table_triades)
{
	int	i;
	int	j;

	i = 0;
	while (table_triades[i] != 0)
	{
		j = 0;
		while (j < 3)
		{
			if (table_triades[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	value_in_base(char value, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (value == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	fill_dict_element(char *str, char *dict_elmnt, char base_from, char base_to)
{
	int	j;

	j = 0;
	while (str[j] >= base_from && str[j] <= base_to)
	{
		dict_elmnt[j] = str[j];
		j++;
	}
	dict_elmnt[j] = '\0';
	return (j);
}

char	**ft_atoi_dict(char *str)
{
	char	**dict_element;
	int		i;

	i = 0;
	dict_element = malloc(sizeof(char *) * 3);
	dict_element[0] = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = fill_dict_element(str, dict_element[0], '0', '9');
	while (value_in_base(str[i], " \t\v\f\r\n"))
		i++;
	if (str[i] != ':')
		return (0);
	i++;
	while (value_in_base(str[i], " \t\v\f\r\n"))
		i++;
	dict_element[1] = malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	i = fill_dict_element(str + i, dict_element[1], 32, 126);
	dict_element[1][i] = '\0';
	dict_element[2] = NULL;
	return (dict_element);
}
