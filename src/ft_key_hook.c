/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:59:02 by lucas             #+#    #+#             */
/*   Updated: 2016/03/17 15:21:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_inc_cursor(int *cursor, int maxlen, int version)
{
	if (version)
	{
		if (*cursor > 0)
			*cursor = *cursor - 1;
		else
			*cursor = maxlen;
	}
	else
	{
		if (*cursor < maxlen)
			*cursor = *cursor + 1;
		else
			*cursor = 0;
	}
}

int		ft_key_hook(t_files *fil, char *buff, int *cursor, int maxlen)
{
	if (buff[0] == 27 && buff[1] == 0 && buff[2] == 0)
		ft_exit(0);
	else if (buff[0] == 113 && buff[2] == 0)
		ft_exit(0);
	else if (buff[0] == 10 && buff[2] == 0)
        ft_end(fil);
	else if (buff[0] == 27 && buff[2] == 65) //Fleche haut
		ft_inc_cursor(cursor, maxlen, 1);
	else if (buff[0] == 27 && buff[2] == 66) //Fleche bas
		ft_inc_cursor(cursor, maxlen, 0);
	else if (buff[0] == 32 && buff[2] == 0)
	{
		ft_check(fil, *cursor);
		ft_inc_cursor(cursor, maxlen, 0);
	}
	return (0);
}
