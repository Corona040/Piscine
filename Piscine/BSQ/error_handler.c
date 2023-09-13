/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:10:05 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/13 10:39:43 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQlib.h"

int	error_msg(void)
{
	write(1, "map error\n", 10);
	return (-1);
}

int	check_strs(char **strs)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(strs[i]);
	while (strs[i] != 0)
	{
		if (len != ft_strlen(strs[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	check_obstacles(char *str, char obstacle)
{
	if (count_obstacles(str, obstacle) <= 0)
		return (-1);
	else
		return (0);
}

int	check_row_count(char *str, t_charset charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			count++;
		}
		i++;
	}
	if (count != charset.rows)
		return (-1);
	return (0);
}
