/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:06:46 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/12 09:12:59 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power > 0)
		nb *= ft_recursive_power(nb, power - 1);
	else
		return (1);
	return (nb);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	nb;
	int	power;

	if (ac == 3)
	{
		nb = atoi(av[1]);
		power = atoi(av[2]);
		printf("%i ^ %i = %i\n", nb, power, ft_recursive_power(nb, power));
	}
}
*/
