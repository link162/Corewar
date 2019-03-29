/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:38:17 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/29 13:43:35 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_operation(t_cor *cor, t_cursor *cursor)
{
	cursor->operation = vm->arena[cursor->pos];
	if (vm->arena[current->pc] >= 0x01 && vm->arena[current->pc] <= 0x10)
		current->cycles_to_exec = g_op[INDEX(current->op_code)].cycles;
}

void	check_cursor(t_cursor *cursor, t_cor *cor)
{
	if (cursor->cycles_wait == 0)
		set_operation(cor, cursor);
	if (cursor->cycles_wait > 0)
		cursor->cycles_wait--;
	if (cursor->cycles_wait == 0)
	{
		if (cursor->operation >= 0x01 && cursor->operation <= 0x10)
			op = &g_op[INDEX(cursor->op_code)];
		if (op)
		{
			parse_types_code(vm, cursor, op);
			if (is_arg_types_valid(cursor, op) && is_args_valid(cursor, vm, op))
				op->func(vm, cursor);
			else
				cursor->step += calc_step(cursor, op);
			if (vm->log & PC_MOVEMENT_LOG && cursor->step)
				log_pc_movements(vm->arena, cursor);
		}
		else
			cursor->step = OP_CODE_LEN;
		move_cursor(vm, cursor);
}

void	run_cycle(t_cor *cor)
{
	t_cursor *tmp;

	cor->cycles++;
	cor->cycles_after_check++;
	tmp = vm->cursors;
	while (tmp)
	{
		check_cursor(tmp, cor);
		tmp = tmp->next;
	}
}

void	check_who_die(t_cor *cor)
{
	
}

void	full_game(t_cor *cor)
{
	while (cor->cursors)
	{
		if (cor->dump_cycle == cor->cycles)
		{
			print_arena(cor);
			exit(1);
		}
		run_cycle(cor);
		if (cor->cycles_to_die == cor->cycles_after_check ||
				cor->cycles_to_die <= 0)
			check_who_die(cor);
		cor->cursors--;
	}
}
