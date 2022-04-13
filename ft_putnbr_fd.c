/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 07:01:44 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/13 06:29:07 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	s[11];
	int		i;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	s[10] = '\0';
	i = 10;
	while (n != 0)
	{
		i--;
		s[i] = (n % 10) + '0';
		n = n / 10;
	}
	ft_putstr_fd(&s[i], fd);
}
