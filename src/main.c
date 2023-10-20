# include "../inc/UTTT.h"

int key(int code, t_game *g)
{
	if (code == UP)
		move(-1, 0, g);
	else if (code == RIGHT)
		move(0, 1, g);
	else if (code == DOWN)
		move(1, 0, g);
	else if (code == LEFT)
		move(1, 0, g);
	else if (code == ESC)
		exit(0);
	else if (code == SPACE)
	{
		if (try_lock(g) == 1)
			;
		else
			Play(g);
	}
	return (0);
}

int main() {
	t_game g;
	init_game(&g);
	g.mlx = mlx_init();
	g.mlx_w = mlx_new_window(g.mlx, 1000, 1000, "UTTT");
	mlx_loop_hook(g.mlx, game_engine, &g);
	mlx_key_hook(g.mlx_w, key, &g);
	mlx_loop(g.mlx);
}