/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation16.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:51:43 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/03 18:37:50 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
/*
inline int8_t	get_byte(t_vm *vm, int32_t pc, int32_t step)
{
	return (vm->arena[calc_addr(pc + step)]);
}
*/

void		int_to_byte(t_cor *cor, int32_t addr, int32_t value, int32_t size)
{
	int8_t i;

	i = 0;
	while (size)
	{
		cor->stage[find_adress(addr + size - 1)] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

int32_t		byte_to_int(t_cor *cor, int32_t addr, int32_t size)
{
	int32_t		result;
	uint8_t		sign;
	int			i;

	i = 0;
	result = 0;
	sign = (cor->stage[find_adress(addr)] & 0x80);
	while (size)
	{
		if (sign)
			result += ((cor->stage[find_adress(addr + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += cor->stage[find_adress(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int		take_op(t_cor *cor, t_cursor *cursor, uint8_t i, int mod)
{
	t_operation	*op;
	int			value;
	int			addr;

	op = &g_op[cursor->operation - 1];
	value = 0;
	if (cursor->args_types[i - 1] & T_REG)
		value = cursor->reg[cor->stage[find_adress(cursor->pos + cursor->step)] - 1];
	else if (cursor->args_types[i - 1] & T_DIR)
		value = byte_to_int(cor, cursor->pos + cursor->step, op->t_dir_size);
	else if (cursor->args_types[i - 1] & T_IND)
	{
		addr = byte_to_int(cor, cursor->pos + cursor->step, IND_SIZE);
		value = byte_to_int(cor, cursor->pos + (mod ? (addr % IDX_MOD) : addr), DIR_SIZE);
	}
	cursor->step += count_step(cursor->args_types[i - 1], op);
	return (value);
}
