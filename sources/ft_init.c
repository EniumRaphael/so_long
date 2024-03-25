/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:25:35 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/17 00:16:49 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_init_image(t_mlx *mlx)
{
	mlx->store.wall = load_image(mlx, "./textures/wall.xpm");
	mlx->store.floor = load_image(mlx, "./textures/floor.xpm");
	mlx->store.coins = load_image(mlx, "./textures/coins.xpm");
	mlx->store.player = load_image(mlx, "./textures/steve.xpm");
	mlx->store.lock = load_image(mlx, "./textures/exit_close.xpm");
	mlx->store.open = load_image(mlx, "./textures/exit_open.xpm");
	if (mlx->store.wall.img_ptr == NULL || mlx->store.floor.img_ptr == NULL \
	|| mlx->store.coins.img_ptr == NULL || mlx->store.player.img_ptr == NULL \
	|| mlx->store.lock.img_ptr == NULL || mlx->store.open.img_ptr == NULL)
		return (1);
	return (0);
}

t_mlx	*ft_init_mlx(t_mlx *mlx, int argc, char *argv[])
{
	mlx->init = mlx_init();
	if (!mlx->init)
		ft_exit(mlx, NULL, 1, "The allocation of mlx has crashed");
	ft_init_map(mlx, argv[1]);
	check_args(argc, argv, mlx);
	map_size(mlx);
	mlx->window = mlx_new_window(mlx->init, mlx->map_l, mlx->map_h, \
	"so_long by rparodi");
	if (!mlx->window)
		ft_exit(mlx, NULL, 1, "The allocation of the window has crashed");
	if (ft_init_image(mlx))
		ft_exit(mlx, NULL, 1, "The allocation of the window has crashed");
	display_map(mlx);
	mlx_hook(mlx->window, 2, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->window, 17, 1L << 17, ft_close, mlx);
	mlx_loop(mlx->init);
	return (mlx);
}

void	display_map(t_mlx *mlx)
{
	t_image	image;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < mlx->map_h && mlx->map[j])
	{
		while (i + 1 < mlx->map_l && mlx->map[j][i] != '\0'\
			&& mlx->map[j][i] != '\n')
		{
			image = ft_whitch_case(mlx->map[j][i], mlx);
			mlx_put_image_to_window(mlx->init, mlx->window, image.img_ptr, \
				i * image.w, j * image.h);
			i++;
		}
		i = 0;
		j++;
	}
}

t_image	new_img(int w, int h, t_mlx *mlx)
{
	t_image	image;

	image.img_ptr = mlx_new_image(mlx->init, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

t_image	load_image(t_mlx *mlx, char *path)
{
	t_image	img;
	int		width;
	int		height;

	width = LONGUEUR / mlx->map_l;
	height = HAUTEUR / mlx->map_h;
	img.img_ptr = mlx_xpm_file_to_image(mlx->init, path, &width, &height);
	if (img.img_ptr == NULL)
		ft_exit(mlx, NULL, 1, "The allocation of the image has crashed");
	img.addr = mlx_get_data_addr(img.img_ptr, &(img.bpp), &(img.line_len),
			&(img.endian));
	img.w = width;
	img.h = height;
	return (img);
}
