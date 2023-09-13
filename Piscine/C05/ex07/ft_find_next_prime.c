/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:46:13 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/12 09:19:22 by ecorona-         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (nb < 2)
		return (2);
	if (ft_is_prime(i))
		return (i);
	if (i % 2 == 0)
		i++;
	while (!(ft_is_prime(i)))
		i += 2;
	return (i);
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
		printf("next prime is %i\n", ft_find_next_prime(nb));
	}
}
*/
