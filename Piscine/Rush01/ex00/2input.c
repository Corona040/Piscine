/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2input.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:48:23 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 20:55:22 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

void	smaller(int *square_small, int *square_big);
void	set_square_number(int *square, int nb);
int		get_square_id(int row, int col);

extern int	g_array[SIZE][SIZE][SIZE];

void	two_colup(int index)
{
	g_array[0][index][3] = 0;
	if (get_square_id(2, index) == 8)
	{
		smaller(g_array[1][index], g_array[0][index]);
	}
	if (get_square_id(3, index) == 8)
	{
		set_square_number(g_array[0][index], 3);
	}
}

void	two_coldown(int index)
{
	g_array[SIZE - 1][index][3] = 0;
	if (get_square_id(1, index) == 8)
	{
		smaller(g_array[2][index], g_array[3][index]);
	}
	if (get_square_id(0, index) == 8)
	{
		set_square_number(g_array[3][index], 3);
	}
}

void	two_rowleft(int index)
{
	g_array[index][0][3] = 0;
	if (get_square_id(index, 2) == 8)
	{
		smaller(g_array[index][1], g_array[index][0]);
	}
	if (get_square_id(index, 3) == 8)
	{
		set_square_number(g_array[index][0], 3);
	}
}

void	two_rowright(int index)
{
	g_array[index][SIZE - 1][3] = 0;
	if (get_square_id(index, 1) == 8)
	{
		smaller(g_array[index][2], g_array[index][3]);
	}
	if (get_square_id(index, 0) == 8)
	{
		set_square_number(g_array[index][3], 3);
	}
}

void	set_numbers_for_two(int is_row, int is_down_or_right, int index)
{
	if (is_row == 0)
	{
		if (is_down_or_right == 0)
			two_colup(index);
		else
			two_coldown(index);
	}
	else
	{
		if (is_down_or_right == 0)
			two_rowleft(index);
		else
			two_rowright(index);
	}
}
