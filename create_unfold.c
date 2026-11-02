/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_unfold.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:22:30 by cgrarock          #+#    #+#             */
/*   Updated: 2026/11/02 10:41:32 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"
#include "create_unfold.h"

t_stream	*create_unfold(
				void *initial_state,
				void *(*get_next)(void *state),
				int (*has_next)(void *source),
				void (*destructor)(void **state))
{
	t_stream	*stream;

	stream = get_stream_template();
	stream->get_next = get_next;
	stream->has_next = has_next;
	stream->destruct = destructor;
	stream->context = initial_state;
	if (stream == NULL)
		return (NULL);
	return (stream);
}
