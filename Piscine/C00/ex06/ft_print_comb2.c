/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:42:58 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/05 11:05:45 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	k;

	i = 0;
	while (i <= 98)
	{
		k = i + 1;
		while (k <= 99)
		{
			put_char(i / 10 + '0');
			put_char(i % 10 + '0');
			write(1, " ", 1);
			put_char(k / 10 + '0');
			put_char(k % 10 + '0');
			if (i != 98)
			{
				write(1, ", ", 2);
			}
			k++;
		}
		i++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
}
*/
