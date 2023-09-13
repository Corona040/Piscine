/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:22:46 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 19:13:45 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcat(char *dest, char *src)
{
	int	i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + j);
}

int	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

char	*realloc_str(char *str, int size)
{
	char	*str2;
	int		old_size;

	old_size = ft_strlen(str);
	str2 = malloc((old_size + size) * sizeof(char));
	ft_strcat(str2, str);
	free(str);
	return (str2);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		str_len;
	char	*str;

	if (size > 0)
	{
		str = "\0";
		i = 0;
		while (i < size)
		{
			str_len = ft_strlen(strs[i]);
			str = realloc_str(str, str_len);
			ft_strcat(str, strs[i]);
			if (i != size - 1)
				ft_strcat(str, sep);
			i++;
		}
		return (str);
	}
	else
		return("");
}

/*
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("%s\n", ft_strjoin(ac, av, ";"));
	printf("%s\n", ft_strjoin(0, av, "'"));
}
*/
