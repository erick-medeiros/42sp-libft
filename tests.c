/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:09 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/02 23:56:29 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

#define STATUS_SUCESS 0
#define STATUS_ERROR 1
#define MAX_TESTS 100
#define FUNC_TEST(condition) (condition ? STATUS_SUCESS : STATUS_ERROR)

void	ft_test(char *name_test, char *list_test, int ntests)
{
	int		i;
	int		status;

	status = STATUS_SUCESS;
	i = 0;
	while (i < ntests && status == STATUS_SUCESS)
	{
		if (list_test[i] == STATUS_ERROR)
		{
			status = STATUS_ERROR;
			break ;
		}
		i++;
	}
	if (status == STATUS_ERROR)
		printf("%s --- KO\nError Test %d\n", name_test, i);
	else
		printf("%s OK\n", name_test);
}

int	main(void)
{
	char	*name;
	char	list[MAX_TESTS];
	
	name = "ft_isalpha";
	list[0] = FUNC_TEST(ft_isalpha('a') != 0 && isalpha('a') != 0);
	list[1] = FUNC_TEST(ft_isalpha('A') != 0 && isalpha('A') != 0);
	list[2] = FUNC_TEST(ft_isalpha('z') != 0 && isalpha('z') != 0);
	list[3] = FUNC_TEST(ft_isalpha('Z') != 0 && isalpha('Z') != 0);
	list[4] = FUNC_TEST(ft_isalpha(1) == isalpha(1));
	list[5] = FUNC_TEST(ft_isalpha('\n') == isalpha('\n'));
	ft_test(name, list, 6);
	name = "ft_isdigit";
	list[0] = FUNC_TEST(ft_isdigit('\n') == isdigit('\n'));
	list[1] = FUNC_TEST(ft_isdigit(1) == isdigit(1));
	list[2] = FUNC_TEST(ft_isdigit('a') == isdigit('a'));
	list[3] = FUNC_TEST(ft_isdigit('1') != 0 && isdigit('1') != 0);
	ft_test(name, list, 4);
	name = "ft_isalnum";
	list[0] = FUNC_TEST(ft_isalnum('\n') == isalnum('\n'));
	list[1] = FUNC_TEST(ft_isalnum(1) == isalnum(1));
	list[2] = FUNC_TEST(ft_isalnum('a') != 0 && isalnum('a') != 0);
	list[3] = FUNC_TEST(ft_isalnum('1') != 0 && isalnum('1') != 0);
	ft_test(name, list, 4);
	return (0);
}
