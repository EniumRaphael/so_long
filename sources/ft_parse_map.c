/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:27:10 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/10 18:23:31 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **map, int x, int y, const char *old_value)
{
	if (x < 0 || y < 0 || x >= (int)(sizeof(map) / ft_strlen(map[0]))
		|| y >= (int)(ft_strlen(map[0])))
	{
		if (ft_index_strchr(old_value, map[x][y]) == 0)
			return ;
		map[x][y] = '.';
		flood_fill(map, x + 1, y, old_value);
		flood_fill(map, x - 1, y, old_value);
		flood_fill(map, x, y + 1, old_value);
		flood_fill(map, x, y - 1, old_value);
	}
}

void	ft_access(char **map, t_mlx *mlx, size_t i, size_t j)
{
	size_t		k;
	const char	old_value[4] = {'P', 'C', 'E', '0'};

	k = 0;
	flood_fill(map, j, i, old_value);
	while (map[k] != NULL)
	{
		if (ft_index_strchr(map[k], 'C') != 0 || \
			ft_index_strchr(map[k], 'E') != 0)
		{
			ft_free_maps(map, NULL);
			ft_exit(mlx, NULL, 1, "The map is not finishable !");
		}
		k++;
	}
}

void	ft_check_finishable(char **map, char **copy, t_mlx *mlx)
{
	size_t	j;
	size_t	i;

	j = 1;
	i = 0;
	while (map[j] && map[j][0] != '\0')
	{
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'P')
				break ;
			i++;
		}
		if (map[j][i] == 'P')
			break ;
		i = 0;
		j++;
	}
	if (map[j] && map[j][i] == 'P')
		ft_access(copy, mlx, i, j);
	else
	{
		ft_free_maps(copy, NULL);
		ft_exit(mlx, NULL, 1, "No Spawn found");
	}
}

char	ft_check_minimal(char *str, t_mlx *mlx)
{
	size_t	i;
	size_t	nb_exit;
	size_t	nb_spawn;

	i = 0;
	nb_exit = 0;
	nb_spawn = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'E')
		{
			if (nb_exit != 0)
				ft_exit(mlx, str, 1, "Too many exit are detected !");
			nb_exit++;
		}
		else if (str[i] == 'P')
		{
			if (nb_spawn != 0)
				ft_exit(mlx, str, 1, "Too many spawn are detected !");
			nb_spawn++;
		}
		i++;
	}
	return (1);
}

void	ft_parsing(char *str, t_mlx *mlx)
{
	char	**copy;

	ft_check_minimal(str, mlx);
	mlx->size_map = ft_strlen(str);
	copy = ft_strsdup(mlx->map, mlx);
	free(str);
	if (copy == NULL)
		ft_exit(mlx, NULL, 1, "The allocation of the map has crahsed !");
	ft_check_finishable(mlx->map, copy, mlx);
	ft_free_maps(copy, NULL);
}
