NAME = streams.a
SOURCES = create_array_stream.c create_file_stream.c create_stream.c \
		noop_clear_elem.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS) 
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
