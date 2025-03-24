CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c utils.c
SERVER_SRCS = server.c utils.c

CLIENT_BONUS_SRCS = client_bonus.c utils.c
SERVER_BONUS_SRCS = server_bonus.c utils.c

CLIENT_OBJ = $(CLIENT_SRCS:.c=.o)
SERVER_OBJ = $(SERVER_SRCS:.c=.o)

CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRCS:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRCS:.c=.o)

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJ)

$(SERVER_NAME): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJ)

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJ)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_OBJ)

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJ)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_OBJ)

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

.PHONY: all clean fclean re bonus
