/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabidar <aabidar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:04:37 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/18 13:59:45 by aabidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

static int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

static int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static double	ft_calc_float(char *s, int i)
{
	double	res;
	int		exp;

	res = 0;
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] == '.' && ft_isdigit(s[i + 1]))
	{
		i++;
		exp = -1;
		while (ft_isdigit(s[i]))
		{
			res = res + pow(10, exp) * (s[i] - 48);
			exp--;
			i++;
		}
	}
	return (res);
}

double	ft_atof(char *s)
{
	double	res;
	int		i;
	double	sg;

	i = 0;
	sg = 1;
	res = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sg = -1;
		i++;
	}
	res = ft_calc_float(s, i);
	return (res * sg);
}
