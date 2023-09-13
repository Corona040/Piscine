/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:25:27 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 21:28:28 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int		get_square_nb(int *square);
void	put_char(char c);

extern int	g_array[SIZE][SIZE][SIZE];

void	draw_table(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			k = get_square_nb(g_array[i][j]);
			put_char(k + '0');
			put_char(' ');
			j++;
		}
		put_char('\n');
		i++;
	}
}
