/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_control_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:43:44 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 14:35:22 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			show_cursor(t_cor *cor)
{
	t_cursor	*cur;
	int			y;
	int			x;

	cur = cor->cursor;
	while (cur)
	{
		y = cur->pos;
		x =  / cur->pos;
		wattron(g_win_arena, COLOR_PAIR(cor->cursor->id + 1));
		mvwprintw(g_win_arena, y, x, "%02x", cor->stage[cur->pos]);
		wattroff(g_win_arena, COLOR_PAIR(cor->cursor->id + 1));
		cur = cur->next;
	}
}

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
		wattron(g_win_arena, COLOR_PAIR(16));
		if (i % 64 == 0)
		{
			y++;
			x = 2;
		}
		if (cor->field[i])
			wattron(g_win_arena, COLOR_PAIR(cor->field[i]));
		mvwprintw(g_win_arena, y, x, "%02x", cor->stage[i]);
		x += 3;
		i++;
	}
	show_cursor(cor);
	update(g_win_arena);
	key_control();
	usleep(g_delay);
}
