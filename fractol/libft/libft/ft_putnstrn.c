/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnstrn.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 15:47:10 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 08:56:28 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnstrn(char *str, int n1, int n2)
{
	int		a;

	if (str)
	{
		a = n1;
		while (a < n2 && str[a])
			ft_putchar(str[a++]);
	}
}
