/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:43:52 by ecorona-          #+#    #+#             */
/*   Updated: 2023/08/28 10:52:24 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
		{
			*(str + i) = *(str + i) - 'a' + 'A';
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "Eduardo Corona";

	ft_strupcase(str);
	printf("%s\n", str);
}
*/
