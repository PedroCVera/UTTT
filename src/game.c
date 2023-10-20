#include "../inc/UTTT.h"

void	Play(t_game *g)
{
	char	flag = '\0';

	g->tac[g->play_x][g->play_y].tic[g->cursor_x][g->cursor_y] = g->playing;
	if (g->playing == 'x')
		g->playing = 'o';
	else
		g->playing = 'x';
	if (!check_if_small_done(g))
	{
		flag = checker_big_sqr(g);
		if (flag)
		{
			printf(GRN"CONGRATS, %c WON!", flag);
			exit(1);
		}
	}
	g->play_x = g->cursor_x;
	g->play_y = g->cursor_y;
	if (g->tac[g->play_x][g->play_y].result)
		g->lock = 0;
	g->cursor_x = 0;
	g->cursor_y = 0;
}

void	move(int x, int y, t_game *g)
{
	if (g->lock == 1)
	{
		if (x == -1 && g->cursor_x == 0)
			return ;
		else if (x == 1 && g->cursor_x == 2)
			return ;
		if (y == -1 && g->cursor_y == 0)
			return ;
		else if (y == 1 && g->cursor_y == 2)
			return ;
		g->cursor_x += x;
		g->cursor_y += y;
	}
	else
	{
		if (x == -1 && g->play_x == 0)
			return ;
		else if (x == 1 && g->play_x == 2)
			return ;
		if (y == -1 && g->play_y == 0)
			return ;
		else if (y == 1 && g->play_y == 2)
			return ;
		g->play_x += x;
		g->play_y += y;
	}
}

void	init_game(t_game *g)
{
	for (int rowtac = 0; rowtac < 3; rowtac++)
	{
		for (int coltac = 0; coltac < 3; coltac++)
		{
			for (int row = 0; row < 3; row++)
			{
				for(int col = 0; col < 3; col++)
					g->tac[rowtac][coltac].tic[row][col] = '\0';
			}
			g->tac[rowtac][coltac].result = '\0';
		}		
	}
	g->playing = 'x';
	g->lock = 0;
}

int	game_engine(t_game *g)
{
	(void)g;
	return (1);
}