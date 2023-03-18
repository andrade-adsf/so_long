/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:36:40 by feandrad          #+#    #+#             */
/*   Updated: 2023/03/12 04:51:53 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>
# include <fcntl.h>
# include <X11/keysym.h>

typedef	struct s_x_obj
{
	void	*x_tab;
	void	*x_window;
} t_x_obj;

int	open_window(t_x_obj *window);
