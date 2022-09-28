ifeq ($(NAME),)
$(error Should make in sub-directory)
endif

SRCS	:= $(shell find . -name "*.cpp")
DEPS	:= $(SRCS)
CFLAGS 	+=

.PHONY: all clean

$(NAME): $(DEPS)
	g++ $(CFLAGS) $(SRCS) -o $@ && ./$@

clean:
	rm -f $(NAME)