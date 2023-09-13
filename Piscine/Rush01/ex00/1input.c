/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1input.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:44:33 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 21:32:32 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

void	set_square_number(int *square, int nb);

extern int	g_array[SIZE][SIZE][SIZE];

void	set_numbers_for_one(int is_row, int is_down_or_right, int index)
{
	if (is_row == 0)
	{
		if (is_down_or_right == 0)
			set_square_number(g_array[0][index], 4);
		else
			set_square_number(g_array[SIZE - 1][index], 4);
	}
	else
	{
		if (is_down_or_right == 0)
			set_square_number(g_array[index][0], 4);
		else
			set_square_number(g_array[index][SIZE - 1], 4);
	}
}
