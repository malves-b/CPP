TARGET := Exe
SRC := main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp
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