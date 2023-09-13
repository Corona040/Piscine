/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4input.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:36:00 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 20:43:51 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

extern int	g_input[16];
extern int	g_array[SIZE][SIZE][SIZE];

int		power(int base, int power);
void	put_char(char c);
int		square_min(int *square);
void	smaller(int *square_smaller, int *square_bigger);
int		get_square_id(int row, int col);
void	set_square_number(int *square, int nb);

void	four_colup(int index)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		set_square_number(g_array[i][index], i + 1);
		i++;
	}
}

void	four_coldown(int index)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		set_square_number(g_array[i][index], SIZE - i);
		i++;
	}
}

void	four_rowleft(int index)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		set_square_number(g_array[index][i], i + 1);
		i++;
	}
}

void	four_rowright(int index)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		set_square_number(g_array[index][i], SIZE - i);
		i++;
	}
}

void	set_numbers_for_four(int is_row, int is_down_or_right, int index)
{
	if (is_row == 0)
	{
		if (is_down_or_right == 0)
			four_colup(index);
		else
			four_coldown(index);
	}
	else
	{
		if (is_down_or_right == 0)
			four_rowleft(index);
		else
			four_rowright(index);
	}
}
