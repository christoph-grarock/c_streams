/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_take_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:45:02 by cgrarock          #+#    #+#             */
/*   Updated: 2026/10/27 14:32:30 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"
#include "create_take_n.h"

static void	take_destruct(void **context)
{
	t_take_n	**ctx;

	ctx = (t_take_n **)context;
	destruct_stream(&((*ctx)->source));
	free(*ctx);
	*ctx = NULL;
}

static void	*take_get_next(void *context)
{
	t_take_n	*ctx;

	ctx = (t_take_n *)context;
	if (ctx->idx < ctx->take)
	{
		ctx->idx++;
		return (ctx->source->get_next(ctx->source->context));
	}
	ctx->idx++;
	return (NULL);
}

static int	take_has_next(void *context)
{
	t_take_n	*ctx;
	t_stream	*source;

	ctx = (t_take_n *)context;
	source = ctx->source;
	return ((ctx->idx < ctx->take) && source->has_next(source->context));
}

t_stream	*create_take_n(size_t n, t_stream *source)
{
	t_take_n	*context;
	t_stream	*stream;

	context = malloc(sizeof(t_take_n));
	if (context == NULL)
		return (NULL);
	stream = get_stream_template();
	if (stream == NULL)
	{
		free(context);
		return (NULL);
	}
	context->take = n;
	context->idx = 0;
	context->source = source;
	stream->context = context;
	stream->destruct = &take_destruct;
	stream->get_next = &take_get_next;
	stream->has_next = &take_has_next;
	return (stream);
}
