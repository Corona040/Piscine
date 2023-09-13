/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:14 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/02 17:17:48 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long int	power(int base, int power)
{
	int					i;
	unsigned long int	result;

	result = 1;
	i = 0;
	while (i < power)
	{
		result *= base;
		i++;
	}
	return (result);
}

void	write_hex(unsigned long int nbr, int size)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = size * 2 - 1;
	while (i >= 0)
	{
		write(1, &hex[(int)(nbr / power(16, i))], 1);
		nbr %= power(16, i);
		i--;
	}
}

void	write_string_hex(char *string)
{
	unsigned int	i;

	i = 0;
	while (*(string + i) != '\0' && i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write_hex(*(string + i), 1);
		i++;
	}
	if (*(string + i) == '\0')
		write_hex('\0', 1);
	while (i < 15)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
	write(1, " ", 1);
}

void	write_string(char *string, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*(string + i) != '\0' && i < 16 && i < size)
	{
		if (*(string + i) < 32 || *(string + i) > 126)
			write(1, ".", 1);
		else
			write(1, string + i, 1);
		i++;
	}
	if (*(string + i) == '\0')
		write(1, ".", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*string;
	unsigned int	i;

	if (size == 0)
		return (addr);
	else
	{
		string = addr;
		i = 0;
		while (i < size && *(string + i) != '\0')
		{
			if (i % 16 == 0)
			{
				write_hex((unsigned long int) string + i, 8);
				write(1, ":", 1);
				write_string_hex(string + i);
				write_string(string + i, size - 16 * i);
				write(1, "\n", 1);
			}
			i++;
		}
		return (addr);
	}
}

int	main(void)
{
	void *string;

	string = "aagkh ahgkasgjghajgsdf asgkjgfjkaw jkgaj gj ag awevka\nWYJEFRJYAEGR ASJVGHWJEAAV\tn\t\rarghkhfgakhJHGAFHgsfghksjdgfJHKGDF";
	ft_print_memory(string, 200);
}
