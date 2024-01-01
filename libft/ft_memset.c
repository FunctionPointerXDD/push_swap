/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:59:50 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/14 19:50:31 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ub;
	unsigned char	uc;

	ub = (unsigned char *)b;
	uc = (unsigned char)c;
	while (len--)
		*ub++ = uc;
	return (b);
}
