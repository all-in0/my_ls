/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:26:24 by vnakonec          #+#    #+#             */
/*   Updated: 2017/10/26 23:27:58 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			open_dir(t_env *e)
{
	e->dirp = NULL;
	e->dirp = opendir(".");
	if (e->dirp == NULL)
		return (0);
	else
		return (1);
}

int			prm_err(t_env *e)
{
	ft_putstr("ft_ls: ");
	ft_putstr(e->list->dir);
	ft_putendl(":Permission denied");
	return (-1);
}

int			main(int ac, char **av)
{
	int		i;
	t_env	e;
	t_dir	*tmp;

	i = 1;
	e.list = NULL;
	while (i < ac)
	{
		if (av[i][0] != '-' && (tmp = (t_dir *)malloc(sizeof(t_dir))))
		{
			tmp->dir = av[i];
			tmp->next = e.list;
			e.list = tmp;
		}
		if (av[i][0] == '-')
			check_flags(&e, av[i]);
		i++;
	}
	if (e.list == NULL)
		do_lst(&e);
	ft_ls(&e);
	return (1);
}
