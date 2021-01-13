EOC = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m

NAME := fixed
INCLUDES = ./
SRCS_DIR = ./
CC = clang++
OBJ_DIR = ./objs_$(NAME)/

CFLAGS += -std=c++98
CFLAGS += -Wall
CFLAGS += -Wextra
# CFLAGS += -fPIC

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

HEADER += Fixed.hpp

SRCS += main.cpp
SRCS += Fixed.cpp

vpath %.cpp ./

OBJS = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS))

all :
	$(MAKE) $(NAME)

$(OBJS): $(OBJ_DIR)%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $<  -I $(INCLUDES) -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDES) -o $@
	@echo "\n 🎉  \033[32m$@ is ready !\033[0m ✅  \n"

$(OBJ_DIR):
	@mkdir -p $@

FORCE :

clean :
	$(RM) -R $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean
	@$(MAKE)

cmp: all
	@echo "\n ⏱  \033[32m Executing the program with piped stdout to file...\033[0m"
	./$(NAME) > bvalette.log
	@echo "\n 🗂  \033[32m Removing timestamp for comparaison...\033[0m"
	cat ./19920104_091532.log | strings | cut --complement -b 1-18 > ref_cut.log
	cat ./bvalette.log | strings | cut --complement -b 1-18 > bvalette_cut.log
	@echo " ✅  \n"
	@echo "\n 🎉  \033[32m Colordiff. Reference on the left, my output on the right\033[0m"
	colordiff -w $(($COLUMNS)) -y ./ref_cut.log ./bvalette_cut.log

f : all
	@./$(NAME) | cat --number

.PHONY: all clean fclean mclean re cmp FORCE
#.SILENT:
