NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g3

INCLUDES = inc

SRCS_RAW = philo.c \
		   destroy_and_exit.c \
		   init.c \
		   input_checks.c \
		   routines.c \
		   threads.c \
		   utils.c 

SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/,$(SRCS_RAW))

OBJS_RAW = $(SRCS_RAW:.c=.o)
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJS_RAW))

YEL = \033[0;33m
GRN = \033[0;32m
RED = \033[0;31m
GRN_B = \033[32;7m
RESET = \033[0m

all: $(NAME)
	@echo $(SRCS)
	@echo "$(GRN_B)\nGood to go!$(RESET)"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YEL)Making $< $(RESET)"
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
	@echo "$(GRN)Done.\n$(RESET)"

clean:
	rm -f $(OBJS)
	rm -df obj

fclean: clean
	rm -f $(NAME)
	@echo "$(GRN)all clean!$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re
