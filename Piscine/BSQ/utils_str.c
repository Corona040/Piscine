/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:03:56 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/13 10:17:48 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQlib.h"

// Returns lenth of string str
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Concatenates string src to string dest, then NULL terminates dest
void	ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

// Reallocs str to a new address with a buffer with 2 more bytes
// (for a new char and the NULL byte)
char	*realloc_str(char *str)
{
	char	*restr;

	restr = malloc(ft_strlen(str) + 2);
	ft_strcat(restr, str);
	return (restr);
}

// Check if char is printable
int	is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

// Check if char is digit
int	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
