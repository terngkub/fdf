/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:43:59 by nkamolba          #+#    #+#             */
/*   Updated: 2018/12/09 13:21:29 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_sign(double n)
{
	if (n > 0)
		return (n);
	else if (n < 0)
		return (-n);
	return (0);
}

void	ft_swapint(int *n1, int *n2)
{
	int		temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
