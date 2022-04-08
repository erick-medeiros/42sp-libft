/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:12:23 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/08 15:41:57 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	i2;
	size_t	count;
	char	**splited;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (i > 0 && s[i] != c && s[i - 1] == c))
				count++;
		i++;
	}
	//printf("\n\n>>> %ld\n\n", count);
	//splited = (char **) malloc(sizeof(char *) * (count + 1));
	splited = (char **) calloc(sizeof(char *), (count + 1));
	if (splited == NULL)
		return (NULL);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			i2 = 0;
			while (s[i + i2] != c)
				i2++;
			//splited[count] = (char *) malloc(sizeof(char) * (i2 + 1));
			//printf("\n%ld %ld\n", count, i2);
			splited[count] = (char *) calloc(sizeof(char), (i2 + 1));
			if (splited[count] == NULL)
				return (NULL);
			ft_strlcpy(splited[count], &s[i], i2 + 1);
			count++;
			i = i + i2;
		}
		i++;
	}
	//splited[count] = NULL;
	return (splited);
}
