/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slipin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:27:01 by slipin            #+#    #+#             */
/*   Updated: 2024/03/30 22:27:05 by slipin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src);
char	*get_value(char *key, char ***dict);
char	*triade_to_word(char *triade, char ***dict);
char	*char_to_str(char a);
int		ft_strlen(char *str);
int		count_word_length(char *triade, char ***dict);

char	*create_tens(char *triade)
{
	char	*a;

	a = malloc(sizeof(char) * 3);
	a[0] = triade[1];
	a[1] = '0';
	a[2] = '\0';
	return (a);
}

char	*concat_word(char *word, char *triade, char ***dict)
{
	word = ft_strcat(ft_strcat(word, \
		get_value(char_to_str(triade[0]), dict)), " ");
	word = ft_strcat(word, get_value("100", dict));
	if ((triade[1] != '0') || (triade[2] != '0'))
		word = ft_strcat(word, " ");
	return (word);
}

char	*triade_to_word(char *triade, char ***dict)
{
	char	*word;

	word = malloc(sizeof(char) * (count_word_length(triade, dict) + 2));
	word[0] = '\0';
	if (triade[0] != '0')
	{
		word = concat_word(word, triade, dict);
	}
	if (triade[1] == '1')
		word = ft_strcat(word, get_value(triade + 1, dict));
	else
	{
		if (triade[1] > '1')
		{
			word = ft_strcat(word, get_value(create_tens(triade), dict));
			if (triade[2] != '0')
				word = ft_strcat(word, " ");
		}
		if (triade[2] != '0')
			word = ft_strcat(word, get_value(triade + 2, dict));
	}
	word[ft_strlen(word)] = '\0';
	return (word);
}

char	*make_table_new(char *triade, int size, char ***dict, int i)
{
	char	*key;
	char	*tab;
	int		j;

	j = 0;
	key = malloc(sizeof(char) * ((size - 1) * 3 + 2));
	key[0] = '\0';
	ft_strcat(key, "1\0");
	while (j < size - 1 - i)
	{
		ft_strcat(key, "000");
		j++;
	}
	key[(size - 1) * 3 + 1] = '\0';
	tab = malloc(sizeof(char) * (ft_strlen(triade_to_word(triade, dict)) \
		+ (size - 1 > i) * (ft_strlen(get_value(key, dict)) + 1)));
	tab = triade_to_word(triade, dict);
	if (size - 1 > i)
		tab = ft_strcat(ft_strcat(tab, " "), get_value(key, dict));
	return (tab);
}

char	**add_xllions(char **table_triades, char ***dict, int size)
{
	char	**table_new;
	int		i;

	i = 0;
	table_new = malloc(sizeof(char *) * (size + 1));
	while (table_triades[i] != NULL)
	{
		table_new[i] = make_table_new(table_triades[i], size, dict, i);
		i++;
	}
	table_new[i] = NULL;
	return (table_new);
}
