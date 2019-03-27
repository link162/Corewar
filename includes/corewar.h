/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:57:51 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/27 21:10:28 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libftprintf/libftprintf.h"
# include "op.h"
# define USAGE "Usage: ./corewar [-d N] [-v] [-n N] <champion1.cor> <...>"
# define ERROR_FILE "Error_file"


typedef struct		s_hero
{
	int				id;
	int				size;
	char			*name;
	char			*comment;
	char			*file;
	uint8_t			*code;
}					t_hero;

typedef struct		s_files
{
	char			*file;
	int				id;
	struct s_files	*next;
}					t_files;

typedef struct		s_cor
{
	uint8_t			stage[MEM_SIZE];
	t_hero			heroes[MAX_PLAYERS];
	t_files			*list;
	int				count_heroes;
	int				dump_cycle;
	int				visual;
}					t_cor;

void				read_flags(t_cor *cor, int argc, char **argv);
void				error_case(char *str);
int					mod_atoi(char *str);
t_files				*create_list(int i, char *data);
int					is_filename(char *str);
void				add_file(t_cor *cor, int *i, int argc, char **argv);
void				set_players(t_cor *cor);
void				validate_heroes(t_cor *cor);

#endif
