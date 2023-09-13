/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:02:41 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 21:41:40 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 4

int	g_input[16];
int	g_array[SIZE][SIZE][SIZE];

int		power(int base, int power);
void	put_char(char c);
int		square_min(int *square);
void	smaller(int *square_smaller, int *square_bigger);
int		get_square_id(int row, int col);
void	set_square_number(int *square, int nb);
void	set_numbers_for_four(int is_row, int is_down_or_right, int index);
void	set_numbers_for_one(int is_row, int is_down_or_right, int index);
void	set_numbers_for_two(int is_row, int is_down_or_right, int index);
void	set_numbers_for_three(int is_row, int is_down_or_right, int index);
void	remove_number(int line, int col);
void	remove_2_number_row(int line, int line2, int col);
void	remove_2_number_col(int col, int col2, int line);
int		get_square_nb(int *square);
void	get_input(char **av);
void	init_table(void);
void	process_input(void);
void	norepeat_one(void);
void	draw_table(void);
int		check_input(char **av);
void	error_msg(void);

int	main(int ac, char **av)
{
	int	limit;

	limit = 0;
	if (ac == 2)
	{
		if (check_input(av))
		{
			get_input(av);
			init_table();
			while (limit < 5)
			{
				process_input();
				norepeat_one();
				limit++;
			}
			draw_table();
		}
		else
			error_msg();
	}
	else
		error_msg();
}
