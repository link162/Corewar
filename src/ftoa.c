/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 08:55:42 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/04 20:18:52 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h> 
  
void	reverse(char *str, int len) 
{ 
    int i;
    int	j;
    int	temp;
	
	j = len - 1;
	i = 0;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int		inttostr(int x, char str[], int d)
{
	int i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

void		ftoa(float n, char *res, int afterpoint)
{
	int		ipart;
	float	fpart;
	int		i;

	ipart = (int)n;
	fpart = n - (float)ipart;
	i = inttostr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * pow(10, afterpoint);
		inttostr((int)fpart, res + i + 1, afterpoint);
	}
}
