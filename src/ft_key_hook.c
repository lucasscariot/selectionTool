/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:59:02 by lucas             #+#    #+#             */
/*   Updated: 2016/03/15 15:04:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_key_hook(char *buffer, int *cursor)
{
	if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
		ft_exit(0);
	else if (buffer[0] == 27 && buffer[2] == 65) //Fleche haut
		*cursor = *cursor - 1;
	else if (buffer[0] == 27 && buffer[2] == 66) //Fleche bas
		*cursor = *cursor + 1;
	else if (buffer[0] == 27 && buffer[2] == 67) //Fleche droite
		ft_putstr("Droite\n");
	else if (buffer[0] == 27 && buffer[2] == 68) //Fleche gauche
		ft_putstr("Gauche\n");
	else
	{
		//printf("%d %d %d\n", buffer[0], buffer[1], buffer[2]);
	}
	buffer[0] = 0;
	buffer[1] = 0;
	buffer[2] = 0;
	return (0);
}
