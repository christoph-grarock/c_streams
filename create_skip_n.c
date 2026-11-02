/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_skip_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:53:25 by cgrarock          #+#    #+#             */
/*   Updated: 2026/11/02 11:07:56 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"
#include "create_skip_n.h"

static void	skip_destruct(void **context)
{
	t_skip_n	**ctx;	

	ctx = (t_skip_n **)context;
	destruct_stream(&((*ctx)->source));
	free(*ctx);
	*ctx = NULL;
}

//trying to get the next one before has_next has been called is deemed invalid
static void	*skip_get_next(void *context)
{
	t_skip_n	*ctx;
	t_stream	*source;

	ctx = (t_skip_n *)context;
	source = ctx->source;
	assert(skip_has_next(context));
	ctx->idx++;
	return (source->get_next(source->context));
}

static int	skip_has_next(void *context)
{
	t_skip_n	*ctx;
	t_stream	*source;

	ctx = (t_skip_n *)context;
	source = ctx->source;
	while (ctx->idx < ctx->skip)
	{
		if (!source->has_next(source->context))
			return (0);
		ctx->idx++;
	}
	return (1);
}

t_stream	*create_skip_n(size_t n, t_stream *source)
{
	t_skip_n	*context;
	t_stream	*stream;

	context = malloc(sizeof(t_skip_n));
	if (context == NULL)
		return (NULL);
	stream = get_stream_template();
	if (stream == NULL)
	{
		free(context);
		return (NULL);
	}
	context->skip = n;
	context->idx = 0;
	context->source = source;
	stream->context = context;
	stream->destruct = &skip_destruct;
	stream->has_next = &skip_has_next;
	stream->get_next = &skip_get_next;
	return (stream);
}
