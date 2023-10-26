#include "../inc/UTTT.h"

char	B_check_horizontal(t_game *g)
{
	int	X = 0;
	int	O = 0;

	for (int row = 0; row < 3; row++)
	{
		X = 0;
		O = 0;
		for(int col = 0; col < 3; col++)
		{
			if (g->tac[row][col].result == 'x')
				X++;
			else if(g->tac[row][col].result == 'o')
				O++;
		}
		if (X == 3)
			return 'x';
		else if (O == 3)
			return 'o';
	}
	return ('\0');
}

char	B_check_vertical(t_game *g)
{
	int	X = 0;
	int	O = 0;

	for (int col = 0; col < 3; col++)
	{
		X = 0;
		O = 0;
		for(int row = 0; row < 3; row++)
		{
			if (g->tac[row][col].result == 'x')
				X++;
			else if(g->tac[row][col].result == 'o')
				O++;
		}
		if (X == 3)
			return 'x';
		else if (O == 3)
			return 'o';
	}
	return ('\0');
}


char	B_check_diagonal(t_game *g)
{
	if (g->tac[1][1].result == 'x')
	{
		if (g->tac[0][2].result == 'x' && g->tac[2][0].result == 'x')
			return 'x';
		else if (g->tac[0][0].result == 'x' && g->tac[2][2].result == 'x')
			return 'x';
	}
	else if (g->tac[1][1].result == 'o')
	{
		if (g->tac[0][2].result == 'o' && g->tac[2][0].result == 'o')
			return 'o';
		else if (g->tac[0][0].result == 'o' && g->tac[2][2].result == 'o')
			return 'o';
	}
	return ('\0');
}

char	checker_big_sqr(t_game *g)
{
	char	flag = '\0';
	int	cx = 0;

	for (int row = 0; row < 3; row++)
		for(int col = 0; col < 3; col++)
			if (g->tac[row][col].result)
				cx++;
	flag = B_check_diagonal(g);
	if (flag)
		return flag;
	flag = B_check_horizontal(g);
	if (flag)
		return flag;
	flag = B_check_vertical(g);
	if (flag)
		return flag;
	if (cx == 9)
		return '-';
	return '\0';
}

void	small_checker(t_tic *tic)
{
	for (int i = 0; i < 3; i++)
	{
		if ((*tic).tic[i][0] && (*tic).tic[i][0] == (*tic).tic[i][1] && (*tic).tic[i][0] == (*tic).tic[i][2])
		{
			(*tic).result = (*tic).tic[i][0];
			return ;
		}
		else if ((*tic).tic[0][i] && (*tic).tic[0][i] == (*tic).tic[1][i] && (*tic).tic[0][i] == (*tic).tic[2][i])
		{
			(*tic).result = (*tic).tic[0][i];
			return ;
		}
	}
	if ((*tic).tic[0][0] && (*tic).tic[0][0] == (*tic).tic[1][1] && (*tic).tic[0][0] == (*tic).tic[2][2])
	{
		(*tic).result = (*tic).tic[0][0];
		return ;
	}
	if ((*tic).tic[0][2] && (*tic).tic[0][2] == (*tic).tic[1][1] && (*tic).tic[0][2] == (*tic).tic[2][0])
	{
		(*tic).result = (*tic).tic[0][2];
		return ;
	}
}

void	check_small(t_game *g)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (!(g->tac[y][x].result))
				small_checker(&(g->tac[y][x]));
		}
	}
}

int	try_lock(t_game *g)
{
	if (g->lock == 1)
	{
		if (g->tac[g->y_b][g->x_b].tic[g->cursor_x][g->cursor_y])
			return 1;
		else
			return 0;
	}
	else
	{
		if (g->tac[g->y_b][g->x_b].result)
			return 1;
		else
		{
			g->lock = 1;
			return 1;
		}
	}
	return 1;
}