/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 01:39:17 by feandrad          #+#    #+#             */
/*   Updated: 2023/03/12 04:56:49 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "../headers/so_long.h"

MU_TEST(open_window_return_1)
{
    t_x_obj window;
    
    int expected = 1;
    int actual = open_window(&window);

    mu_assert_int_eq(expected, actual);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(open_window_return_1);
}

int main(int argc, char *argv[])
{
	MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
