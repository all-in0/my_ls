/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:16:48 by vnakonec          #+#    #+#             */
/*   Updated: 2016/11/23 17:45:22 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[b] != '\0')
	{
		s1[i] = s2[b];
		i++;
		b++;
	}
	s1[i] = '\0';
	return (s1);
}