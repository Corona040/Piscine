/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:01:32 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/05 11:07:21 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_range(int start, int range)
{
	int	i;

	if (start + range <= 10 && range > 0)
	{
		i = 0;
		while (i < range)
		{
			ft_putchar(start + i + '0');
			i++;
		}
	}
}

void	print_comb(int n, int last_nb, int start)
{
	int	i;

	i = last_nb;
	while (i <= 9)
	{
		print_range(start, n - 1);
		ft_putchar(i + '0');
		if ((start != 10 - n && n != 1) || (n == 1 && i != 9))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		i++;
	}
	if (start != 10 - n && n != 1)
		print_comb(n, last_nb + 1, start + 1);
}

void	ft_print_combn(int n)
{
	if (n > 0 && n < 10)
		print_comb(n, n - 1, 0);
}

/*
#include <stdlib.h>
int	main(int ac, char **av)
{
	ft_print_combn(atoi(av[1]));
}
*/
