/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

char	*get_value(char *key, char ***dict)
{
	int	i;

	i = 0;
	while (dict[i] != 0)
	{
		if (ft_strcmp(key, dict[i][0]) == 0)
			return (dict[i][1]);
		i++;
	}
	write(1, "value not found in dict\n", 24);
	return (0);
}

char	*char_to_str(char a)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = a;
	str[1] = '\0';
	return (str);
}

int	count_word_length(char *triade, char ***dict)
{
	char	*a;
	int		word_length;

	word_length = 0;
	if (triade[0] != '0')
	{
		word_length += ft_strlen(get_value(char_to_str(triade[0]), dict)) + 1;
		word_length += ft_strlen(get_value("100", dict)) + 1;
	}
	if (triade[1] == '1')
		word_length += ft_strlen(get_value(triade + 1, dict));
	else
	{
		if (triade[1] > '1')
		{
			a = malloc(sizeof(char) * 2);
			a[0] = triade[1];
			a[1] = '0';
			a[2] = '\0';
			word_length += ft_strlen(get_value(a, dict)) + 1;
		}
		if (triade[2] != '0')
			word_length += ft_strlen(get_value(triade + 2, dict));
	}
	return (word_length);
}
