NAME = streams.a
SOURCES = create_array_stream.c create_file_stream.c get_stream_template.c\
		noop_clear_elem.c create_take_n.c destruct_stream.c create_skip_n.c\
		create_map_stream.c create_unfold.c
PRIVATE_HEADERS_FOLDER = private_headers
OUTPUT_FOLDER = output
HEADERS_FOLDER = public_headers
CFLAGS = -Wall -Werror -Wextra -I$(PRIVATE_HEADERS_FOLDER) -I$(HEADERS_FOLDER)
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	test -d $(OUTPUT_FOLDER) || mkdir $(OUTPUT_FOLDER)
	ar -rcs $(OUTPUT_FOLDER)/$(NAME) $(OBJECTS) 
	cp $(HEADERS_FOLDER)/* $(OUTPUT_FOLDER)/
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf $(OUTPUT_FOLDER)/
re: fclean all

.PHONY: all clean fclean re
