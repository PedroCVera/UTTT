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
	printf("B x[%d]y[%d] ---- S x[%d]y[%d] character = %c\n", g->x_b, g->y_b, g->x_s, g->y_s, g->tac[g->y_b][g->x_b].tic[g->y_s][g->x_s]);
	printf("x = %d y = %d\n", x, y);
	if (g->state == 'B')
	{
		if (g->x_b + x >= 0 && g->x_b + x <= 2)
		{
			g->x_b += x;
			if (x)
				printf("moving left/right\n");
		}
		if (g->y_b + y >= 0 && g->y_b + y <= 2)
		{
			g->y_b += y;
			if (y)
			printf("moving up/down\n");
		}
	}
	else
	{
		if (g->x_s + x >= 0 && g->x_s + x <= 2)
			g->x_s += x;
		if (g->y_s + y >= 0 && g->y_s + y <= 2)
			g->y_s += y;
	}
	printf("B x[%d]y[%d] ---- S x[%d]y[%d] character = %c\n", g->x_b, g->y_b, g->x_s, g->y_s, g->tac[g->y_b][g->x_b].tic[g->y_s][g->x_s]);
}

void	g_select(t_game *g)
{
	if (g->state == 'B')
	{
		if (!(g->tac[g->y_b][g->x_b].result))
		{
			g->state = 'S';
			g->x_s = 1;
			g->y_s = 1;
		}
	}
	else
	{
		if ((!(g->tac[g->y_b][g->x_b].tic[g->y_s][g->x_s])))
		{
			g->tac[g->y_b][g->x_b].tic[g->y_s][g->x_s] = g->playing;
			if (g->playing == 'o')
				g->playing = 'x';
			else
				g->playing = 'o';
			if (!(g->tac[g->y_s][g->x_s].result))
			{
				g->x_b = g->x_s;
				g->y_b = g->y_s;
			}
			else
			{
				g->state = 'B';
				g->x_b = 1;
				g->y_b = 1;
			}
		}
	}
}

// void	move(int x, int y, t_game *g)
// {
// 	if (g->lock == 1)
// 	{
// 		if (x == -1 && g->cursor_x == 0)
// 			return ;
// 		else if (x == 1 && g->cursor_x == 2)
// 			return ;
// 		if (y == -1 && g->cursor_y == 0)
// 			return ;
// 		else if (y == 1 && g->cursor_y == 2)
// 			return ;
// 		g->cursor_x += x;
// 		g->cursor_y += y;
// 	}
// 	else
// 	{
// 		if (x == -1 && g->play_x == 0)
// 			return ;
// 		else if (x == 1 && g->play_x == 2)
// 			return ;
// 		if (y == -1 && g->play_y == 0)
// 			return ;
// 		else if (y == 1 && g->play_y == 2)
// 			return ;
// 		g->play_x += x;
// 		g->play_y += y;
// 	}
// }

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
	g->state = 'B';
	g->x_b = 1;
	g->y_b = 1;
	g->x_s = 1;
	g->y_s = 1;
	g->playing = 'x';


	// g->lock = 0;
	// g->play_x = 0;
	// g->play_y = 0;
	// g->cursor_x = 0;
	// g->cursor_y = 0;
}

int	game_engine(t_game *g)
{
	// (void)g;
	display(g);
	check_small(g);
	return (1);
}