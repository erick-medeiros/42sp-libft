/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:09 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/03 03:02:01 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

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
	name = "ft_isascii";
	list[0] = FUNC_TEST(ft_isascii('\n') != 0 && isascii('\n') != 0);
	list[1] = FUNC_TEST(ft_isascii(0) != 0 && isascii(1) != 0);
	list[2] = FUNC_TEST(ft_isascii(127) != 0 && isascii(127) != 0);
	list[3] = FUNC_TEST(ft_isascii(128) == 0 && isascii(128) == 0);
	list[4] = FUNC_TEST(ft_isascii(178) == 0 && isascii(178) == 0);
	ft_test(name, list, 5);
	name = "ft_isprint";
	list[0] = FUNC_TEST(ft_isprint('\n') == 0 && isprint('\n') == 0);
	list[1] = FUNC_TEST(ft_isprint(0) == 0 && isprint(1) == 0);
	list[2] = FUNC_TEST(ft_isprint(127) == 0 && isprint(127) == 0);
	list[3] = FUNC_TEST(ft_isprint(' ') != 0 && isprint(' ') != 0);
	list[4] = FUNC_TEST(ft_isprint('~') != 0 && isprint('~') != 0);
	ft_test(name, list, 5);
	name = "ft_strlen";
	list[0] = FUNC_TEST(ft_strlen("123") == strlen("123"));
	list[1] = FUNC_TEST(ft_strlen("") == strlen(""));
	ft_test(name, list, 2);

	name = "ft_memset";
	char memset_s1[10];
	char memset_s2[10];
	list[0] = FUNC_TEST(strcmp(ft_memset(memset_s1, 'f', 4), memset(memset_s2, 'f', 4)) == 0);
	ft_test(name, list, 1);

	name = "ft_bzero";
	char bzero_buffer1[10];
	char bzero_buffer2[10];
	memset(bzero_buffer1, 'a', 10);
	memset(bzero_buffer2, 'a', 10);
	ft_bzero(bzero_buffer1, 4);
	bzero(bzero_buffer2, 4);
	list[0] = FUNC_TEST(strncmp(bzero_buffer1, bzero_buffer1, 10)  == 0);
	list[1] = FUNC_TEST(bzero_buffer1[1] == '\0' && bzero_buffer2[1] == '\0');
	list[2] = FUNC_TEST(bzero_buffer1[5] == 'a' && bzero_buffer2[5] == 'a');
	ft_test(name, list, 3);
	return (0);
}
