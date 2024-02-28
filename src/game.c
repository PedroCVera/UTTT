#include "../inc/UTTT.h"

void	move(int x, int y, t_game *g)
{
	if (g->state == 'B')
	{
		if (g->x_b + x >= 0 && g->x_b + x <= 2)
			g->x_b += x;
		if (g->y_b + y >= 0 && g->y_b + y <= 2)
			g->y_b += y;
	}
	else
	{
		if (g->x_s + x >= 0 && g->x_s + x <= 2)
			g->x_s += x;
		if (g->y_s + y >= 0 && g->y_s + y <= 2)
			g->y_s += y;
	}
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
			small_checker(&(g->tac[g->y_b][g->x_b]));
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
}

void clean_exit(t_game *g) {
	(void)g;
}

int	game_engine(t_game *g)
{
	check_small(g);
	char	flag = checker_big_sqr(g);
	if (flag)
	{
		if (flag == '-')
			printf("Come on guys... y'all can do better... :/\n");
		else
			printf("DINGDINGDINGDINGDING %c WON\n", flag);
		printf("\nGame made by: pcoimbra, ralves-g!\n");
		exit(0);
	}
	display(g);
	return (1);
}

