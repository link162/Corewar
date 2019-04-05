/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 09:49:34 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 13:56:50 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		winner_ban()
{
	wattron(stdscr, COLOR_PAIR(17));
	mvwprintw(stdscr, 28, 100, "%S",
			L"██╗    ██╗██╗███╗   ██╗███╗   ██╗███████╗██████╗ ");
	mvwprintw(stdscr, 29, 100, "%S",
			L"██║    ██║██║████╗  ██║████╗  ██║██╔════╝██╔══██╗");
	mvwprintw(stdscr, 30, 100, "%S",
			L"██║ █╗ ██║██║██╔██╗ ██║██╔██╗ ██║█████╗  ██████╔╝");
	mvwprintw(stdscr, 31, 100, "%S",
			L"██║███╗██║██║██║╚██╗██║██║╚██╗██║██╔══╝  ██╔══██╗");
	mvwprintw(stdscr, 32, 100, "%S",
			L"╚███╔███╔╝██║██║ ╚████║██║ ╚████║███████╗██║  ██║");
	mvwprintw(stdscr, 33, 100, "%S",
			L" ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝");
	wattroff(stdscr, COLOR_PAIR(17));
}

void			get_color(int id)
{
	const char	*color[4] = {
		"\033[32m", "\033[34m", "\033[33m", "\033[31m"};

	printf("%s", color[id]);
}

void		winner(t_hero winner)
{
	int		y;
	int		x;
	int		col;
	int		len;
	
	update(stdscr);
	y = getmaxy(stdscr);
	x = getmaxx(stdscr);
	get_color(winner.id);
	len = ft_strlen(winner.name);
	while (y--)
	{
		col = x / 2;
		while (col--)
			printf("%c ", ft_toupper(winner.name[col % len]));
	}
	winner_ban();
	while (getch() != KEY_ESC)
		;
	dinit_win();
}
