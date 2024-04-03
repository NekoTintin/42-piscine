/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:13:17 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/20 20:48:24 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		return (1);
	}
	if (*str >= 'A' && *str <= 'Z')
	{
		return (2);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_word;

	i = 0;
	is_word = 0;
	while (str[i] != '\0')
	{
		
		if (ft_char_is_alpha(&str[i]) == 1)
		{
			str[i] -= 32;
		}
		if (ft_char_is_alpha(&str[i]) == 2)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

#include <unistd.h>

void	ft_putstr(char *str)
{
	int l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	write(1, str, l);
}

int		main()
{
	char c[] = "salut, coMMent tu vAs ? 42mOts quArAnTe-dEux; cinQuante+et+un";
	ft_putstr("Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un:");
	ft_putstr(ft_strcapitalize(c));
	ft_putstr(":");
	ft_putstr(c);
}
