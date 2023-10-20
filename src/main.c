# include "../inc/UTTT.h"

int key(int code, t_game *g)
{
	(void)g;
	printf("key = %d\n", code);
	return (0);
}

int main() {
	t_game g;
	// init_game(&g);
	g.mlx = mlx_init();
	g.mlx_w = mlx_new_window(g.mlx, 1000, 1000, "UTTT");
	// mlx_loop_hook(g.mlx, game_engine, &g);
	mlx_key_hook(g.mlx_w, key, &g);
	mlx_loop(g.mlx);
}