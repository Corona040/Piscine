/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeja-ne <jbeja-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:43:09 by jbeja-ne          #+#    #+#             */
/*   Updated: 2023/09/13 10:48:07 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQLIB_H
# define BSQLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_charset
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_charset;

typedef struct s_pos
{
	int	i_row;
	int	i_col;
}	t_pos;

int		in_square(t_pos pos, t_pos sol_pos, int sol_size);
int		max_size(char **board, t_charset charset, t_pos pos, int iter);
int		check_sides(char **board, t_charset charset, t_pos pos, int iter);
int		can_start(char **board, t_charset charset, t_pos pos);
void	solve_game(char **board, t_charset charset);
int		get_solution(char **board, t_charset charset, t_pos *sol_pos);
void	put_sol(char **board, t_charset charset, t_pos sol_pos, int sol_size);
int		count_obstacles(char *str, char obstacle);
int		**get_obstacles_index(char **strs, char obstacle, int obstacle_count);
int		ft_strlen(char *str);
void	ft_strcat(char *dest, char *src);
char	*realloc_str(char *str);
char	*read_map(const char *map_path, int std_in);
int		get_rows(char *str, int digits_nbr);
int		get_charset(t_charset *charset, char *str);
int		get_cols(char *str, char sep);
void	cpy_to_sep(char *dest, char *src, char sep);
char	**split(int line_count, char *str, char sep);
int		error_msg(void);
int		check_strs(char **strs);
int		check_obstacles(char *str, char obstacle);
int		check_row_count(char *str, t_charset charset);
int		is_printable(char c);
int		is_digit(char c);
int		check_charset_count(char *str);
int		check_charset_chars(t_charset charset);
int		ultimate_check(char **strs, char *str, char *str2, t_charset charset);
int		init(char *mapfile_path, char ***strs, t_charset *charset, int std_in);

#endif
