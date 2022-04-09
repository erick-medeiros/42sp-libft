/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 07:01:44 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/09 07:08:08 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_putnbr_fd_topositive(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		cpn;
	char	s[12];

	cpn = n;
	s[11] = '\0';
	i = 10;
	while ((i != 0 && n != 0) || (i == 10 && n == 0))
	{
		s[i] = ft_putnbr_fd_topositive(n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (cpn < 0)
		s[i] = '-';
	else
		i++;
	write(fd, &s[i], 12 - i);
}
