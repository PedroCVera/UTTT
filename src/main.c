# include "../inc/UTTT.h"

int key(int code, t_game *g)
{
	(void)g;
	printf("key = %d\n", code);
	// if (code == UP)
	// 	move(-1, 0, g);
	// if (code == UP)
	// 	move(-1, 0, g);
	// if (code == UP)
	// 	move(-1, 0, g);
	// if (code == UP)
	// 	move(-1, 0, g);
	
	return (0);
}

int main() {
	t_game g;
	// init_game(&g);
	g.mlx = mlx_init();
	g.mlx_w = mlx_new_window(g.mlx, 1700, 1700, "UTTT");
	// mlx_loop_hook(g.mlx, game_engine, &g);
	// create_image(&(g.big_grid), g.mlx, "imgs/big_grid.xpm");
	create_grid(&(g.big_grid), g.mlx, 900, 900, 25);
	create_grid(&(g.small_grid), g.mlx, 270, 270 , 5);
	dislplay(&g);
	mlx_key_hook(g.mlx_w, key, &g);
	mlx_loop(g.mlx);
}