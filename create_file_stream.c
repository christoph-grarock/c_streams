/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_stream.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:55:05 by cgrarock          #+#    #+#             */
/*   Updated: 2026/11/02 11:06:44 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"
#include "create_file_stream.h"

static int	file_has_next(void *context)
{
	t_file_context	*ctx;

	ctx = (t_file_context *)context;
	if (ctx->last_read == ctx->idx)
	{
		ctx->last_read = read(ctx->file_id, ctx->buffer, ctx->buffer_size);
		ctx->idx = 0;
	}
	return (ctx->idx < ctx->last_read);
}

static void	*file_get_next(void *context)
{
	t_file_context	*ctx;
	size_t			idx;

	ctx = (t_file_context *)context;
	assert(file_has_next(context));
	idx = ctx->idx;
	ctx->idx++;
	return (ctx->buffer + idx);
}

static void	file_destruct(void **context)
{
	t_file_context	**ctx;

	ctx = (t_file_context **)context;
	if ((*ctx)->on_destruct != NULL)
		(*ctx)->on_destruct((*ctx)->file_id);
	free((*ctx)->buffer);
	free(*ctx);
	*ctx = NULL;
}

static void	init_file_context(
				t_file_context **context,
				int fd,
				size_t buf_size,
				void (*on_destruct)(int fd))
{
	*context = malloc(sizeof(t_file_context));
	if (*context == NULL)
		return ;
	(*context)->buffer = malloc(sizeof(char) * buf_size);
	if ((*context)->buffer == NULL)
	{
		free(*context);
		*context = NULL;
		return ;
	}
	(*context)->file_id = fd;
	(*context)->buffer_size = buf_size;
	(*context)->on_destruct = on_destruct;
	(*context)->last_read = 0;
	(*context)->idx = 0;
}

t_stream	*create_file_stream(
				int fd,
				size_t buf_size,
				void (*on_destruct)(int fd))
{
	t_file_context	*context;
	t_stream		*stream;

	stream = get_stream_template();
	if (stream == NULL)
	{
		return (NULL);
	}
	init_file_context(&context, fd, buf_size, on_destruct);
	if (context == NULL)
	{
		free(stream);
		return (NULL);
	}
	stream->context = context;
	stream->destruct = &file_destruct;
	stream->get_next = &file_get_next;
	stream->has_next = &file_has_next;
	return (stream);
}
