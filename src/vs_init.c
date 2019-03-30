/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:33:35 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/30 09:13:15 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <locale.h>

void		update(WINDOW *win)
{
	refresh();
	wrefresh(win);
}

void		print_border(int y)
{
	wattron(g_win_status_bar, COLOR_PAIR(15));
	mvwprintw(g_win_status_bar, y, 1,
			"__________________________________________________________");
	mvwprintw(g_win_status_bar, ++y, 1,
			"__________________________________________________________");
	wattroff(g_win_status_bar, COLOR_PAIR(15));
}

static void	set_colors(void)
{
	start_color();
	init_pair(15, 128, 0);
	init_pair(16, COLOR_WHITE, 0);
	init_pair(1, 40, 0);
	init_pair(2, 39, 0);
	init_pair(3, COLOR_YELLOW, 0);
	init_pair(4, 196, 0);
	init_pair(11, COLOR_WHITE, 49);
	init_pair(12, COLOR_WHITE, 111);
	init_pair(13, COLOR_WHITE, 223);
	init_pair(14, COLOR_WHITE, 205);
}

void		init_win(t_cor *cor)
{
	system("echo \'\e[8;67;258t\' && stty columns 258 rows 67");
	g_music_set = ft_strdup("./music.sh 1 &");
	system(g_music_set);
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	set_colors();
	g_win_arena = newwin(66, 195, 0, 0);
	g_win_status_bar = newwin(66, 61, 0, 195);
	g_delay = 10000;
	g_speed = 1;
	wattron(g_win_status_bar, A_BOLD | COLOR_PAIR(15));
	wattron(g_win_arena, (A_BOLD | COLOR_PAIR(15)));
	box(g_win_arena, 0, 0);
	box(g_win_status_bar, 0, 0);
	wattroff(g_win_arena, COLOR_PAIR(15));
	wattroff(g_win_status_bar, COLOR_PAIR(15));
	init_status_bar(cor);
}
