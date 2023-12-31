/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:09:18 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 04:37:24 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void leaks() {
	system("leaks -s cub3D");
}

void print_info(t_game *game) {
	printf("%s\n%s\n%s\n%s\n%d\n%d\n", game->img_info.north, game->img_info.south, game->img_info.west, game->img_info.east, game->img_info.floor, game->img_info.ceiling);
	printf("map_width: %d\nmap_height: %d\n", game->map_width, game->map_height);
	for (int y = game->map_height - 1; y >= 0; y--) {
		for (int x = 0; x < game->map_width; x++)
			printf("%d", game->map[y][x]);
		printf("\n");
	}
	printf("\n");
	printf("player: (%f, %f)\n", game->player.x, game->player.y);
	printf("view_dir: (%f, %f)\n", game->view_dir.x, game->view_dir.y);
	printf("plane_dir: (%f, %f)\n\n", game->plane_dir.x, game->plane_dir.y);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	// atexit(leaks); //
	check_argument(argc, argv);
	game = ft_calloc(1, sizeof(t_game));
	init_game_info(argv[1], game);
	// print_info(game); // 실행
	play_game(game);
	free_data(game);
	return (0);
}
