/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:46:35 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/09 06:08:12 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_topositive(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	int		cpn;
	char	s[12];
	char	*r;

	cpn = n;
	s[11] = '\0';
	i = 10;
	while ((i != 0 && n != 0) || (i == 10 && n == 0))
	{
		s[i] = ft_itoa_topositive(n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (cpn < 0)
		s[i] = '-';
	else
		i++;
	r = ft_strdup(&s[i]);
	if (r == NULL)
		return (NULL);
	return (r);
}
