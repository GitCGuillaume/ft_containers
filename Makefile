TESTS_VECTOR	=	./tests/vector

TESTS_MAP	=	./tests/map

TESTS_STACK	=	./tests/stack

TESTS_VECTOR_FT	=	./tests/vector_ft

TESTS_MAP_FT	=	./tests/map_ft

TESTS_STACK_FT	=	./tests/stack_ft

SRCS_VEC	=	$(TESTS_VECTOR)/at.cpp $(TESTS_VECTOR)/capacities.cpp $(TESTS_VECTOR)/constructor.cpp $(TESTS_VECTOR)/data.cpp \
	$(TESTS_VECTOR)/erase.cpp $(TESTS_VECTOR)/front_back.cpp $(TESTS_VECTOR)/iterator_backward.cpp $(TESTS_VECTOR)/iterator_forward.cpp \
	$(TESTS_VECTOR)/iterator.cpp $(TESTS_VECTOR)/modifiers.cpp $(TESTS_VECTOR)/operator.cpp $(TESTS_VECTOR)/reverse_iterator.cpp

SRCS_VEC_FT	=	$(TESTS_VECTOR_FT)/at.cpp $(TESTS_VECTOR_FT)/capacities.cpp $(TESTS_VECTOR_FT)/constructor.cpp $(TESTS_VECTOR_FT)/data.cpp \
	$(TESTS_VECTOR_FT)/erase.cpp $(TESTS_VECTOR_FT)/front_back.cpp $(TESTS_VECTOR_FT)/iterator_backward.cpp $(TESTS_VECTOR_FT)/iterator_forward.cpp \
	$(TESTS_VECTOR_FT)/iterator.cpp $(TESTS_VECTOR_FT)/modifiers.cpp $(TESTS_VECTOR_FT)/operator.cpp $(TESTS_VECTOR_FT)/reverse_iterator.cpp

SRCS_MAP	=	$(TESTS_MAP)/at.cpp $(TESTS_MAP)/bracket.cpp $(TESTS_MAP)/constructor.cpp $(TESTS_MAP)/iterator.cpp \
			$(TESTS_MAP)/lookup.cpp $(TESTS_MAP)/modifier_one.cpp $(TESTS_MAP)/observer.cpp $(TESTS_MAP)/operator.cpp \
			$(TESTS_MAP)/pair.cpp

SRCS_MAP_FT	=	$(TESTS_MAP_FT)/at.cpp $(TESTS_MAP_FT)/bracket.cpp $(TESTS_MAP_FT)/constructor.cpp $(TESTS_MAP_FT)/iterator.cpp \
			$(TESTS_MAP_FT)/lookup.cpp $(TESTS_MAP_FT)/modifier_one.cpp $(TESTS_MAP_FT)/observer.cpp $(TESTS_MAP_FT)/operator.cpp \
			$(TESTS_MAP_FT)/pair.cpp

SRCS_STACK	=	$(TESTS_STACK)/constructor.cpp $(TESTS_STACK)/mutantstack_tests.cpp $(TESTS_STACK)/tests.cpp

SRCS_STACK_FT	=	$(TESTS_STACK_FT)/constructor.cpp $(TESTS_STACK_FT)/mutantstack_tests.cpp $(TESTS_STACK_FT)/tests.cpp

SRCS_MAIN_SCHOOL = ./tests/main_school.cpp

SRCS_MAIN_SCHOOL_FT = ./tests/main_school_ft.cpp

SRCS_MAIN	=	./main.cpp

SRCS_MAIN_FT	=	./main_ft.cpp

OBJS_MS	=	$(SRCS_MAIN_SCHOOL:.cpp=.o)

OBJS_VEC	=	$(SRCS_VEC:.cpp=.o)

OBJS_MAP	=	$(SRCS_MAP:.cpp=.o)

OBJS_STACK	=	$(SRCS_STACK:.cpp=.o)

OBJS_MAIN	=	$(SRCS_MAIN:.cpp=.o)

OBJS_MS_FT	=	$(SRCS_MAIN_SCHOOL_FT:.cpp=.o)

OBJS_VEC_FT	=	$(SRCS_VEC_FT:.cpp=.o)

OBJS_MAP_FT	=	$(SRCS_MAP_FT:.cpp=.o)

OBJS_STACK_FT	=	$(SRCS_STACK_FT:.cpp=.o)

OBJS_MAIN_FT	=	$(SRCS_MAIN_FT:.cpp=.o)

NAME_STD	=	std

NAME_FT	=	ft

RM	=	rm -f

COMPILER	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -Iincludes/containers

.cpp.o:
	$(COMPILER) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all:	$(NAME_STD) $(NAME_FT)

$(NAME_STD): $(OBJS_MAIN) $(OBJS_MS) $(OBJS_VEC) $(OBJS_MAP) $(OBJS_STACK)
	$(COMPILER) $(CFLAGS) -o $(NAME_STD) $(OBJS_MAIN) $(OBJS_MS) $(OBJS_VEC) $(OBJS_MAP) $(OBJS_STACK)

$(NAME_FT): $(OBJS_MAIN_FT) $(OBJS_MS_FT) $(OBJS_VEC_FT) $(OBJS_MAP_FT) $(OBJS_STACK_FT)
	$(COMPILER) $(CFLAGS) -o $(NAME_FT) $(OBJS_MAIN_FT) $(OBJS_MS_FT) $(OBJS_VEC_FT) $(OBJS_MAP_FT) $(OBJS_STACK_FT)

clean:
	$(RM) $(OBJS_MAIN)
	$(RM) $(OBJS_MS)
	$(RM) $(OBJS_VEC)
	$(RM) $(OBJS_MAP)
	$(RM) $(OBJS_STACK)
	$(RM) $(OBJS_MAIN_FT)
	$(RM) $(OBJS_MS_FT)
	$(RM) $(OBJS_VEC_FT)
	$(RM) $(OBJS_MAP_FT)
	$(RM) $(OBJS_STACK_FT)

fclean:
	$(RM) $(NAME_STD)
	$(RM) $(NAME_FT)
	make clean

re: fclean all

.PHONY: all clean fclean re
