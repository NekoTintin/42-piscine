/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:11:55 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/25 11:46:45 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char *str)
{
	if (*str < 'a' || *str > 'z')
	{
		return (0);
	}
	return (1);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_lowercase(&str[i]) == 1)
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
