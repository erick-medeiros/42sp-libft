/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 07:01:44 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/11 04:37:50 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	s[10];
	int		i;

	if (n == 0)
		return (ft_putchar_fd('0', fd));
	if (n < 0)
		ft_putchar_fd('-', fd);
	s[9] = '\0';
	i = 8;
	while (n != 0)
	{
		s[i] = n % 10;
		if (s[i] < 0)
			s[i] = s[i] * -1;
		s[i] = s[i] + '0';
		n = n / 10;
		i--;
	}
	i++;
	ft_putstr_fd(&s[i], fd);
}
