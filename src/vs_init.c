/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:33:35 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/28 13:44:13 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <locale.h>

static void	set_colors(void)
{
	start_color();
	init_pair(15, 147, 0);
	init_pair(16, COLOR_WHITE, 0);
	init_pair(1, COLOR_GREEN, 0);
	init_pair(2, 21, 0);
	init_pair(3, COLOR_YELLOW, 0);
	init_pair(4, COLOR_RED, 0);
	init_pair(11, COLOR_WHITE, 49);
	init_pair(12, COLOR_WHITE, 111);
	init_pair(13, COLOR_WHITE, 223);
	init_pair(14, COLOR_WHITE, 205);
}

void		print_header()
{
	wattron(g_win_status_bar, COLOR_PAIR(16));
	mvwprintw(g_win_status_bar, 1, 1, "%S", L" ██████╗ ██████╗ ██████╗ ███████╗██╗    ██╗ █████╗ ██████╗ ");
	mvwprintw(g_win_status_bar, 2, 1, "%S", L"██╔════╝██╔═══██╗██╔══██╗██╔════╝██║    ██║██╔══██╗██╔══██╗");
	mvwprintw(g_win_status_bar, 3, 1, "%S", L"██║     ██║   ██║██████╔╝█████╗  ██║ █╗ ██║███████║██████╔╝");
	mvwprintw(g_win_status_bar, 4, 1, "%S", L"██║     ██║   ██║██╔══██╗██╔══╝  ██║███╗██║██╔══██║██╔══██╗");
	mvwprintw(g_win_status_bar, 5, 1, "%S", L"╚██████╗╚██████╔╝██║  ██║███████╗╚███╔███╔╝██║  ██║██║  ██║");
	mvwprintw(g_win_status_bar, 6, 1, "%S", L" ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝");
	mvwprintw(g_win_status_bar, 7, 1, "___________________________________________________________");
	mvwprintw(g_win_status_bar, 8, 1, "___________________________________________________________");
	wattron(g_win_status_bar, COLOR_PAIR(15));
}

void		init_status_bar()
{
	mvwprintw(g_win_status_bar, 10, 5, "Cycle :");
	mvwprintw(g_win_status_bar, 11, 5, "Processes :");
	mvwprintw(g_win_status_bar, 12, 5, "Cycle to die :");
	mvwprintw(g_win_status_bar, 13, 5, "Cycle delta :");
	mvwprintw(g_win_status_bar, 14, 5, "PLAYERS");
}

void		init_win(t_cor *cor)
{
	system("afplay -r 1.5 music.mp3 &");
	setlocale(LC_ALL, "");
	initscr();
	g_win_arena = newwin(66, 195, 0, 0);
	g_win_status_bar = newwin(66, 61, 0, 195);
	timeout(0);
	noecho();
	curs_set(0);
	set_colors();
	wattron(g_win_status_bar, A_BOLD | COLOR_PAIR(15));
	wattron(g_win_arena, A_BOLD | COLOR_PAIR(15));
	box(g_win_arena, 0, 0);
	box(g_win_status_bar, 0, 0);
	wattroff(g_win_arena, A_BOLD | COLOR_PAIR(15));
	print_header();
	init_status_bar();
	update_arena(cor);
	refresh();
	wrefresh(g_win_arena);
	wrefresh(g_win_status_bar);
}
