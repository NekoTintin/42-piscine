/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slipin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:04:35 by slipin            #+#    #+#             */
/*   Updated: 2024/03/28 13:08:16 by slipin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*concat_str;
	int		len;
	int		i;

	if (size == 0)
	{
		concat_str = malloc(sizeof(char));
		concat_str[0] = '\0';
		return (concat_str);
	}
	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	concat_str = malloc(sizeof(char) * (len + ft_strlen(sep) * (size - 1) + 1));
	concat_str[0] = '\0';
	ft_strcat(concat_str, strs[0]);
	i = 1;
	while (i < size)
	{
		ft_strcat(concat_str, sep);
		ft_strcat(concat_str, strs[i++]);
	}
	concat_str = ft_strcat(concat_str, "\0");
	return (concat_str);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*pointer_2[argc - 1];
	int 	i = 1;
	while (i < argc - 1)
	{
		pointer_2[i - 1] = argv[i];
		i++;
	}
	printf("%s\n", ft_strjoin(argc - 2, pointer_2, argv[argc - 1]));

// empty string
//	char *pointer = NULL;
//	char **pointer_2 = &pointer;
//	printf("%s\n", ft_strjoin(0, pointer_2, "SEP"));

}
*/
