#ifndef STREAMS_H
#define STREAMS_H
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_stream
{
	void	*context;
	//these functions get called with the context of the stream
	void	(*destruct)(void **);
	void	*(*get_next)(void *);
	int		(*has_next)(void *);
	//this function gets called with the element returned by get_next, rather than the context
	//performs cleanup operations, like freeing the memory if necessary, otherwise a noop function should be set for this
	void	(*clear_elem)(void *);
} t_stream;

t_stream *create_stream(void *context, void (*destruct)(void **), void *(*get_next)(void *), int (*has_next)(void *), void (*clear_elem)(void *));
t_stream *create_array_stream(void *arr, size_t elem_size, size_t elem_count);
t_stream *create_file_stream(int fd, size_t buf_size);
//t_stream *map_stream(t_stream *source, void (*destruct)(void *), void *(*mapper)(void), void *context);
t_stream *take_n(t_stream *source);
t_stream *skip_n(t_stream *source);
void	noop_clear_elem(void *);
#endif
