/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:49:48 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/26 18:21:32 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	y;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		y = 0;
		while (str[i] != '\0' && str[i + y] == to_find[y])
		{
			y++;
			if (to_find[y] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
