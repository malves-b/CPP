TARGET := Exe
SRC := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	$(RM) $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re