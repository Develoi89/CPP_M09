NAME		=	RPN

SRC			=	main.cpp\
				RPN.cpp

HDS			=	RPN.hpp

OBJ			=	$(SRC:.cpp=.o)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

%.o:	%.cpp %.tpp %.hpp
		$(CC) ${CFLAGS} -o $@ -c $<

$(NAME)		:	$(OBJ) $(HDS)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					
all			:	$(NAME)

clean		:
		@rm -rf  $(OBJ)

fclean		:	clean
		@rm -rf $(NAME) $(OBJ)

re			:	fclean	all

.PHONY		:	all clean fclean re