/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streams.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:49:55 by cgrarock          #+#    #+#             */
/*   Updated: 2026/11/02 10:54:42 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAMS_H
# define STREAMS_H
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <assert.h>

typedef struct s_stream
{
	void	*context;
	//these functions get called with the context of the stream
	void	(*destruct)(void **);
	//get next also performs cleanup of the previously returned value if need be
	void	*(*get_next)(void *);
	int		(*has_next)(void *);
}	t_stream;

t_stream	*get_stream_template(void);
t_stream	*create_array_stream(void *arr, size_t elem_size,
				size_t elem_count);
t_stream	*create_file_stream(
				int fd,
				size_t buf_size,
				void (*on_destruct)(int fd));
void		destruct_stream(t_stream **stream);
t_stream	*create_map_stream(t_stream *source, void *(*mapper)(void *),
				void (*clear_mapper_elem)(void *));
t_stream	*create_take_n(size_t n, t_stream *source);
t_stream	*create_skip_n(size_t n, t_stream *source);
t_stream	*create_unfold(
				void *initial_state,
				void *(*get_next)(void *state),
				int (*has_next)(void *source),
				void (*destructor)(void **state));
#endif
