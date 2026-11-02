/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_stream.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:49:45 by cgrarock          #+#    #+#             */
/*   Updated: 2026/10/22 15:49:47 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"

void	destruct_stream(t_stream **stream)
{
	(*stream)->destruct((*stream)->context);
	free(*stream);
	*stream = NULL;
}
