/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_control_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:43:44 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/28 13:27:27 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	update_arena(t_cor *cor)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 2;
	y = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			y++;
			x = 2;
		}
		mvwprintw(g_win_arena, y, x, "%02x", cor->stage[i]);
		x += 3;
		i++;
	}
}
