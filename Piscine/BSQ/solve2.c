/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeja-ne <jbeja-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:04:40 by jbeja-ne          #+#    #+#             */
/*   Updated: 2023/09/13 10:58:26 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQlib.h"

int	in_square(t_pos pos, t_pos sol_pos, int sol_size)
{
	if (pos.i_row >= sol_pos.i_row && pos.i_col >= sol_pos.i_col)
	{
		if (pos.i_row <= (sol_pos.i_row + sol_size - 1)
			&& pos.i_col <= (sol_pos.i_col + sol_size - 1))
			return (1);
	}
	return (0);
}

int	max_size(char **board, t_charset charset, t_pos pos, int iter)
{
	int	m_size;

	m_size = 0;
	if (board[pos.i_row + iter][pos.i_col + iter] != charset.obstacle)
	{
		if (check_sides(board, charset, pos, iter))
		{
			++m_size;
			if ((pos.i_row + iter < charset.rows - 1)
				&& (pos.i_col + iter < charset.cols - 1))
				m_size += max_size(board, charset, pos, iter + 1);
		}
	}
	return (m_size);
}

int	check_sides(char **board, t_charset charset, t_pos pos, int iter)
{
	int	c;
	int	l;

	c = -1;
	while (++c < iter)
	{
		if (board[pos.i_row + iter][pos.i_col + c] == charset.obstacle)
			return (0);
	}
	l = -1;
	while (++l < iter)
	{
		if (board[pos.i_row + l][pos.i_col + iter] == charset.obstacle)
			return (0);
	}
	return (1);
}

int	can_start(char **board, t_charset charset, t_pos pos)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	if (pos.i_row == 0)
		++start;
	else
	{
		while (i < charset.cols && board[pos.i_row - 1][i] != charset.obstacle)
			++i;
		if (i != charset.cols)
			++start;
	}
	i = 0;
	if (pos.i_col == 0)
		++start;
	else
	{
		while (i < charset.rows && board[i][pos.i_col - 1] != charset.obstacle)
			++i;
		if (i != charset.rows)
			++start;
	}
	return (start);
}
