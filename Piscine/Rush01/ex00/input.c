/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:08:27 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 21:14:51 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

extern int	g_input[16];
extern int	g_array[SIZE][SIZE][SIZE];

void	get_input(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[1][i] != '\0')
	{
		if (av[1][i] >= '1' && av[1][i] <= '4')
		{
			g_input[j] = av[1][i] - '0';
			j++;
		}
		i++;
	}
}

void	init_table(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			k = 0;
			while (k < SIZE)
			{
				g_array[i][j][k] = 1;
				k++;
			}
			j++;
		}
		i++;
	}
}
