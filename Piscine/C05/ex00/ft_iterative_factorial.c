/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:45:04 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/12 09:10:29 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb > 0)
	{
		i = nb;
		while (i > 1)
		{
			nb *= i - 1;
			i--;
		}
		return (nb);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%i! = %i\n", atoi(av[1]), ft_iterative_factorial(atoi(av[1])));
}
*/
