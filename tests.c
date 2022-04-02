/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:09 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/02 23:35:31 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

# define STATUS_SUCESS 0
# define STATUS_ERROR 1
# define MAX_TESTS 100
# define FUNC_TEST(condition) (condition ? STATUS_SUCESS : STATUS_ERROR)

typedef struct t_test {
	char *name;
	int	list[MAX_TESTS];
	int	status;
} t_test;

void	ft_test(t_test test_func, int ntests)
{
	int	i;
	int status;
	char *name_test = test_func.name;
	int *list_test = test_func.list;

	status = STATUS_SUCESS;
	i = 0;
	while (i < ntests && status == STATUS_SUCESS)
	{
		if (list_test[i] == STATUS_ERROR)
		{
			status = STATUS_ERROR;
			break;
		}
		i++;
	}
	if (status == STATUS_ERROR) {
		printf("%s --- KO\n", name_test);
		printf("Error Test %d\n", i);
	} else {
		printf("%s OK\n", name_test);
	}
}

int	main(void)
{
	// ft_isalpha
	t_test test_isalpha;
	test_isalpha.name = "ft_isalpha";
	test_isalpha.list[0] = FUNC_TEST(ft_isalpha('a') != 0 && isalpha('a') != 0);
	test_isalpha.list[1] = FUNC_TEST(ft_isalpha('A') != 0 && isalpha('A') != 0);
	test_isalpha.list[2] = FUNC_TEST(ft_isalpha('z') != 0 && isalpha('z') != 0);
	test_isalpha.list[3] = FUNC_TEST(ft_isalpha('Z') != 0 && isalpha('Z') != 0);
	test_isalpha.list[4] = FUNC_TEST(ft_isalpha(1) == isalpha(1));
	test_isalpha.list[5] = FUNC_TEST(ft_isalpha('\n') == isalpha('\n'));
	ft_test(test_isalpha, 6);
	// ft_isdigit
	t_test test_isdigit;
	test_isdigit.name = "ft_isdigit";
	test_isdigit.list[0] = FUNC_TEST(ft_isdigit('\n') == isdigit('\n'));
	test_isdigit.list[1] = FUNC_TEST(ft_isdigit(1) == isdigit(1));
	test_isdigit.list[2] = FUNC_TEST(ft_isdigit('a') == isdigit('a'));
	test_isdigit.list[3] = FUNC_TEST(ft_isdigit('1') != 0 && isdigit('1') != 0);
	ft_test(test_isdigit, 4);
	return (0);
}
