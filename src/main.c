/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/15 10:36:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
int		ft_key_hook();

int		ft_exit(int i)
{
	struct termios term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	exit(i);
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
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
	ft_aff(av, env);
	ft_key_hook();
	return (0);
}

int     ft_key_hook()
{
	char     buffer[3];

	while (read(0, buffer, 3))
	{
		if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
			ft_exit(0);
		else if (buffer[0] == 27 && buffer[2] == 65) //Fleche haut
			ft_putstr("Haut\n");
		else if (buffer[0] == 27 && buffer[2] == 66) //Fleche bas
			ft_putstr("Bas\n");
		else if (buffer[0] == 27 && buffer[2] == 67) //Fleche droite
			ft_putstr("Droite\n");
		else if (buffer[0] == 27 && buffer[2] == 68) //Fleche gauche
			ft_putstr("Gauche\n");
		else
			printf("%d %d %d\n", buffer[0], buffer[1], buffer[2]);
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
	}
	return (0);
}
