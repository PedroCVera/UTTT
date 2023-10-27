# include "../inc/UTTT.h"

int key(int code, t_game *g)
{
	if (code == UP)
		move(0, -1, g);
	else if (code == RIGHT)
		move(1, 0, g);
	else if (code == DOWN)
		move(0, 1, g);
	else if (code == LEFT)
		move(-1, 0, g);
	else if (code == ESC)
		exit(0);
	else if (code == SPACE)
		g_select(g);
	return (0);
}

void init_images(t_game *g)
{
	g->o_big.img = mlx_xpm_file_to_image(g->mlx, "imgs/O_big.xpm", &(g->o_big.width), &(g->o_big.height));
	g->o_big.addr = mlx_get_data_addr(g->o_big.img, &(g->o_big.bits_per_pixel), (&g->o_big.line_length), (&g->o_big.endian));

	g->o_small.img = mlx_xpm_file_to_image(g->mlx, "imgs/O_small.xpm", &(g->o_small.width), &(g->o_small.height));
	g->o_small.addr = mlx_get_data_addr(g->o_small.img, &(g->o_small.bits_per_pixel), (&g->o_small.line_length), (&g->o_small.endian));

	g->x_big.img = mlx_xpm_file_to_image(g->mlx, "imgs/X_big.xpm", &(g->x_big.width), &(g->x_big.height));
	g->x_big.addr = mlx_get_data_addr(g->x_big.img, &(g->x_big.bits_per_pixel), (&g->x_big.line_length), (&g->x_big.endian));

	g->x_small.img = mlx_xpm_file_to_image(g->mlx, "imgs/X_small.xpm", &(g->x_small.width), &(g->x_small.height));
	g->x_small.addr = mlx_get_data_addr(g->x_small.img, &(g->x_small.bits_per_pixel), (&g->x_small.line_length), (&g->x_small.endian));

	create_selection(&(g->slct_r), g->mlx, 100, 100, 6, 0x00FF0000);
	create_selection(&(g->slct_g), g->mlx, 100, 100, 6, 0x0000FF00);
	create_selection(&(g->select_r), g->mlx, 300, 300, 6, 0x00FF0000);
	create_selection(&(g->select_g), g->mlx, 300, 300, 6, 0x0000FF00);
	create_grid(&(g->big_grid), g->mlx, 900, 900, 25);
	create_grid(&(g->small_grid), g->mlx, 270, 270 , 5);
}

int main() {
	t_game g;
	init_game(&g);
	g.mlx = mlx_init();



	init_images(&g);
	g.mlx_w = mlx_new_window(g.mlx, 1700, 1700, "UTTT");
	mlx_loop_hook(g.mlx, game_engine, &g);
	mlx_key_hook(g.mlx_w, key, &g);
	mlx_loop(g.mlx);
	printf("\n\nGame made by: pcoimbra, ralves-g!\n");
}