#include "streams.h"
typedef struct s_file_context
{
	int		file_id;
	size_t 	buffer_size;
	char 	*buffer;
	size_t	last_read;
	size_t	idx;
} t_file_context;

static int file_has_next(void *context)
{
	t_file_context	*ctx;

	ctx = (t_file_context *)context;
	if (ctx == NULL)
		return (0);
	if (ctx->last_read == ctx->idx)
	{
		ctx->last_read = read(ctx->file_id, ctx->buffer, ctx->buffer_size);
		ctx->idx = 0;
	}
	return (ctx->idx < ctx->last_read);
}

static void *file_get_next(void *context)
{
	t_file_context	*ctx;
	size_t			idx;

	ctx = (t_file_context *)context;
	if (ctx == NULL)
		return (NULL);
	idx = ctx->idx;
	ctx->idx++;
	return (ctx->buffer + idx);
}

static void file_destruct(void **context)
{
	t_file_context **ctx;

	ctx = (t_file_context **)context;
	free((*ctx)->buffer);
	free(*ctx);
	*ctx = NULL;
}

t_stream	*create_file_stream(int fd, size_t buf_size)
{
	t_file_context	*context;
	
	context = malloc(sizeof(t_file_context));
	if (context == NULL)
		return (NULL);
	context->file_id = fd;
	context->buffer_size = buf_size;
	context->buffer = malloc(sizeof(char) * buf_size);
	if (context->buffer == NULL)
	{
		free(context);
		return (NULL);
	}
	context->last_read = 0;
	context->idx = 0;
	return (create_stream(context, &file_destruct, &file_get_next, &file_has_next, &noop_clear_elem));
}
