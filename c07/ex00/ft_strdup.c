/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:38:45 by qupollet          #+#    #+#             */
/*   Updated: 2024/03/28 18:41:09 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strdup(char *src)
{
	char*	ptr;
	int	nb_char;
	int	i;

	nb_char = ft_strlen(src);
	i = 0;
	ptr = (char*)malloc(sizeof(char) * (nb_char + 1));
	if (ptr == NULL)
		 exit(1);
	while (i < nb_char)
	{
		ptr[i] = src[i];
		i++;
	}	
	return (ptr);

}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", strcmp(strdup("Test"), ft_strdup("Test")) == 0 ? "OK" : "Fail");
	printf("%s\n", strcmp(strdup("484df41hdy1h111fs1fsd15sf15sdf115d15fdgs15gfd4sg1615df156g1515g4erg4561esg156gr15156g15eg15eg15e51e51g1515ge156e156eg156e15156ge516e1551eg51eg15g1551eg15e516eg15e15eg1515e55eg51e15e51g5151eg15eg1515egr515151erg51er51e51e551ee5eg51egr51er51er5er5eg51e5r1e51rg5egr5eg51erg5e1r51e6rg51egr516ee5g15e1g5e1g5e1g51ger51egr51erg55reg5er55er55"), ft_strdup("484df41hdy1h111fs1fsd15sf15sdf115d15fdgs15gfd4sg1615df156g1515g4erg4561esg156gr15156g15eg15eg15e51e51g1515ge156e156eg156e15156ge516e1551eg51eg15g1551eg15e516eg15e15eg1515e55eg51e15e51g5151eg15eg1515egr515151erg51er51e51e551ee5eg51egr51er51er5er5eg51e5r1e51rg5egr5eg51erg5e1r51e6rg51egr516ee5g15e1g5e1g5e1g51ger51egr51erg55reg5er55er55")) == 0 ? "OK" : "Fail");
}
