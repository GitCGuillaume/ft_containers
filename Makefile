TESTS_VECTOR	=	./tests/vector

TESTS_MAP	=	./tests/map

TESTS_STACK	=	./tests/stack

SRCS_VEC	=	$(TESTS_VECTOR)/at.cpp $(TESTS_VECTOR)/capacities.cpp $(TESTS_VECTOR)/constructor.cpp $(TESTS_VECTOR)/data.cpp \
	$(TESTS_VECTOR)/erase.cpp $(TESTS_VECTOR)/front_back.cpp $(TESTS_VECTOR)/iterator_backward.cpp $(TESTS_VECTOR)/iterator_forward.cpp \
	$(TESTS_VECTOR)/iterator.cpp $(TESTS_VECTOR)/modifiers.cpp $(TESTS_VECTOR)/operator.cpp $(TESTS_VECTOR)/reverse_iterator.cpp

SRCS_MAP	=	$(TESTS_MAP)/at.cpp $(TESTS_MAP)/bracket.cpp $(TESTS_MAP)/constructor.cpp $(TESTS_MAP)/iterator.cpp \
			$(TESTS_MAP)/lookup.cpp $(TESTS_MAP)/modifier_one.cpp $(TESTS_MAP)/observer.cpp $(TESTS_MAP)/operator.cpp \
			$(TESTS_MAP)/pair.cpp

SRCS_STACK	=	$(TESTS_STACK)/constructor.cpp $(TESTS_STACK)/mutantstack_tests.cpp $(TESTS_STACK)/tests.cpp

SRCS_MAIN_SCHOOL = ./tests/main_school.cpp

SRCS_MAIN	=	./main.cpp

OBJS_MS	=	$(SRCS:.cpp=.o)

OBJS_VEC	=	$(SRCS_VEC:.cpp=.o)

OBJS_MAP	=	$(SRCS_MAP:.cpp=.o)

OBJS_STACK	=	$(SRCS_STACK:.cpp=.o)

OBJS_MAIN	=	$(SRCS_MAIN:.cpp=.o)

NAME_STD	=	std

NAME_FT	=	ft

RM	=	rm -f

.cpp.o:
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $(<:.cpp=.o)

all:	$(NAME_STD) $(NAME_FT)

$(NAME_STD): $(OBJS_MAIN) $(OBJS_MS) $(OBJS_VEC) $(OBJS_MAP) $(OBJS_STACK)
	c++ -Wall -Wextra -Werror -std=c++98 -D TYPECONT=ft -o $(NAME_STD) $(OBJS_MAIN) $(OBJS_MS) $(OBJS_VEC) $(OBJS_MAP) $(OBJS_STACK)

$(NAME_FT): $(OBJS_MAIN) $(OBJS_MS) $(OBJS_VEC) $(OBJS_MAP) $(OBJS_STACK)
	c++ -Wall -Wextra -Werror -std=c++98 -D TYPECONT=std -o $(NAME_FT) $(OBJS_MAIN) $(OBJS_MS) $(OBJS_VEC) $(OBJS_MAP) $(OBJS_STACK)

clean:
	$(RM) $(OBJS_MAIN)
	$(RM) $(OBJS_MS)
	$(RM) $(OBJS_VEC)
	$(RM) $(OBJS_MAP)
	$(RM) $(OBJS_STACK)

fclean:
	$(RM) $(NAME_STD)
	$(RM) $(NAME_ft)
	make clean

re: fclean all

.PHONY: all clean fclean re
