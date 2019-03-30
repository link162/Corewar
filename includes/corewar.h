/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:57:51 by ybuhai            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/29 15:39:16 by akorobov         ###   ########.fr       */
=======
/*   Updated: 2019/03/29 17:18:22 by ybuhai           ###   ########.fr       */
>>>>>>> e8f838fdd7efcc5831d8e43a2d55fabbc7dbaa2f
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libftprintf/libftprintf.h"
# include "op.h"
# include "struct.h"
# include "visual.h"
# define USAGE "Usage: ./corewar [-d N] [-v] [-n N] <champion1.cor> <...>"
# define ERROR_FILE "Error file"

<<<<<<< HEAD
void			op_live(t_cor *cor, t_cursor *cursor);
void			op_ld(t_cor *cor, t_cursor *cursor);
void			op_st(t_cor *cor, t_cursor *cursor);
void			op_add(t_cor *cor, t_cursor *cursor);
void			op_sub(t_cor *cor, t_cursor *cursor);
void			op_and(t_cor *cor, t_cursor *cursor);
void			op_or(t_cor *cor, t_cursor *cursor);
void			op_xor(t_cor *cor, t_cursor *cursor);
void			op_zjmp(t_cor *cor, t_cursor *cursor);
void			op_ldi(t_cor *cor, t_cursor *cursor);
void			op_sti(t_cor *cor, t_cursor *cursor);
void			op_fork(t_cor *cor, t_cursor *cursor);
void			op_lld(t_cor *cor, t_cursor *cursor);
void			op_lldi(t_cor *cor, t_cursor *cursor);
void			op_lfork(t_cor *cor, t_cursor *cursor);
void			op_aff(t_cor *cor, t_cursor *cursor);

typedef struct	s_op
=======
typedef struct		s_cursor
{
	int				id;
	int				carry;
	int				last_live;
	int				pos;
	int				operation;
	int				cycle_wait;
	int				step;
	int				reg[REG_NUMBER];
	struct s_cursor	*next;
}					t_cursor;

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
	t_cursor		*cursor;
	ssize_t			cycles;
	ssize_t			cycles_to_die;
	ssize_t			cycles_after_check;
	int				cursors;
	int				count_heroes;
	int				dump_cycle;
	int				visual;
	int				last_alive;
}					t_cor;

void				op_live(t_cor *cor, t_cursor *cursor);
void				op_ld(t_cor *cor, t_cursor *cursor);
void				op_st(t_cor *cor, t_cursor *cursor);
void				op_add(t_cor *cor, t_cursor *cursor);
void				op_sub(t_cor *cor, t_cursor *cursor);
void				op_and(t_cor *cor, t_cursor *cursor);
void				op_or(t_cor *cor, t_cursor *cursor);
void				op_xor(t_cor *cor, t_cursor *cursor);
void				op_zjmp(t_cor *cor, t_cursor *cursor);
void				op_ldi(t_cor *cor, t_cursor *cursor);
void				op_sti(t_cor *cor, t_cursor *cursor);
void				op_fork(t_cor *cor, t_cursor *cursor);
void				op_lld(t_cor *cor, t_cursor *cursor);
void				op_lldi(t_cor *cor, t_cursor *cursor);
void				op_lfork(t_cor *cor, t_cursor *cursor);
void				op_aff(t_cor *cor, t_cursor *cursor);

typedef struct		s_operation
>>>>>>> e8f838fdd7efcc5831d8e43a2d55fabbc7dbaa2f
{
	char			*name;
	uint8_t			code;
	uint8_t			args_num;
	int				args_types_code;
	uint8_t			args_types[3];
	int				modify_carry;
	uint8_t			t_dir_size;
	int				cycles;
	void			(*func)(t_cor *, t_cursor *);

<<<<<<< HEAD
}				t_op;
=======
}					t_operation;
>>>>>>> e8f838fdd7efcc5831d8e43a2d55fabbc7dbaa2f

static t_operation	g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 20,
		.func = &op_zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 800,
		.func = &op_fork
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = true,
		.t_dir_size = 2,
		.cycles = 50,
		.func = &op_lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &op_lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = true,
		.args_types = {T_REG, 0, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 2,
		.func = &op_aff
	}
};

<<<<<<< HEAD
=======
static uint8_t			g_arg_code[3] = {
	T_REG,
	T_DIR,
	T_IND
};

# include "visual.h"
>>>>>>> e8f838fdd7efcc5831d8e43a2d55fabbc7dbaa2f

void				read_flags(t_cor *cor, int argc, char **argv);
void				error_case(char *str);
int					mod_atoi(char *str);
t_files				*create_list(int i, char *data);
int					is_filename(char *str);
void				add_file(t_cor *cor, int *i, int argc, char **argv);
void				set_players(t_cor *cor);
void				validate_heroes(t_cor *cor);
void				init_game(t_cor *cor);
void				full_game(t_cor *cor);
void				read_command(t_cor *cor, t_cursor *cursor, t_operation *o);
int32_t				find_adress(int32_t i);
void				print_players(t_cor *cor);
void				print_arena(t_cor *cor);
void				print_last_alive(t_cor *cor);
void				print_live(t_cor *cor, int id);

#endif
