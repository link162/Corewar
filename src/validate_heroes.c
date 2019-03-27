/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_heroes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:29:06 by ybuhai            #+#    #+#             */
/*   Updated: 2019/03/27 21:11:18 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int32_t	bytecode_to_int32(uint8_t *bytecode, int size)
{
	int32_t	result;
	int		sign;
	int		i;

	result = 0;
	sign = (int)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int32_t	check_int(int fd)
{
	int		size;
	uint8_t	buffer[4];

	size = read(fd, &buffer, 4);
	if (size == -1 || size < 4)
		error_case(ERROR_FILE);
	return (bytecode_to_int32(buffer, 4));
}

char	*check_name(int fd, int len)
{
	int		size;
	char	*buffer;

	if (!(buffer = ft_strnew(len)))
		error_case("Memory error");
	size = read(fd, buffer, len);
	if (size < len)
		error_case(ERROR_FILE);
	return (buffer);
}

void	read_hero(t_cor *cor, int i)
{
	int fd;

	fd = open(cor->heroes[i].file, O_RDONLY);
	if (fd < 0)
		error_case(ERROR_FILE);
	if (check_int(fd) != COREWAR_EXEC_MAGIC)
		error_case("Error magic header");
	cor->heroes[i].name = check_name(fd, PROG_NAME_LENGTH);
	if (check_int(fd) != 0)
		error_case(ERROR_FILE);
	if ((cor->heroes[i].size = check_int(fd)) < 0 ||
			cor->heroes[i].size > CHAMP_MAX_SIZE)
		error_case("Error champion size");
	cor->heroes[i].comment = check_name(fd, COMMENT_LENGTH);
	if (check_int(fd) != 0)
		error_case(ERROR_FILE);
//	cor->heroes[i] = check_code(fd, cor->heroes[i].size);
	close(fd);
}

void    validate_heroes(t_cor *cor)
{
    int i;

    i = 0;
    while (i < cor->count_heroes)
        read_hero(cor, i++);
}
