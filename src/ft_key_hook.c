/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:59:02 by lucas             #+#    #+#             */
/*   Updated: 2016/03/16 15:08:01 by lucas            ###   ########.fr       */
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


int		ft_key_hook(char *buffer, int *cursor, int maxlen)
{
	if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
		ft_exit(0);
	else if (buffer[0] == 113 && buffer[2] == 0) //Fleche haut
		ft_exit(0);
	else if (buffer[0] == 10 && buffer[2] == 0) //Fleche haut
        ft_exit(0);
	else if (buffer[0] == 27 && buffer[2] == 65) //Fleche haut
		ft_inc_cursor(cursor, maxlen, 1);
	else if (buffer[0] == 27 && buffer[2] == 66) //Fleche bas
		ft_inc_cursor(cursor, maxlen, 0);
	else if (buffer[0] == 27 && buffer[2] == 67) //Fleche droite
		ft_putstr("Droite\n");
	else if (buffer[0] == 27 && buffer[2] == 68) //Fleche gauche
		ft_putstr("Gauche\n");
	else if (buffer[0] == 32 && buffer[2] == 0)
		return (1);
	else
		printf("%d %d %d\n", buffer[0], buffer[1], buffer[2]);
	buffer[0] = 0;
	buffer[1] = 0;
	buffer[2] = 0;
	return (0);
}
