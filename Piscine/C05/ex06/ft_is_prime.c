/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:33:28 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/12 09:17:55 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	if (nb == 2)
		return (1);
	while (i <= nb / 2 + 1)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	nb;

	if (ac == 2)
	{
		nb = atoi(av[1]);
		if (ft_is_prime(nb))
			printf("%i is prime\n", nb);
		else
			printf("%i is not prime\n", nb);
	}
}
*/
