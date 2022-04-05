/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:16:22 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/05 19:55:21 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;
	char	*bigc;

	bigc = (char *)big;
	len_little = ft_strlen(little);
	if (len_little == 0)
		return (bigc);
	i = 0;
	while (i < len && bigc[i] != '\0')
	{
		if (ft_strncmp(&bigc[i], little, len_little) == 0)
			return (&bigc[i]);
		i++;
	}
	printf("oiaaaaa %ld\n", i);
	return (NULL);
}
