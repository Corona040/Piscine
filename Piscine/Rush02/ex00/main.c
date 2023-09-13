/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:34:38 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/11 11:26:37 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	error_msg(int derror)
{
	if (derror)
		write(1, "Dict ", 5);
	write(1, "Error\n", 6);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (is_numeric(av[1]))
			error_msg(1);
		else
			error_msg(0);
	}
	else if (ac == 3)
	{
		if (is_numeric(av[2]))
			error_msg(1);
		else
			error_msg(0);
	}
	else
		error_msg(0);
}
