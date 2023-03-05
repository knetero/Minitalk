# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 23:12:37 by abazerou          #+#    #+#              #
#    Updated: 2023/03/05 17:08:39 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	=	client
SERVER	=	server
CLIENT_B	=	client_bonus
SERVER_B	=	server_bonus

PRINTF		=	ft_printf/libftprintf.a
PRINTF_DIR	=	ft_printf/
HEADER		= 	minitalk.h

SRC_C	=	client.c
SRC_S	=	server.c
SRCB_C	=	client_bonus.c
SRCB_S	=	server_bonus.c

CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

red			=	`tput setaf 1`
green		=	`tput setaf 2`
white		=	`tput setaf 7`

all: $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

$(SERVER): $(PRINTF) $(HEADER) $(SRC_S)
	@ $(CC) $(CFLAG) $(SRC_S) $(PRINTF) -o $(SERVER) 
	@echo " [$(green)SUCCESS$(white)] server $(green)ready$(white)."

$(CLIENT): $(PRINTF) $(HEADER) $(SRC_C)
	@ $(CC) $(CFLAG) $(SRC_C) $(PRINTF) -o $(CLIENT)
	@echo " [$(green)SUCCESS$(white)] client $(green)ready$(white)."

$(SERVER_B): $(PRINTF) $(HEADER) $(SRCB_S)
	@ $(CC) $(CFLAG) $(SRCB_S) $(PRINTF) -o $(SERVER_B)
	@echo " [$(green)SUCCESS$(white)] server_bonus $(green)ready$(white)."

$(CLIENT_B): $(PRINTF) $(HEADER) $(SRCB_C)
	@ $(CC) $(CFLAG) $(SRCB_C) $(PRINTF) -o $(CLIENT_B)
	@echo " [$(green)SUCCESS$(white)] client_bonus $(green)ready$(white)."

$(PRINTF):
	@ $(MAKE) -C $(PRINTF_DIR)

clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@echo " [$(red)INFO$(white)] client $(red)removed$(white)."
	@echo " [$(red)INFO$(white)] server $(red)removed$(white)."
	@ $(RM) $(CLIENT_B) $(SERVER_B)
	@echo " [$(red)INFO$(white)] client_bonus $(red)removed$(white)."
	@echo " [$(red)INFO$(white)] server_bonus $(red)removed$(white)."	

fclean:
	@ $(MAKE) fclean -C $(PRINTF_DIR)
	@echo " [$(red)INFO$(white)] object files $(red)removed$(white)."
	@ $(RM) $(CLIENT) $(SERVER)
	@echo " [$(red)INFO$(white)] client $(red)removed$(white)."
	@echo " [$(red)INFO$(white)] server $(red)removed$(white)."
	@ $(RM) $(CLIENT_B) $(SERVER_B)
	@echo " [$(red)INFO$(white)] client_bonus $(red)removed$(white)."
	@echo " [$(red)INFO$(white)] server_bonus $(red)removed$(white)."	
re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		$(CLIENT_B) $(SERVER_B)

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
