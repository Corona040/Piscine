/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3input.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:55:41 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 21:01:01 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

void	smaller(int *square_small, int *square_big);
int		get_square_id(int row, int col);

extern int	g_array[SIZE][SIZE][SIZE];

void	three_colup(int index)
{
	g_array[0][index][3] = 0;
	g_array[0][index][2] = 0;
	g_array[1][index][3] = 0;
	if (get_square_id(2, index) == 8)
	{
		smaller(g_array[0][index], g_array[1][index]);
	}
	if (get_square_id(3, index) == 8 && get_square_id(2, index) == 4)
	{
		smaller(g_array[1][index], g_array[0][index]);
	}
}

void	three_coldown(int index)
{
	g_array[SIZE - 1][index][3] = 0;
	g_array[SIZE - 1][index][2] = 0;
	g_array[SIZE - 2][index][3] = 0;
	if (get_square_id(1, index) == 8)
	{
		smaller(g_array[3][index], g_array[2][index]);
	}
	if (get_square_id(0, index) == 8 && get_square_id(1, index) == 4)
	{
		smaller(g_array[2][index], g_array[3][index]);
	}
}

void	three_rowleft(int index)
{
	g_array[index][0][3] = 0;
	g_array[index][0][2] = 0;
	g_array[index][1][3] = 0;
	if (get_square_id(index, 2) == 8)
	{
		smaller(g_array[index][0], g_array[index][1]);
	}
	if (get_square_id(index, 3) == 8 && get_square_id(index, 2) == 4)
	{
		smaller(g_array[index][1], g_array[index][0]);
	}
}

void	three_rowright(int index)
{
	g_array[index][SIZE - 1][3] = 0;
	g_array[index][SIZE - 1][2] = 0;
	g_array[index][SIZE - 2][3] = 0;
	if (get_square_id(index, 1) == 8)
	{
		smaller(g_array[index][3], g_array[index][2]);
	}
	if (get_square_id(index, 0) == 8 && get_square_id(index, 1) == 4)
	{
		smaller(g_array[index][2], g_array[index][3]);
	}
}

void	set_numbers_for_three(int is_row, int is_down_or_right, int index)
{
	if (is_row == 0)
	{
		if (is_down_or_right == 0)
			three_colup(index);
		else
			three_coldown(index);
	}
	else
	{
		if (is_down_or_right == 0)
			three_rowleft(index);
		else
			three_rowright(index);
	}
}
