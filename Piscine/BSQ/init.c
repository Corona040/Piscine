/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:31:47 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/13 10:50:09 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQlib.h"

int	init(char *mapfile_path, char ***strs, t_charset *charset, int std_in)
{
	int		i;
	char	*full_str;
	char	*map_str;

	if (std_in)
		full_str = read_map(mapfile_path, 1);
	else
		full_str = read_map(mapfile_path, 0);
	if (get_charset(charset, full_str) == 0)
	{
		i = 0;
		while (full_str[i] != '\n' && full_str[i])
			i++;
		map_str = full_str + i + 1;
		*strs = split(charset->rows, map_str, '\n');
		if (ultimate_check(*strs, map_str, full_str, *charset) != 0)
			return (error_msg());
		else
			return (0);
	}
	else
		return (error_msg());
}
