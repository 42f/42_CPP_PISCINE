EOC = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m

NAME := cpp06_00
INCLUDES = ./includes
SRCS_DIR = ./srcs
CC = clang++
OBJ_DIR = ./objs_$(NAME)/

CFLAGS += -std=c++98
CFLAGS += -Wall
CFLAGS += -Wextra
# CFLAGS += -fPIC

ifeq ($(unused), 1)
	CFLAGS += -Wno-unused
endif

ifeq ($(help), 1)
	CFLAGS += -Wconversion
else ifeq ($(help), 2)
	CFLAGS += -Wsuggest-attribute=pure
else ifeq ($(help), 3)
	CFLAGS += -Wsuggest-attribute=const
else ifeq ($(help), 4)
	CFLAGS += -Wsuggest-attribute=noreturn
else ifeq ($(help), 5)
	CFLAGS += -fsanitize-undefined-trap-on-error
else ifneq ($(no_error), 1)
	CFLAGS += -Werror
endif

ifeq ($(debug), 1)
	CFLAGS += -g3
else ifeq ($(debug), 2)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
else ifeq ($(debug), 3)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
	CFLAGS += -Wpadded
else ifeq ($(debug), 4)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
	CFLAGS += -Wpadded
	ifneq ($(CC), gcc)
		CFLAGS += -Weverything
	endif
endif

ifeq ($(opti), 1)
	CFLAGS += -O3
endif

ifeq ($(debug_mode), 1)
	CFLAGS += -D DEBUG_MODE=1
endif

HEADER += ./header.hpp

SRCS += ./main.cpp

vpath %.cpp ./srcs
vpath %.hpp ./includes

OBJS = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS))

all :
	$(MAKE) $(NAME)
	@echo
	@echo

$(OBJS): $(OBJ_DIR)%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $<  -I $(INCLUDES) -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDES) -o $@
	@echo "🎉 \033[32m$@ is ready !\033[0m ✅"

$(OBJ_DIR):
	@mkdir -p $@

FORCE :

clean :
	$(RM) -R $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME) output.log

re : fclean
	@$(MAKE)

f : all
	@echo
	@echo
	@./$(NAME)

cmp: all
	./$(NAME) > output.log
	@echo "\n 🎉  \033[32m Colordiff. Reference on the left, my output on the right\033[0m"
	diff -y ./subject.log ./output.log

.PHONY: all clean fclean mclean re FORCE cmp
#.SILENT:
