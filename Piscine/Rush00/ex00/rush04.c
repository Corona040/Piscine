/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:32:05 by ecorona-          #+#    #+#             */
/*   Updated: 2023/08/27 19:32:10 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	draw_corner_char(int line, int col, int last_line, int last_col);
void	draw_side_char(int line, int col, int last_line, int last_col);
int		find_location(int line, int col, int last_line, int last_col);

// last_line = y - 1
// last_col = x - 1
void	rush(int x, int y)
{
	int	line;
	int	col;
	int	location;

	line = 0;
	while (line <= y - 1)
	{
		col = 0;
		while (col <= x - 1)
		{
			location = find_location(line, col, y - 1, x - 1);
			if (location == 1)
				draw_corner_char(line, col, y - 1, x - 1);
			if (location == 2)
				draw_side_char(line, col, y - 1, x - 1);
			if (location == 0)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}

// if corner 	-> return (1)
// if side 		-> return (2)
// if middle 	-> return (0)
int	find_location(int line, int col, int last_line, int last_col)
{
	if ((line == 0 || line == last_line) && (col == 0 || col == last_col))
		return (1);
	else if (line == 0 || line == last_line || col == 0 || col == last_col)
		return (2);
	else
		return (0);
}

// (line == 0 && col == 0) 					-> upper	left	corner
// (line == 0 && col == last_col) 			-> upper	right	corner
// (line == last_line && col == 0) 			-> lower	left	corner
// (line == last_line && col == last_col) 	-> lower	right	corner
void	draw_corner_char(int line, int col, int last_line, int last_col)
{
	if (line == 0 && col == 0)
		ft_putchar('A');
	if (line == 0 && col == last_col)
		ft_putchar('C');
	if (line == last_line && col == 0)
		ft_putchar('C');
	if (line == last_line && col == last_col)
		ft_putchar('A');
}

// (line == 0) 			-> upper	side
// (line == last_line) 	-> lower	side
// (col == 0) 			-> left		side
// (col == last_col) 	-> right	side
void	draw_side_char(int line, int col, int last_line, int last_col)
{
	if (line == 0)
		ft_putchar('B');
	if (line == last_line)
		ft_putchar('B');
	if (col == 0)
		ft_putchar('B');
	if (col == last_col)
		ft_putchar('B');
}
