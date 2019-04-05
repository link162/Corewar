/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 09:49:34 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 10:08:42 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		winner(char *name_winner)
{
	int		y;
	int		x;
	int		col_sym;
	
	update(g_win_status_bar);
	update(g_win_arena);
	if (258 % ft_strlen(name_winner))
		col = 258 /  ft_strlen(name_winner) + 1;
	else
		col = 258 /  ft_strlen(name_winner);	
	y = -1;
	while (++y < 67)
	{
		x = -1;
		while (++x < col)
			printf(name_winner);
	}
	while (getch() != KEY_ESC)
		;
}
