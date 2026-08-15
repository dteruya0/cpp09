NAME = bitcoin

SRC = main.cpp BitcoinExchange.cpp

OBJ_F = obj/

OBJ = $(addprefix $(OBJ_F), $(SRC:.cpp=.o))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJ_F):
	@mkdir -p $(OBJ_F)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully!"

$(OBJ_F)%.o: %.cpp | $(OBJ_F)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@rm -rf $(OBJ_F)

fclean: clean
	@rm -f $(NAME)

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

re: fclean all