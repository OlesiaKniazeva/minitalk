CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft -I minitalk.h

LIB = libft/libft.a

RM = rm -f

all: client server

$(LIB):
		make -C libft

#oclient: client.o 
#		$(CC) $(CFLAGS) -c client.c -o client.o

client:  $(LIB) client.o minitalk.h
		$(CC) $(CFLAGS) $(LIB) client.o -o client

#oserver: server.o
#		$(CC) $(CFLAGS) -c server.c -o server.o

server: $(LIB) server.o minitalk.h
		$(CC) $(CFLAGS) $(LIB) server.o -o server
		

clean: 
			make clean -C libft
			$(RM) server.o client.o

fclean: clean
		$(RM) $(LIB)
		$(RM) server client 

re:		fclean all		
		
