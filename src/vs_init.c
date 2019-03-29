/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:33:35 by akorobov          #+#    #+#             */
/*   Updated: 2019/03/29 13:51:35 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <locale.h>

void		update(WINDOW *win)
{
	refresh();
	wrefresh(win);
}

static void print_border(int y)
{
	wattron(g_win_status_bar, COLOR_PAIR(15));
	mvwprintw(g_win_status_bar, y, 1,
			"___________________________________________________________");
	mvwprintw(g_win_status_bar, ++y, 1,
			"___________________________________________________________");
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

void		print_header()
{
	wattron(g_win_status_bar, COLOR_PAIR(16));
	mvwprintw(g_win_status_bar, 1, 1, "%S",
			L" ██████╗ ██████╗ ██████╗ ███████╗██╗    ██╗ █████╗ ██████╗ ");
	mvwprintw(g_win_status_bar, 2, 1, "%S",
			L"██╔════╝██╔═══██╗██╔══██╗██╔════╝██║    ██║██╔══██╗██╔══██╗");
	mvwprintw(g_win_status_bar, 3, 1, "%S",
			L"██║     ██║   ██║██████╔╝█████╗  ██║ █╗ ██║███████║██████╔╝");
	mvwprintw(g_win_status_bar, 4, 1, "%S",
			L"██║     ██║   ██║██╔══██╗██╔══╝  ██║███╗██║██╔══██║██╔══██╗");
	mvwprintw(g_win_status_bar, 5, 1, "%S",
			L"╚██████╗╚██████╔╝██║  ██║███████╗╚███╔███╔╝██║  ██║██║  ██║");
	mvwprintw(g_win_status_bar, 6, 1, "%S",
			L" ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝");
	wattroff(g_win_status_bar, COLOR_PAIR(16));
	print_border(7);
}

void		print_players_info(t_cor *cor)
{
	int		y;
	int		len;
	int		i;

	y = 17;
	i = -1;
	while (++i < cor->count_heroes && (y += 2))
	{
		mvwprintw(g_win_status_bar, ++y, 5, "PLAYER NUMBER %d", i + 1);
		mvwprintw(g_win_status_bar, ++y, 7, "name:");
		wattron(g_win_status_bar, COLOR_PAIR(i + 1));
		len = ft_strlen(cor->heroes[i].name);
		if (len > 30)
		{
			mvwprintw(g_win_status_bar, y, 14, "%.*s", len / 2,
					cor->heroes[i].name, &cor->heroes[i].name[len / 2]);
			mvwprintw(g_win_status_bar, ++y, 8, &cor->heroes[i].name[len / 2]);
		}
		else
			mvwprintw(g_win_status_bar, y, 14, "%s", cor->heroes[i].name);
		wattroff(g_win_status_bar, COLOR_PAIR(i + 1));
		mvwprintw(g_win_status_bar, ++y, 7, "last live:");
		mvwprintw(g_win_status_bar, ++y, 7, "lives in current period:");
	}
}

void		init_status_bar(t_cor *cor)
{
	print_header();
	mvwprintw(g_win_status_bar, 11, 5, "CYCLE :");
	mvwprintw(g_win_status_bar, 12, 5, "CYCLE TO DIE :");
	mvwprintw(g_win_status_bar, 13, 5, "CYCLE DELTA :");
	mvwprintw(g_win_status_bar, 14, 5, "PROCESSES :");
	print_border(16);
	print_players_info(cor);
	print_border(48);
	print_control_key();
	update(g_win_status_bar);
}

void		init_win(t_cor *cor)
{
	g_music_set = ft_strdup("./music.sh 1 &");
	system(g_music_set);
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	set_colors();
	write(1, "\e[8;67;258t", 14);
	g_win_arena = newwin(66, 195, 0, 0);
	g_win_status_bar = newwin(66, 61, 0, 195);
	g_delay = 10000;
	wattron(g_win_status_bar, A_BOLD | COLOR_PAIR(15));
	wattron(g_win_arena, (A_BOLD | COLOR_PAIR(15)));
	box(g_win_arena, 0, 0);
	box(g_win_status_bar, 0, 0);
	wattroff(g_win_arena, COLOR_PAIR(15));
	wattroff(g_win_status_bar, COLOR_PAIR(15));
	init_status_bar(cor);
}
