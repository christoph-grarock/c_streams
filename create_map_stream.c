/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_stream.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:09:03 by cgrarock          #+#    #+#             */
/*   Updated: 2026/11/02 11:06:03 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"
#include "create_map_stream.h"

static int	map_has_next(void *context)
{
	t_stream	*source;

	source = ((t_map *)context)->source;
	return (source->has_next(source->context));
}

static void	*map_get_next(void *context)
{
	t_map	*ctx;

	ctx = (t_map *)context;
	assert(map_has_next(ctx->source->context));
	if (ctx->last_elem != NULL)
		ctx->clear_mapper_elem(ctx->last_elem);
	ctx->last_elem = ctx->mapper(ctx->source->get_next(ctx->source->context));
	return (ctx->last_elem);
}

static void	map_destruct(void **context)
{
	t_map	**ctx;

	ctx = (t_map **)context;
	(*ctx)->clear_mapper_elem((*ctx)->last_elem);
	destruct_stream(&((*ctx)->source));
	free(*ctx);
	*ctx = NULL;
}

t_stream	*create_map_stream(t_stream *source, void *(*mapper)(void *),
				void (*clear_mapper_elem)(void *))
{
	t_map		*context;
	t_stream	*stream;

	context = malloc(sizeof(t_map));
	if (context == NULL)
		return (NULL);
	stream = get_stream_template();
	if (stream == NULL)
	{
		free(context);
		return (NULL);
	}
	context->mapper = mapper;
	context->clear_mapper_elem = clear_mapper_elem;
	context->source = source;
	context->last_elem = NULL;
	stream->context = context;
	stream->destruct = &map_destruct;
	stream->get_next = &map_get_next;
	stream->has_next = &map_has_next;
	return (stream);
}
