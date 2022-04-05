/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:09:12 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/05 20:50:47 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sin;
	int	val;

	i = 0;
	sin = 1;
	val = 0;
	while (ft_isspace(nptr[i]) || nptr[i] == '+')
		i++;
	if (nptr[i] == '-')
	{
		sin = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		val = val * 10;
		val += nptr[i] - '0';
		i++;
	}
	if (val > 0)
		val = val * sin;
	return (val);
}
