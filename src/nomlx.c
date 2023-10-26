/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nomlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:45:55 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/10/26 17:51:54 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/UTTT.h"

void	Default_Game_Display(t_game *g)
{
	for (int h = 0; h < 3; h++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int z = 0; z < 3; z++)
			{
				for (int i = 0; i < 3; i++)
				{
					printf("%c", g->tac[h][z].tic[j][i]);
					if (i < 2)
						printf("|");
				}
				if (z < 2)
					printf(" * ");
			}
			printf("\n");
		}
		if (h < 2)
			printf("******************************\n");
	}
}