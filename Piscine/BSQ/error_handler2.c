/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:10:05 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/13 10:31:39 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQlib.h"

int	check_charset_count(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
		return (-1);
	if (str[i] == '\n')
		i--;
	j = 0;
	while (j < 3)
	{
		if (!is_printable(str[i - j++]))
			return (-1);
	}
	while (j <= i)
	{
		if (!is_digit(str[i - j++]))
			return (-1);
	}
	if (j < 4)
		return (-1);
	return (0);
}

int	check_charset_chars(t_charset charset)
{
	if (charset.empty == charset.obstacle || charset.empty == charset.full)
		return (-1);
	if (charset.obstacle == charset.full)
		return (-1);
	return (0);
}

int	ultimate_check(char **strs, char *mapstr, char *fullstr, t_charset charset)
{
	int	check;

	check = 0;
	check += check_strs(strs);
	check += check_obstacles(mapstr, charset.obstacle);
	check += check_row_count(mapstr, charset);
	check += check_charset_count(fullstr);
	check += check_charset_chars(charset);
	if (check != 0)
		return (-1);
	return (0);
}
