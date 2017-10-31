/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:28:09 by vnakonec          #+#    #+#             */
/*   Updated: 2017/10/26 23:29:32 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		revers_list(t_dir **head_ref, t_dir *prev)
{
	t_dir	*nxt;
	t_dir	*dirs;

	dirs = *head_ref;
	while (dirs != NULL)
	{
		nxt = dirs->next;
		dirs->next = prev;
		prev = dirs;
		dirs = nxt;
	}
	*head_ref = prev;
}

void		ft_ls(t_env *e)
{
	t_dir	*tp;

	tp = e->list;
	while (tp != NULL)
	{
		make_ls(tp->dir, e);
		tp = tp->next;
	}
}

void		do_lst(t_env *e)
{
	e->list = (t_dir *)malloc(sizeof(t_dir));
	e->list->dir = ".";
	e->list->next = NULL;
}

void		inv_ar(char *s)
{
	ft_putstr(s);
	ft_putendl(": Wrong flag");
	exit(1);
}

int			check_flags(t_env *e, char *arg)
{
	int		x;

	x = 1;
	while (arg[x] != '\0')
	{
		if (arg[x] == 'l')
			e->fl[0] = 1;
		else if (arg[x] == 'a')
			e->fl[1] = 1;
		else if (arg[x] == 'r')
			e->fl[2] = 1;
		else if (arg[x] == 't')
			e->fl[3] = 1;
		else if (arg[x] == 'R')
			e->fl[4] = 1;
		else
			inv_ar(arg);
		x++;
	}
	return (1);
}
