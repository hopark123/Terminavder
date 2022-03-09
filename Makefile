NAME = KRAFTON
HEADER = -I./Include
SRCS =	Source/Input.cpp \
		Source/main.cpp
OBJS=${SRCS:.cpp=.o}
all: $(NAME)
.cpp.o:$(SRCS)
	clang++ --std=c++20 $(HEADER) -c -o $@ $<
  
$(NAME): $(OBJS)
	ar rc $@ $^ 

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
