/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:12:28 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/13 11:12:10 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQlib.h"

/*
   From a string str, with a given linecount and sep character
   creates an array of strings
   stripped at sep chararacter
*/
char	**split(int line_count, char *str, char sep)
{
	int		i;
	int		len;
	char	**strs;

	strs = malloc(line_count * sizeof(char *) + 1);
	if (!strs)
		return (0);
	len = get_cols(str, sep);
	i = 0;
	while (i < line_count)
	{
		strs[i] = malloc(len + 1);
		if (!strs[i])
			return (0);
		cpy_to_sep(strs[i], str, sep);
		str += len + 1;
		i++;
	}
	strs[i] = 0;
	return (strs);
}

/*
   Uses open and read functions to read map file
   map_path is the string with the path of map file
   Returns a string with the total content of map file
*/
char	*read_map(const char *map_path, int std_in)
{
	int		fd;
	char	*str_temp;
	char	*str_map;

	if (std_in)
		fd = 0;
	else
		fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	str_temp = malloc(1);
	str_map = malloc(1);
	while (read(fd, str_temp, 1))
	{
		str_map = realloc_str(str_map);
		ft_strcat(str_map, str_temp);
	}
	if (read(fd, str_temp, 1) == -1)
	{
		return (0);
	}
	free(str_temp);
	close(fd);
	return (str_map);
}

/*
	This function reads the first line from the map file
	and saves the number of line (rows) by calling the get_rows function
	and the charset for empty, obstacle and full
	it also calls the get_cols functions to save the columns length (cols)
*/
int	get_charset(t_charset *charset, char *str)
{
	int			i;

	if (check_charset_count(str) == -1)
		return (-1);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
		return (-1);
	if (str[i] == '\n')
		i--;
	charset->full = str[i--];
	charset->obstacle = str[i--];
	charset->empty = str[i];
	charset->rows = get_rows(str, i);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
		return (-1);
	if (str[i] == '\n')
		i++;
	charset->cols = get_cols(str + i, '\n');
	return (0);
}
