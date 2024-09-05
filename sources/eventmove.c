/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:44:22 by agiguair          #+#    #+#             */
/*   Updated: 2023/12/10 14:52:58 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	view_player(t_data *data)
{
	double	old_dx;
	double	angle;
	double	radian_angle;

	old_dx = data->player->dx;
	if (data->rl == 1)
	{
		angle = -5;
		radian_angle = angle * M_PI / 180.0;
		data->player->dx = data->player->dx
			* cos(radian_angle) - data->player->dy * sin(radian_angle);
		data->player->dy = old_dx * sin(radian_angle)
			+ data->player->dy * cos(radian_angle);
	}
	if (data->rr == 1)
	{
		angle = 5;
		radian_angle = angle * M_PI / 180.0;
		data->player->dx = data->player->dx * cos(radian_angle)
			- data->player->dy * sin(radian_angle);
		data->player->dy = old_dx * sin(radian_angle)
			+ data->player->dy * cos(radian_angle);
	}
}

void	move_playerf(t_data *data)
{
	if (data->mf)
	{
		if (data->map[(int)(data->player->y)]
		[(int)(data->player->x - data->player->dx * 0.3)] == '0' ||
		data->map[(int)(data->player->y)]
		[(int)(data->player->x - data->player->dx * 0.3)] == '6')
			data->player->x -= data->player->dx * 0.1;
		if (data->map[(int)(data->player->y - data->player->dy * 0.3)]
		[(int)(data->player->x)] == '0' ||
		data->map[(int)(data->player->y - data->player->dy * 0.3)]
		[(int)(data->player->x)] == '6')
			data->player->y -= data->player->dy * 0.1;
	}
	else
		move_playerb(data);
}

void	move_playerb(t_data *data)
{
	if (data->mb)
	{
		if (data->map[(int)(data->player->y)]
		[(int)(data->player->x + data->player->dx * 0.3)] == '0'
			|| (data->map[(int)(data->player->y)]
		[(int)(data->player->x + data->player->dx * 0.3)] == '6'))
			data->player->x += data->player->dx * 0.1;
		if (data->map[(int)(data->player->y + data->player->dy * 0.3)]
		[(int)(data->player->x)] == '0'
			|| data->map[(int)(data->player->y + data->player->dy * 0.3)]
		[(int)(data->player->x)] == '6')
			data->player->y += data->player->dy * 0.1;
	}
}

bool	check_not_to_close(t_data *data)
{
	double	new_x;
	double	new_y;

	if (data->mr)
	{
		new_x = data->player->x - data->player->dy * 0.3;
		new_y = data->player->y + data->player->dx * 0.3;
	}
	if (data->ml)
	{
		new_x = data->player->x + data->player->dy * 0.3;
		new_y = data->player->y - data->player->dx * 0.3;
	}
	if (data->map[(int)new_y][(int)new_x] != '1'
		&& data->map[(int)new_y][(int)new_x] != '2'
		&& data->map[(int)new_y][(int)new_x] != '3'
		&& data->map[(int)new_y][(int)new_x] != '4'
		&& data->map[(int)new_y][(int)new_x] != '5'
		&& data->map[(int)new_y][(int)new_x] != '7'
		&& data->map[(int)new_y][(int)new_x] != '8'
		&& data->map[(int)new_y][(int)new_x] != '9')
		return (TRUE);
	return (FALSE);
}

void	move_playerlr(t_data *data)
{
	double	new_x;
	double	new_y;

	if (data->mr)
	{
		new_x = data->player->x - data->player->dy * 0.1;
		new_y = data->player->y + data->player->dx * 0.1;
	}
	if (data->ml)
	{
		new_x = data->player->x + data->player->dy * 0.1;
		new_y = data->player->y - data->player->dx * 0.1;
	}
	if (check_not_to_close(data))
	{
		data->player->x = new_x;
		data->player->y = new_y;
	}
}
