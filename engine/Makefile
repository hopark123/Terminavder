NAME=engine.a
HEADER=-Iinclude
SRCS= \
	source/GameObject.cpp \
	source/Object.cpp \
	source/Scene.cpp \
	source/Vector.cpp \
	source/GameManager.cpp \
	source/Graphics.cpp \
	source/InputManager.cpp \
	source/TVDR.cpp \
	source/MemoryPool.cpp 
OBJS=${SRCS:.cpp=.o}
all: $(NAME)
.cpp.o: $(SRCS)
	clang++ --std=c++20 $(HEADER) -c -o $@ $<

$(NAME): $(OBJS)
	ar rc $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
