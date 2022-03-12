NAME=Terminvader
HEADER = -I./source/
ENGINE = engine
SRCS =	main.cpp \
	source/HelloWorld.cpp \
	source/Player.cpp \
	source/Enemy.cpp \
	source/Enemy_Attack.cpp \
	source/Player_Attack.cpp \
	
$(NAME) : all

all:
	$(MAKE) -C ./$(ENGINE)
	clang++ --std=c++20 $(SRCS) $(HEADER) -o $(NAME) \
		-I./$(ENGINE)/include `sdl2-config --cflags --libs` $(ENGINE)/$(ENGINE).a

test: re
	./$(NAME)
fclean:
	rm -f $(NAME)
	$(MAKE) -C ./$(ENGINE) fclean
re:fclean all