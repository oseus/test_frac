/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 11:14:24 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 08:07:38 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (a == n)
		return (0);
	while (s1[a] && s2[a] && s1[a] == s2[a] && a < (n - 1))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
