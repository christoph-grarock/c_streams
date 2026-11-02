/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array_stream.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:46:58 by cgrarock          #+#    #+#             */
/*   Updated: 2026/10/27 14:33:02 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"
#include "create_array_stream.h"

static int	arr_has_next(void *context)
{
	t_arr_context	*ctx;

	ctx = (t_arr_context *)context;
	if (ctx == NULL)
		return (0);
	return (ctx->current_idx < ctx->elem_count);
}

static void	*arr_get_next(void *context)
{
	t_arr_context	*ctx;
	size_t			offset;

	ctx = (t_arr_context *)context;
	if (ctx == NULL)
		return (NULL);
	offset = ctx->elem_size * ctx->current_idx;
	ctx->current_idx += 1;
	return ((void *)(((char *)ctx->backing_arr) + offset));
}

static void	arr_destruct(void **context)
{
	t_arr_context	**ctx;

	ctx = (t_arr_context **)context;
	free((*ctx)->backing_arr);
	free((*ctx));
	*ctx = NULL;
}

t_stream	*create_array_stream(void *arr, size_t elem_size, size_t elem_count)
{
	t_arr_context	*context;
	t_stream		*stream;

	context = malloc(sizeof(t_arr_context));
	if (context == NULL)
		return (NULL);
	stream = get_stream_template();
	if (stream == NULL)
	{
		free(context);
		return (NULL);
	}
	context->backing_arr = arr;
	context->elem_size = elem_size;
	context->elem_count = elem_count;
	context->current_idx = 0;
	stream->destruct = &arr_destruct;
	stream->context = context;
	stream->get_next = &arr_get_next;
	stream->has_next = &arr_has_next;
	return (stream);
}
