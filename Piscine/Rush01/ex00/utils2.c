/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:34:24 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 21:41:09 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

void put_char(char c);

void	set_square_number(int *square, int nb)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != nb - 1)
			square[i] = 0;
		i++;
	}
}

int	get_square_nb(int *square)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (square[i] == 1)
			return (i + 1);
		i++;
	}
	return ('9' - '0');
}

void error_msg(void)
{
	char *str = "Error\n";
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		put_char(str[i]);
		i++;
	}
}
