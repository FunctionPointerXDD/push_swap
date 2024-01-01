/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:16:44 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/28 20:24:02 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	free_split_data(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
		free(argv[i++]);
	free(argv);
	return (-1);
}

int	bonus_free(char *data)
{
	free(data);
	return (-1);
}
