/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabidar <aabidar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:22 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/20 11:20:19 by aabidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	ft_putchar(char c)
{
	write(2, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
}

static int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int	check_constant(char *x)
{
	int	i;
	int	pts;

	i = 0;
	pts = 0;
	if ((x[i] == '-' || x[i] == '+') && x[i + 1] && ft_isdigit(x[i + 1]))
		i++;
	while (x[i])
	{
		if (!(ft_isdigit(x[i]) || (!pts && x[i] == '.')))
			return (0);
		if (x[i] == '.')
			pts = 1;
		i++;
	}
	return (1);
}
