/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:21:47 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 16:19:35 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) != '\0' || *(s2 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (0);
}

void	ft_sort_params(int ac, char **av)
{
	char	*hold;
	int		i;
	int		cmp;

	i = 1;
	cmp = 0;
	while (i < ac - 1)
	{
		cmp = ft_strcmp(*(av + i), *(av + i - 1));
		if (cmp < 0)
		{
			hold = *(av + i);
			*(av + i) = *(av + i - 1);
			*(av + i - 1) = hold;
			ft_sort_params(ac, av);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	ft_sort_params(ac, av + 1);
	i = 1;
	while (i < ac)
	{
		ft_putstr(*(av + i));
		i++;
	}
}
