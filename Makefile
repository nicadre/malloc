#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 13:23:47 by niccheva          #+#    #+#              #
#    Updated: 2016/07/31 17:46:00 by niccheva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		=	libft_malloc_$(HOSTTYPE).so

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

DSOURCES	=	./sources/

DOBJECTS	=	objects/

BUILD		=	./build

INCLUDES	=	-I./includes
INCLUDES	+=	-I./libraries/liblist/includes

SOURCES		=	malloc.c
SOURCES		+=	malloc_bzero.c
SOURCES		+=	malloc_memset.c
SOURCES		+=	init_malloc.c
SOURCES		+=	create_large_zone.c
SOURCES		+=	create_zone_for.c
SOURCES		+=	size_for_zone_type.c
SOURCES		+=	size_for_elem_in_zone.c
SOURCES		+=	add_zone.c
SOURCES		+=	del_zone.c

OBJECTS		=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.o, $(SOURCES))

DEPS		=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.d, $(SOURCES))

DEPENDS		=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all: $(BUILD)/$(NAME)

libs:
	make -C ./libraries/liblist

$(BUILD)/$(NAME): libs $(OBJECTS)
	@echo "\n\033[0;32m$(NAME) compiled:\t\033[0;m\c"
	$(CC) -shared -o $(BUILD)/$(NAME) $(OBJECTS) -L./libraries/liblist/build -llist
	@ln -sf $(BUILD)/$(NAME) libft_malloc.so

-include $(OBJECTS:.o=.d)

$(BUILD)/$(DOBJECTS)%.o: $(DSOURCES)%.c
	@mkdir -p $(BUILD)/$(DOBJECTS)
	@echo "\033[0;32m$< compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) $(DEPENDS) -fpic -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(BUILD)/$(DOBJECTS)

fclean: clean
	@rm -f $(BUILD)/$(NAME)
	@rm -rf $(BUILD)
	@rm -f libft_malloc.so

re: fclean all

.PHONY: all clean fclean re libs
