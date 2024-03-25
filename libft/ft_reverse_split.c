/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:33 by rparodi           #+#    #+#             */
/*   Updated: 2024/03/10 18:28:07 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_count_line(char *path)
{
	char		*str;
	size_t		count;
	int			fd;

	count = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		count++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (count);
}

char	**ft_init_map(t_mlx *mlx, char *path)
{
	int		check;
	size_t	total_size;
	size_t	j;

	j = 0;
	check = 1;
	total_size = ft_count_line(path);
	if (mlx->map != NULL)
		ft_free_maps(mlx->map, NULL);
	mlx->map = (char **)malloc(sizeof(char *) * (total_size + 1));
	if (!mlx->map)
		ft_exit(mlx, NULL, 0, "The allocation of the map crashed");
	while (check != 0 && mlx->map != NULL)
	{
		mlx->map[j] = get_next_line(mlx->fd_map);
		if (mlx->map[j] == NULL)
			check = 0;
		j++;
	}
	return (mlx->map);
}

size_t	ft_strslen(char **strs)
{
	size_t	counter;
	size_t	i;
	size_t	j;

	counter = 0;
	i = 0;
	j = 0;
	while (strs[j] != NULL)
	{
		while (strs[j][i] != '\0')
		{
			counter++;
			i++;
		}
		i = 0;
		j++;
	}
	return (counter);
}

char	*ft_convert_strs_to_str(char *str, char **strs)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (strs[j] != NULL)
	{
		while (strs[j][i] != '\0')
		{
			str[k] = strs[j][i];
			i++;
			k++;
		}
		i = 0;
		j++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_reverse_split(t_mlx *mlx)
{
	const size_t	total_size = ft_strslen(mlx->map);
	char			*str;

	str = (char *)malloc(total_size + 1);
	if (str == NULL)
		ft_exit(mlx, NULL, 0, "The allocation of the string crashed");
	return (ft_convert_strs_to_str(str, mlx->map));
}
