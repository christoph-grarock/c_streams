#include "streams.h"

t_stream *create_stream(void *context, void (*destruct)(void **), void *(*get_next)(void *), int (*has_next)(void *), void (*clear_elem)(void *))
{
	t_stream *stream;
	stream = malloc(sizeof(t_stream));
	if (stream == NULL)
		return NULL;
	stream->context = context;
	stream->destruct = destruct;
	stream->get_next = get_next;
	stream->has_next = has_next;
	stream->clear_elem = clear_elem;
	return (stream);
}
