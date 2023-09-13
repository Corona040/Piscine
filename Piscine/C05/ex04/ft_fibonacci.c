/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:15:00 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/12 09:14:13 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	result;

	result = 0;
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
	{
		result += ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (result);
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	index;

	if (ac == 2)
	{
		index = atoi(av[1]);
		printf("fib[%i] = %i\n", index, ft_fibonacci(index));
	}
}
*/
