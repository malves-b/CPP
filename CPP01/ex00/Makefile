TARGET := Zombie
SRC := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	$(RM) $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
