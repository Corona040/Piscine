/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:15:35 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 21:42:12 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

extern int	g_input[16];

void	set_numbers_for_four(int is_row, int is_down_or_right, int index);
void	set_numbers_for_three(int is_row, int is_down_or_right, int index);
void	set_numbers_for_two(int is_row, int is_down_or_right, int index);
void	set_numbers_for_one(int is_row, int is_down_or_right, int index);

int	check_input(char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '\0')
	{
		if ((i % 2 == 0) && (av[1][i] < '1' || av[1][i] > '4'))
			return (0);
		if ((i % 2 == 1) && (av[1][i] != ' '))
			return (0);
		if (i >= 16)
			return (0);
		i++;
	}
	return (1);
}

void	process_input(void)
{
	int	i;
	int	is_row;
	int	is_down_or_right;
	int	index;

	i = 0;
	while (i < SIZE * SIZE)
	{
		is_row = i / (SIZE * 2);
		is_down_or_right = (i / SIZE) % 2;
		index = i % SIZE;
		if (g_input[i] == 4)
			set_numbers_for_four(is_row, is_down_or_right, index);
		if (g_input[i] == 1)
			set_numbers_for_one(is_row, is_down_or_right, index);
		if (g_input[i] == 2)
			set_numbers_for_two(is_row, is_down_or_right, index);
		if (g_input[i] == 3)
			set_numbers_for_three(is_row, is_down_or_right, index);
		i++;
	}
}
