/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:56:35 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/12 09:11:00 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 1)
	{
		nb *= ft_recursive_factorial(nb - 1);
	}
	else if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	return (nb);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%i! = %i\n", atoi(av[1]), ft_recursive_factorial(atoi(av[1])));
}
*/
