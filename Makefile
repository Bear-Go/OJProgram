ifeq ($(NAME),)
ifneq (clean,$(firstword $(MAKECMDGOALS)))
$(error Only support target clean in main directory, please make others in sub-directory)
endif
endif

SRCS	:= $(shell find . -name "*.cpp")
DEPS	:= $(SRCS)
CFLAGS 	+=
OUTS	:= $(shell find -iname "*.out")

.PHONY: all clean

$(NAME): $(DEPS)
	g++ $(CFLAGS) $(SRCS) -o $@ && ./$@

clean:
	rm -f $(OUTS)