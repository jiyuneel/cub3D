/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_vector_in_image.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:36:18 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/24 21:34:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_init_unit_vectors(t_raycast *ray, t_vec_f *player);

void	calculate_vector_in_image(t_game *game, int screen_x)
{
	t_raycast	*ray;
	double		camera_x;

	ray = &game->ray_info;
	camera_x = 2 * screen_x / (double)SCR_WIDTH - 1;
	ray->ray_dir.x = game->view_dir.x + game->plane_dir.x * camera_x;
	ray->ray_dir.y = game->view_dir.y + game->plane_dir.y * camera_x;
	ray->map_pos.x = (int)game->player.x;
	ray->map_pos.y = (int)game->player.y;
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	_init_unit_vectors(ray, &game->player);
}

static void	_init_unit_vectors(t_raycast *ray, t_vec_f *player)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_dir.x = -1;
		ray->side_dist.x = (player->x - ray->map_pos.x) \
			* ray->delta_dist.x;
	}
	else
	{
		ray->step_dir.x = 1;
		ray->side_dist.x = (ray->map_pos.x + 1.0 - player->x) \
			* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_dir.y = -1;
		ray->side_dist.y = (player->y - ray->map_pos.y) \
			* ray->delta_dist.y;
	}
	else
	{
		ray->step_dir.y = 1;
		ray->side_dist.y = (ray->map_pos.y + 1.0 - player->y) \
			* ray->delta_dist.y;
	}
}
