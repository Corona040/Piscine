/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeja-ne <jbeja-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:17:09 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/13 10:19:20 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQlib.h"

//	Returns length of string from address str until character sep
int	get_cols(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != sep && str[i])
		i++;
	return (i);
}

// Copies from address src to address dest until a sep
// then NULL terminates dest
void	cpy_to_sep(char *dest, char *src, char sep)
{
	while (*src != sep && *src)
		*dest++ = *src++;
	*dest = '\0';
}

// Count number of obstacles on map string (single string, not array of strings)
// obstacle could be any character and is passed as an arguments
// str argument is the map string
int	count_obstacles(char *str, char obstacle)
{
	int	count;

	count = 0;
	while (*str)
		if (*str++ == obstacle)
			count++;
	return (count);
}

// This functions reads 'digits_nbr' chars from the first line from map file
// It implements a simple atoi to transform the written number to an integers
int	get_rows(char *str, int digits_nbr)
{
	int	i;
	int	rows;

	rows = 0;
	i = 0;
	while (i < digits_nbr)
		rows = rows * 10 + str[i++] - '0';
	return (rows);
}
