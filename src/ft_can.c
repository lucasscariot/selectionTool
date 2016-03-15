/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:18:10 by lucas             #+#    #+#             */
/*   Updated: 2016/03/15 14:23:50 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_can()
{
	char           *name_term;
	struct termios term;
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	// remplis la structure termios des possibilités du terminal.
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}
