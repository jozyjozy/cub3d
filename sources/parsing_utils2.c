/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:04:04 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/21 07:43:25 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	error_double(t_double d)
{
	if (d.no != 1)
		printf("Error\nNeed ONE texture for North\n");
	if (d.so != 1)
		printf("Error\nNeed ONE texture for South\n");
	if (d.we != 1)
		printf("Error\nNeed ONE texture for West\n");
	if (d.ea != 1)
		printf("Error\nNeed ONE texture for EAST\n");
	if (d.fl != 1)
		printf("Error\nNeed ONE RGB for floor\n");
	if (d.ce != 1)
		printf("Error\nNeed ONE RGB for floor\n");
	if (d.no != 1 || d.we != 1 || d.so != 1
		|| d.ea != 1 || d.fl != 1 || d.ce != 1)
		return (TRUE);
	return (FALSE);
}

t_double	set_zero_double(void)
{
	t_double	d;

	d.so = 0;
	d.no = 0;
	d.we = 0;
	d.ea = 0;
	d.ce = 0;
	d.fl = 0;
	return (d);
}

void	do_wh_map(t_data *data)
{
	int	w;
	int	h;
	int	max;

	max = 0;
	h = 0;
	while (data->map[h])
	{
		w = 0;
		while (data->map[h][w])
			w++;
		if (w > max)
			max = w;
		h++;
	}
	data->w_map = max;
	data->h_map = h;
}

bool	check_double(t_data *data)
{
	int			i;
	t_double	d;

	i = 0;
	d = set_zero_double();
	while (data->file[i])
	{
		if (ft_strcmp(data->file[i], "NO "))
			d.no++;
		else if (ft_strcmp(data->file[i], "SO "))
			d.so++;
		else if (ft_strcmp(data->file[i], "WE "))
			d.we++;
		else if (ft_strcmp(data->file[i], "EA "))
			d.ea++;
		else if (ft_strcmp(data->file[i], "F "))
			d.fl++;
		else if (ft_strcmp(data->file[i], "C "))
			d.ce++;
		i++;
	}
	return (error_double(d));
}

char	**get_file(int fd, int nbl)
{
	int		i;
	char	**final;

	i = 0;
	final = malloc(sizeof(char *) * (nbl + 1));
	if (!final)
		return (NULL);
	final[i] = get_next_line(fd);
	while (final[i])
	{
		i++;
		final[i] = get_next_line(fd);
	}
	return (final);
}
