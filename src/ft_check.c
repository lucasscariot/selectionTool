/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:34:36 by lscariot          #+#    #+#             */
/*   Updated: 2016/03/16 14:39:57 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_check(t_files *files, int cursor)
{
	while (cursor--)
		files = files->next;
	if (files->chckd)
		files->chckd = 0;
	else
		files->chckd = 1;
	return (1);
}
