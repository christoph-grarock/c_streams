/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stream_template.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:07:59 by cgrarock          #+#    #+#             */
/*   Updated: 2026/10/27 15:27:28 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"

t_stream	*create_stream_template(void)
{
	t_stream	*stream;

	stream = calloc(1, sizeof(t_stream));
	return (stream);
}
