/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:22:18 by vnakonec          #+#    #+#             */
/*   Updated: 2017/10/26 23:37:15 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_file_check(t_env *e)
{
	if (open_dir(e))
	{
		while ((e->dp = readdir(e->dirp)) != NULL)
		{
			lstat(e->dp->d_name, &e->sb);
			if (S_ISREG(e->sb.st_mode) &&
					ft_strcmp(e->dp->d_name, e->list->dir) == 0)
			{
				ft_putendl(e->dp->d_name);
				return (1);
			}
			else if (!ft_strcmp(e->dp->d_name, e->list->dir))
				return (prm_err(e));
		}
		ft_putstr("ft_ls: ");
		ft_putstr(e->list->dir);
		ft_putendl(":Permission denied");
		return (-1);
	}
	return (0);
}

void		print_lnk(t_dir *tmp, char *b)
{
	size_t	l;

	ft_putstr(" -> ");
	l = (size_t)readlink(tmp->full_path, b, 64);
	b[l] = '\0';
	ft_putstr(b);
}

void		get_time(struct stat fstat, t_dir *tmp)
{
	char	buff[13];
	char	*str;
	char	buf[64];

	(void)fstat;
	str = ctime(&tmp->time);
	ft_memcpy(buff, &str[4], 12);
	buff[12] = '\0';
	ft_putstr(buff);
	ft_putstr(" ");
	ft_putstr(tmp->dir);
	if (S_ISLNK(fstat.st_mode))
		print_lnk(tmp, buf);
}

void		time_sort(t_dir **head, int done)
{
	t_dir	**src;
	t_dir	*tmp;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		tmp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if ((tmp->time < next->time) && (done = 0) == 0)
			{
				tmp->next = next->next;
				next->next = tmp;
				*src = next;
			}
			src = &tmp->next;
			tmp = next;
			next = next->next;
		}
	}
}

void		print_l(t_dir *list)
{
	struct stat	fstat;
	char		*size;
	size_t		len;
	size_t		c;
	t_dir		*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		c = 5;
		lstat(tmp->full_path, &fstat);
		perm_dir_link(tmp, fstat);
		ft_putnbr(fstat.st_nlink);
		prt_user(fstat);
		size = ft_itoa(fstat.st_size);
		len = ft_strlen(size);
		while (c-- > len)
			ft_putchar(' ');
		ft_putstr(ft_strjoin(size, "  "));
		get_time(fstat, tmp);
		tmp = tmp->next;
		if (tmp != NULL)
			ft_putchar('\n');
	}
}
