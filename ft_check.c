/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:21:37 by rfork             #+#    #+#             */
/*   Updated: 2019/11/30 18:52:11 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char *tmp)
{
	int ret;
	int count;
	int dve_grani;

	ret = -1;
	count = 0;
	dve_grani = 0;
	count = ft_check_2(tmp, ret, count, dve_grani);
	return (count);
}

int		ft_check_2(char *tmp, int ret, int count, int dve_grani)
{
	int kol_resh;

	kol_resh = 0;
	while (tmp[++ret])
	{
		if (tmp[ret] == '.' || tmp[ret] == '#' || check_4(tmp, ret, count, 0))
		{
			if (tmp[ret] == '#')
			{
				dve_grani = ft_check_3(ret, tmp, dve_grani, count);
				if (++kol_resh > 4)
					ft_error(0);
			}
			if (check_4(tmp, ret, count, 1))
			{
				ret = ret + 2;
				dve_grani = 0;
				kol_resh = 0;
				count++;
			}
		}
		else
			ft_error(0);
	}
	return (count);
}

int		ft_check_3(int ret, char *tmp, int dve_grani, int count)
{
	if (!(tmp[ret - 1] == '#' || tmp[ret + 1] == '#' || tmp[ret - 5] == '#'
		|| tmp[ret + 5] == '#'))
		ft_error(0);
	if ((tmp[ret - 1] == '#' && tmp[ret + 1] == '#')
		|| (tmp[ret - 5] == '#' && tmp[ret + 5] == '#')
		|| (tmp[ret - 5] == '#' || tmp[ret - 1] == '#')
		|| (tmp[ret - 5] == '#' || tmp[ret + 1] == '#')
		|| (tmp[ret - 1] == '#' || tmp[ret + 5] == '#')
		|| (tmp[ret + 1] == '#' || tmp[ret + 5] == '#'))
		dve_grani++;
	if (tmp[ret] == '\n' && tmp[ret + 1] == '\n' && (ret - count + 1) % 5 == 0
		&& !dve_grani)
		ft_error(0);
	return (dve_grani);
}

int		check_4(char *tmp, int ret, int count, int check)
{
	if (check == 1)
	{
		if (tmp[ret] == '\n' && tmp[ret + 1] == '\n'
			&& (ret - count + 1) % 5 == 0)
			return (1);
	}
	else if (tmp[ret] == '\n' && (ret - count + 1) % 5 == 0)
		return (1);
	return (0);
}

/*
** ft_check_2:
** 		первый if: проверка на правильность символов
**
** ft_check_3:
** 		первый if: проверка на наличее соединений гранями
** 		второй if: проверка на наличие нескольких соединений граней
** 		третий if: вывод ошибки по граням
*/
