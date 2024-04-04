/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slipin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:38:35 by slipin            #+#    #+#             */
/*   Updated: 2024/03/30 19:30:20 by slipin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*substring;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && ft_strlen(to_find) > 0)
	{
		if (str[i + ft_strlen(to_find) - 1] != '\0')
		{
			if (ft_strncmp(str + i, to_find, ft_strlen(to_find)) == 0)
			{
				j = 0;
				substring = malloc(sizeof(char) * i + 1);
				while (j < i)
				{
					substring[j] = str[j];
					j++;
				}
				substring[j] = '\0';
				return (substring);
			}
			i++;
		}
	}
	return (str);
}

int	count_strings(char *str, char *charset)
{
	int	i;
	int	count;
	int	substring;

	count = 0;
	i = 0;
	substring = 0;
	while (str[i + ft_strlen(charset) - 1] != '\0')
	{
		if (ft_strncmp(str + i, charset, ft_strlen(charset)) != 0 \
				&& substring == 0)
		{
			count++;
			substring = 1;
		}
		else
			substring = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**splitted_table;
	char	*substring;
	int		i;
	int		j;

	splitted_table = malloc(sizeof(char *) * (count_strings(str, charset) + 1));
	if (splitted_table == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(str))
	{
		substring = ft_strstr(str + i, charset);
		splitted_table[j] = substring;
		i += ft_strlen(substring);
		i += ft_strlen(charset);
		if (ft_strlen(substring) > 0)
			j++;
	}
	splitted_table[j] = 0;
	return (splitted_table);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char **final_table = ft_split(argv[1], argv[2]);
	//printf("%d\n", count_strings(argv[1], argv[2]));	
//	printf("%s\n", ft_strstr(argv[1], argv[2]));	
//	char *input_table[2];
//	input_table[0] = "oooo";
//	input_table[1] = "o";
//	char **final_table = ft_split(input_table[0], input_table[1]);
		int	i = 0;
		while (final_table[i] != 0)
		{
			printf("str %d: %s\n", i, final_table[i]);
			i++;
		}
	}
				//return (cut_string(str, i));
}
*/
