/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:54 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/07 11:08:43 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

# define HAUTEUR 1920
# define LONGUEUR 1080

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_img_store
{
	t_image	wall;
	t_image	floor;
	t_image	lock;
	t_image	open;
	t_image	player;
	t_image	coins;
}				t_img_store;

typedef struct s_mlx
{
	void			*init;
	void			*window;
	int				w_h;
	int				w_l;
	int				fd_map;
	size_t			size_map;
	char			**map;
	size_t			map_h;
	size_t			map_l;
	t_image			*img;
	unsigned int	count;
	char			*path;
	t_img_store		store;
}					t_mlx;

char			*ft_get_line(char *str);
char			*get_next_line(int fd);
char			*ft_get_next(char *str);
int				ft_index_strchr(const char *s, char c);
char			**ft_strsdup(char **s, t_mlx *mlx);
char			*ft_get_line(char	*str);
char			*ft_strjoin(char *s1, char *s2, int i, int j);
char			*file_converted(int fd);
char			*ft_free(char *str);
char			*ft_check(char *memory, int fd);
size_t			ft_count_line(char *path);
int				ft_printf(const char *str, ...);
int				ft_check_args(char c, va_list args, int *ret_value);
void			ft_putnbr_unsigned(unsigned int nb, int *ret_value);
void			ft_putnbr(int nb, int *ret_value);
void			ft_putchar(char c, int *ret_value);
void			ft_putstr(char *str, int *ret_value);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
size_t			what_is_it(char *str, size_t i, size_t line, t_mlx *mlx);
char			**ft_split(char const *s, char c);
int				check_border(char *str, t_mlx *mlx);
char			*size_file(t_mlx *mlx);
size_t			ft_linelen(t_mlx *mlx);
void			check_args(int argc, char *argv[], t_mlx *mlx);
void			ft_exit(t_mlx *mlx, void *p2, short int exit_status,
					char *error_msg);
t_image			new_img(int w, int h, t_mlx *mlx);
void			ft_parsing(char *str, t_mlx *mlx);
char			*ft_strdup(const char *s);
int				ft_close(t_mlx *mlx);
char			ft_strchr(const char *s, int c);
void			ft_free_maps(char **strs, char **copy);
int				key_hook(int keycode, t_mlx *mlx);
t_image			load_image(t_mlx *mlx, char *path);
t_mlx			*ft_init_mlx(t_mlx *mlx, int argc, char **argv);
int				main(int argc, char *argv[]);
void			map_size(t_mlx *mlx);
t_image			ft_whitch_case(char c, t_mlx *mlx);
char			**ft_init_map(t_mlx *mlx, char *path);
size_t			ft_strslen(char **strs);
char			*ft_convert_strs_to_str(char *str, char **strs);
char			*ft_reverse_split(t_mlx *mlx);
void			ft_move_up(int x, int y, t_mlx *mlx, unsigned int *count);
void			ft_move_down(int x, int y, t_mlx *mlx, unsigned int *count);
void			ft_move_left(int x, int y, t_mlx *mlx, unsigned int *count);
void			ft_move_right(int x, int y, t_mlx *mlx, unsigned int *count);
void			ft_check_end(t_mlx *mlx, unsigned int coins);
void			display_map(t_mlx *mlx);
void			ft_free_image(t_mlx *mlx);
void			ft_init_value_mlx(t_mlx *mlx);
unsigned int	count_coins(t_mlx *mlx);
void			ft_putnbr_base(unsigned long long nbr, char *base,
					int *ret_value, char c);

#endif
