/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:01:56 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 21:04:53 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

extern int	g_array[SIZE][SIZE][SIZE];

void	remove_number(int line, int col)
{
	int	nb_pos;
	int	i;

	nb_pos = 0;
	while (g_array[line][col][nb_pos] != 1)
		nb_pos++;
	i = 0;
	while (i < SIZE)
	{
		if (i != col)
			g_array[line][i][nb_pos] = 0;
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (i != line)
			g_array[i][col][nb_pos] = 0;
		i++;
	}
}

void	remove_2_number_row(int line, int line2, int col)
{
	int	k;
	int	i;
	int	nb_pos1;
	int	nb_pos2;

	nb_pos1 = 0;
	k = 0;
	while (k < SIZE)
	{
		if (g_array[line][col][k] == 1 && !nb_pos1)
			nb_pos1 = k;
		else if (g_array[line][col][k] == 1)
			nb_pos2 = k;
		k++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (i != line && i != line2)
		{
			g_array[i][col][nb_pos1] = 0;
			g_array[i][col][nb_pos2] = 0;
		}
		i++;
	}
}

void	remove_2_number_col(int col, int col2, int line)
{
	int	k;
	int	j;
	int	nb_pos1;
	int	nb_pos2;

	nb_pos1 = 0;
	k = 0;
	while (k < SIZE)
	{
		if (g_array[line][col][k] == 1 && !nb_pos1)
			nb_pos1 = k;
		else if (g_array[line][col][k] == 1)
			nb_pos2 = k;
		k++;
	}
	j = 0;
	while (j < SIZE)
	{
		if (j != col && j != col2)
		{
			g_array[line][j][nb_pos1] = 0;
			g_array[line][j][nb_pos2] = 0;
		}
		j++;
	}
}
