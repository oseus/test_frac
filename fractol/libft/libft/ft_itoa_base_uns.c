/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base_uns.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 09:47:43 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 08:57:36 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base_uns(unsigned long long nb, int base)
{
	long long	rest;
	char		*ans;
	int			i;

	i = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	if (!(ans = (char*)malloc(sizeof(char) * 65)))
		return (NULL);
	while (nb != 0)
	{
		rest = nb % base;
		ans[i++] = rest > 9 ? rest - 10 + 'a' : rest + '0';
		nb /= base;
	}
	ans[i] = '\0';
	return (ft_strrev(ans));
}
