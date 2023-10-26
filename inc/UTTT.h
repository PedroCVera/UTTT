#ifndef UTTT_H
# define UTTT_H

# include "../mlx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define SQUARE 400

# define MARGIN 0

# define S_MARGIN 0

# define OFFSET 1
# define SG_OFFSET 325 // SMALL GRIDS OFFSET


# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307
# define SPACE 32

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;

}	t_img;

typedef struct s_tic {
	char tic[3][3]; //tic tac toe pequeno
	char result;
} t_tic;

typedef struct s_game {
	void	*mlx;
	void	*mlx_w;
	t_img	frame;
	t_img	o_big;
	t_img	o_small;
	t_img	x_big;
	t_img	x_small;
	t_img	big_grid;
	t_img	small_grid;
	t_img	select_r;
	t_img	select_g;
	t_img	slct_r;
	t_img	slct_g;
	t_tic	tac[3][3]; //tic tac toe grande
	int		state;
	char	playing; // x || o
	int		play_x; //Position you gotta play X BIG ONES
	int		play_y; //position you gotta play Y BIG ONES
	int		x_b;
	int		y_b;
	int		x_s;
	int		y_s;
	int		cursor_x;
	int		cursor_y;
	int		lock;	//if big square is locked in
} t_game;

//  Display

void	display(t_game *g);
void	create_frame(t_img *img, void *mlx, int width, int height);
void	put_image(t_game *g, t_img *img, int start_x, int start_y);
void	put_image_grid(t_game *g, t_img *img, int start_x, int start_y);
void	print_game(t_game *g);
void	print_selection(t_game *g);
void	create_image(t_img *img, void *mlx, char *name);
void	create_grid(t_img *img, void *mlx, int width, int height, int thickness);
void	put_pixel(t_img *data, int x, int y, int color);
void	create_selection(t_img *img, void *mlx, int width, int height, int thickness, unsigned int color);

//	checkers.c

int		check_if_small_done(t_game *g);
int		try_lock(t_game *g);
char	checker_big_sqr(t_game *g);

//	Game.c

void	Play(t_game *g);
void	move(int x, int y, t_game *g);
void	g_select(t_game *g);
void	init_game(t_game *g);
int		game_engine(t_game *g);

#endif