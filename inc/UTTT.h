#ifndef UTTT_H
# define UTTT_H

# include "../mlx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>

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
	int		x_size;
	int		y_size;
	int		cursor_x;
	int		cursor_y;
}	t_img;

typedef struct s_tic {
	char tic[3][3];
	char result;
} t_tic;

typedef struct s_game {
	void	*mlx;
	void	*mlx_w;
	t_img	frame;

	t_tic	tac[3][3];
	char	playing;
	int		play_x;
	int		play_y;
} t_game;




#endif