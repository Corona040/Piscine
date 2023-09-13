/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeja-ne <jbeja-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:24:43 by jbeja-ne          #+#    #+#             */
/*   Updated: 2023/09/12 10:24:43 by jbeja-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQlib.h"

void	solve_game(char **board, t_charset charset)
{
	int		sol_size;
	t_pos	sol_pos;

	sol_pos.i_row = -1;
	sol_pos.i_col = -1;
	sol_size = get_solution(board, charset, &sol_pos);
	put_sol(board, charset, sol_pos, sol_size);
}

int	get_solution(char **board, t_charset charset, t_pos *sol_pos)
{
	t_pos	pos;
	int		sol_size;
	int		size;

	sol_size = 0;
	pos.i_row = -1;
	while (++pos.i_row < charset.rows - sol_size)
	{
		pos.i_col = -1;
		while (++pos.i_col < charset.cols)
		{
			if ((board[pos.i_row][pos.i_col] != charset.obstacle)
				&& (can_start(board, charset, pos) == 2))
			{
				size = max_size(board, charset, pos, 0);
				if (size > sol_size)
				{
					sol_size = size;
					sol_pos->i_row = pos.i_row;
					sol_pos->i_col = pos.i_col; 
				}
			}
		}
	}
	return (sol_size);
}

void	put_sol(char **board, t_charset charset, t_pos sol_pos, int sol_size)
{
	t_pos	pos;

	pos.i_row = 0;
	while (pos.i_row < charset.rows)
	{
		pos.i_col = 0;
		while (pos.i_col < charset.cols)
		{
			if (in_square(pos, sol_pos, sol_size))
				write(1, &charset.full, 1);
			else
				write(1, &board[pos.i_row][pos.i_col], 1);
			pos.i_col++;
		}
		write(1, "\n", 1);
		pos.i_row++;
	}
}
