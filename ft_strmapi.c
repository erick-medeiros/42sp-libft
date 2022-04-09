/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:11:44 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/09 06:30:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;

	r = ft_strdup(s);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (r[i] != '\0')
	{
		r[i] = f(i, r[i]);
		i++;
	}
	return (r);
}
