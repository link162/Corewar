/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:09:54 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/02 18:21:30 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				op_live(t_cor *cor, t_cursor *cursor)
{
	int		id;
	t_hero	*hero;

	ft_printf("live!!!\n");
	cursor->step++;
	id = take_op(cor, cursor, 1, false);
	cor->live_in++;
	cursor->last_live = cor->cycles;
	hero = NULL;
	if (id <= -1 && id >= -cor->count_heroes)
	{
		if (id < 0)
			id *= -1;
		hero = &cor->heroes[id - 1];
		hero->last_live = cor->cycles;
		hero->live++;
		cor->last_alive = id - 1;
	}
}

void				op_ld(t_cor *cor, t_cursor *cursor)
{/*
	int32_t	value;
	int32_t	r_id;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_op_arg(vm, cursor, 1, true);
	cursor->carry = (t_bool)(!value);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r_id)] = value;
	cursor->step += REG_LEN;*/
}

void				op_st(t_cor *cor, t_cursor *cursor)
{/*
int32_t	r_id;
	int32_t	r_value;
	int32_t	addr;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	r_value = cursor->reg[INDEX(r_id)];
	cursor->step += REG_LEN;
	if (cursor->args_types[1] == T_REG)
	{
		addr = get_byte(vm, cursor->pc, cursor->step);
		cursor->reg[INDEX(addr)] = r_value;
		cursor->step += REG_LEN;
	}
	else
	{
		addr = bytecode_to_int32(vm->arena,
							cursor->pc + cursor->step, IND_SIZE);
		int32_to_bytecode(vm->arena, cursor->pc + (addr % IDX_MOD),
							r_value, DIR_SIZE);
		vs_st(vm, cursor, addr);
		cursor->step += IND_SIZE;
	}
	if (vm->log & OP_LOG)
		log_st(cursor->id, r_id, addr);*/
}

void				op_add(t_cor *cor, t_cursor *cursor)
{/*
	int32_t	r1_id;
	int32_t	r2_id;
	int32_t	r3_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r1_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	r2_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	value = cursor->reg[INDEX(r1_id)] + cursor->reg[INDEX(r2_id)];
	cursor->carry = (t_bool)(!value);
	r3_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r3_id)] = value;
	cursor->step += REG_LEN;
	if (vm->log & OP_LOG)
		log_add(cursor->id, r1_id, r2_id, r3_id);*/
}

void				op_sub(t_cor *cor, t_cursor *cursor)
{/*
	int32_t	r1_id;
	int32_t	r2_id;
	int32_t	r3_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r1_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	r2_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	value = cursor->reg[INDEX(r1_id)] - cursor->reg[INDEX(r2_id)];
	cursor->carry = (t_bool)(!value);
	r3_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r3_id)] = value;
	cursor->step += REG_LEN;
	if (vm->log & OP_LOG)
		log_sub(cursor->id, r1_id, r2_id, r3_id);*/
}
