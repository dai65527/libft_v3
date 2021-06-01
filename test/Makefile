# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 10:22:35 by dnakano           #+#    #+#              #
#    Updated: 2021/06/01 22:39:58 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CXX			=	g++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++11

### config ###
SRCNAME		=	ft_memset.c \
				ft_memcpy.c
SRCDIR		=	..
INCLUDEDIR	=	..
TESTSRCNAME	=	test_memset.cc \
				test_memcpy.cc
TESTSRCDIR	=	.
### config ###

# no need to edit
SRCS		=	$(addprefix $(SRCDIR)/,$(SRCNAME))
TESTSRCS	=	$(addprefix $(TESTSRCDIR)/,$(TESTSRCNAME))
GTESTSRCNAME=	gtest-all.cc
GTESTSRCDIR	=	gtest
GTESTSRCS	=	test.cc $(addprefix $(GTESTSRCDIR)/,$(GTESTSRCNAME))
OBJS		=	$(SRCS:%.c=%.o) $(TESTSRCS:%.cc=%.o) $(GTESTSRCS:%.cc=%.o)
NAME		=	test.out
OUTDIR		=	.

.SUFFIXES:	.o .cpp .cc .c

.PHONY:		all
all:		test

$(NAME):	$(OBJS)
			$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

%o:%c
			$(CC) $(CFLAGS) -c $< -o $@

%o:%cc
			$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY:		test
test:		$(NAME)
			$(OUTDIR)/$(NAME)

.PHONY:		clean
clean:
			rm -f $(OBJS)

.PHONY:		fclean
fclean:		clean
			rm -f $(NAME)

.PHONY:		re
re:			fclean all
