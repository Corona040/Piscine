/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:23:57 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/12 09:16:56 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	bin_search(int nb)
{
	int	i;
	int	j;
	int	past;
	int	step;

	past = -1;
	j = 0;
	i = 0;
	step = nb / 2;
	while (past != i)
	{
		if (j % 3 == 0 && j > 2)
			past = i;
		if (i * i > nb || i > 46340)
			i -= step;
		else if (i * i < nb)
			i += step;
		if (step > 1)
			step /= 2;
		j++;
	}
	if (i * i == nb)
		return (i);
	else
		return (0);
}

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	else
		return (bin_search(nb));
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
		printf("sqrt(%i) = %i\n", nb, ft_sqrt(nb));
	}
}
*/
