#include "streams.h"

typedef struct s_arr_context
{
	void *backing_arr;
	size_t elem_size;
	size_t elem_count;
	size_t current_idx;
}	t_arr_context;

static int	arr_has_next(void *context)
{
	t_arr_context	*ctx;

	ctx = (t_arr_context *)context;
	if (ctx == NULL)
		return (0);
	return (ctx->current_idx < ctx->elem_count);
}

static void *arr_get_next(void *context)
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

static void arr_destruct(void **context)
{
	t_arr_context **ctx;

	ctx = (t_arr_context **)context;
	free((*ctx)->backing_arr);
	free((*ctx));
	*ctx = NULL;
}

t_stream *create_array_stream(void *arr, size_t elem_size, size_t elem_count)
{
	t_arr_context *context;

	context = malloc(sizeof(t_arr_context));
	if (context == NULL)
		return (NULL);
	context->backing_arr = arr;
	context->elem_size = elem_size;
	context->elem_count = elem_count;
	context->current_idx = 0;
	return (create_stream(context, &arr_destruct, &arr_get_next , &arr_has_next, &noop_clear_elem));
}
