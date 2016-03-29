/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:18:10 by lucas             #+#    #+#             */
/*   Updated: 2016/03/29 15:10:18 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_can()
{
	char           *name_term;

	tcgetattr(0, &g_save);
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &g_term) == -1)
		return (-1);
	g_term.c_lflag &= ~(ICANON);
	g_term.c_lflag &= ~(ECHO);
	g_term.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSADRAIN, &g_term) == -1)
		return (-1);
	return (0);
}
