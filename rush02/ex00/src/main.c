/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slipin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:25:40 by slipin            #+#    #+#             */
/*   Updated: 2024/03/30 22:25:47 by slipin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
char	**ft_split(char *str, char *charset);
char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_atoi_dict(char *str);
char	*get_value(char *key, char ***dict);
char	*char_to_str(char a);
char	*triade_to_word(char *triade, char ***dict);
char	**add_xllions(char **table_triades, char ***dict, int size);
void	ft_putstr(char *str);
int		fill_dict_element(char *str, char *dict_elmnt, \
		char base_from, char base_to);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		count_strings(char *str, char *charset);
int		check_zero(char **table_triades);
int		value_in_base(char value, char *base);
int		ft_strcmp(char *s1, char *s2);
int		count_word_length(char *triade, char ***dict);

char	*read_dict(int argc, char **argv)
{
	char	*buffer;
	int		fd;
	int		buffer_size;
	int		bytes_read;

	buffer_size = 4096;
	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	buffer = malloc(buffer_size + 1);
	if (fd == -1 || buffer == NULL)
	{
		write(1, "Dict Error\n", 11);
		return (NULL);
	}
	bytes_read = read(fd, buffer, buffer_size);
	close(fd);
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	***structure_dict(char	*dict)
{
	char	**dict_table;
	char	***dict_structured;
	int		i;

	dict_table = malloc(sizeof(char *) * (count_strings(dict, "\n") + 1));
	dict_table = ft_split(dict, "\n");
	dict_structured = malloc(sizeof(char **) * (count_strings(dict, "\n") + 1));
	i = 0;
	while (dict_table[i] != 0)
	{
		dict_structured[i] = malloc(sizeof(char *) * 3);
		dict_structured[i] = ft_atoi_dict(dict_table[i]);
		i++;
	}
	free(dict_table);
	dict_table[i] = NULL;
	return (dict_structured);
}

char	*get_triade(char *str, int length)
{
	char	*triade;
	int		i;
	int		j;

	i = 0;
	j = 0;
	triade = malloc(sizeof(char) * (3 + 1));
	while (i < 3 - length)
	{
		triade[i] = '0';
		i++;
	}
	while (i < 3)
	{
		triade[i] = str[j];
		i++;
		j++;
	}
	triade[i] = '\0';
	return (triade);
}

char	**cut_to_triades(char *str)
{
	char	**table_triads;
	int		i;
	int		j;
	int		mod;

	i = 0;
	j = 0;
	mod = ft_strlen(str) % 3;
	table_triads = malloc(sizeof(char *) * \
			(ft_strlen(str) / 3 + (mod > 0) + 1));
	if (mod > 0)
	{
		table_triads[j] = get_triade(str, mod);
		j++;
	}
	i += mod;
	while (i < ft_strlen(str))
	{
		table_triads[j] = get_triade(str + i, 3);
		i += 3;
		j++;
	}
	table_triads[j] = NULL;
	return (table_triads);
}

int	main(int argc, char **argv)
{
	char	*dict;
	char	***dict_structured;
	char	**triade_example;
	int		i;

	if (argc == 1)
		return (0);
	dict = read_dict(argc, argv);
	if (dict == NULL)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	dict_structured = structure_dict(dict);
	triade_example = cut_to_triades(argv[argc - 1]);
	if (check_zero(triade_example))
		ft_putstr(get_value("0", dict_structured));
	else
	{
		i = 0;
		while (triade_example[i] != 0)
			i++;
		triade_example = add_xllions(triade_example, dict_structured, i);
		ft_putstr(ft_strjoin(i, triade_example, " "));
	}
}
