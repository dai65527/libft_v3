# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 08:47:29 by dnakano           #+#    #+#              #
#    Updated: 2023/11/26 18:15:49 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
SRCNAME			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
					ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c \
					ft_strlcat.c ft_strncmp.c ft_strchr.c ft_strrchr.c \
					ft_strnstr.c ft_strdup.c ft_isalpha.c ft_isdigit.c \
					ft_isupper.c ft_islower.c \
					ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c \
					ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstdup.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstpop.c \
					ft_lstrm_if.c \
					ft_lstsize.c \
					ft_lstsort.c
SRCDIR			=	.
SRCS			=	$(addprefix $(SRCDIR)/,$(SRCNAME))
OBJS			=	$(SRCS:%.c=%.o)
HEADERNAME		=	libft.h
HEADERDIR		=	.
HEADERS			=	$(addprefix $(HEADERDIR)/,$(HEADERNAME))
NAME			=	libft.a
OUTPUTDIR		=	.
OUTPUTS			=	$(addprefix $(OUTPUTDIR)/,$(NAME))

.SUFFIXES:		.o .c

.PHONY:			all
all:			$(NAME)

$(NAME):		$(OBJS) $(BONUSOBJS) $(HEADERS)
				ar cr $(OUTPUTS) $(OBJS) $(BONUSOBJS)

%.o:%.c
				$(CC) $(CFLAGS) -c $< -o $@

.PHONY:			clean
clean:
				rm -f $(OBJS)

.PHONY:			fclean
fclean:			clean
				rm -f $(OUTPUTS)

.PHONY:			re
re:				fclean all
