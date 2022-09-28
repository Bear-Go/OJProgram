ifeq (new,$(firstword $(MAKECMDGOALS)))
NAME := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
ifeq ($(NAME),)
$(error Need new name)
endif
endif

ifeq (clean,$(firstword $(MAKECMDGOALS)))
NAME := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
ifeq ($(NAME),)
$(error Need clean name)
endif
endif

ifeq (,$(firstword $(MAKECMDGOALS)))
$(error Only support target new and clean)
endif


$(eval $(NAME):;@:)

.PHONY: $(NAME)

new:
	mkdir $(NAME)
	cp -r ../module/* $(NAME)/

clean:
	rm -rf $(NAME)/


	
