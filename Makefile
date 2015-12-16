##
## Makefile for bistro in /home/bougon_p/rendu/Piscine_C_bistromathique
## 
## Made by Pierre Bougon
## Login   <bougon_p@epitech.net>
## 
## Started on  Thu Oct 29 14:45:48 2015 Pierre Bougon
## Last update Wed Dec 16 16:23:03 2015 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)bsq.c \
	$(SRCP)my_strcat.c \
	$(SRCP)transform.c \
	$(SRCP)remains.c \
	$(SRCP)my_realloc.c

OBJS    = $(SRC:.c=.o)

NAME    = bsq

CC      = gcc

CFLAGS  = -W -Wall -ansi -pedantic -g

LDFLAGS = -lmy -L./lib/

RM      = rm -f

$(NAME): $(OBJS)
	@($(CC) -o $(NAME) $(OBJS) $(LDFLAGS))

all: $(NAME) 

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
