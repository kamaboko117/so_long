# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 14:20:20 by asaboure          #+#    #+#              #
#    Updated: 2021/10/14 13:33:15 by asaboure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	=	so_long.c															\
			sources/init.c														\
			sources/error_management.c											\
			sources/parsing.c													\
			sources/utils.c														\
			sources/clear.c														\
			sources/game_loop.c													\
			sources/parsing_checks.c											\
			sources/parsing_layout.c											\
			sources/parsing_checks2.c											\
			sources/drawutils.c													\
			sources/texture.c													\
			sources/utils2.c													\
			sources/movement.c													\
			sources/drawutils2.c												\
			sources/gameover.c													\
			sources/init2.c
			
LIBFTSRCS = ft_memccpy.c														\
			ft_memchr.c															\
			ft_memcmp.c															\
			ft_memcpy.c															\
			ft_memmove.c														\
			ft_memset.c															\
			ft_putchar_fd.c														\
			ft_putendl_fd.c														\
			ft_putnbr_fd.c														\
			ft_putstr_fd.c														\
			ft_split.c															\
			ft_strchr.c															\
			ft_strdup.c															\
			ft_strjoin.c														\
			ft_strlcat.c														\
			ft_strlcpy.c														\
			ft_strlen.c															\
			ft_strmapi.c														\
			ft_strncmp.c														\
			ft_strnstr.c														\
			ft_strrchr.c														\
			ft_strtrim.c														\
			ft_substr.c															\
			ft_tolower.c														\
			ft_toupper.c														\
			ft_atoi.c															\
			ft_bzero.c															\
			ft_calloc.c															\
			ft_isalnum.c														\
			ft_isalpha.c														\
			ft_isascii.c														\
			ft_isdigit.c														\
			ft_isprint.c														\
			ft_itoa.c															\
			ft_putnbrbase_fd.c													\
			ft_putnbru_fd.c														\
			ft_putnbrubase_fd.c													\
			ft_numlen.c															\
			get_next_line.c														\
			get_next_line_utils.c												\
			ft_strjoin_free.c													\
			ft_strcmp.c					

MLXHEADER = minilibx-linux/mlx.h

LOCLIBREP = /usr/local/lib/

LOCLIBMLX	= ${LOCLIBREP}libmlx.a

LIBMLX_DIR = ./minilibx-linux/

LIBMLX	= ${LIBMLX_DIR}libmlx.a

LIBFTOBJS =${LIBFTSRCS:.c=.o}

BONUSSRCS	=

OBJS	= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUSSRCS:.c=.o}

CC		= gcc

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR = ./libft

LIBS	= -L${LIBMLX_DIR} -lmlx -lXext -lX11 -lm -L${LIBFT_DIR} -lft

RM		= rm -f

${NAME}:	${LIBFT} ${MLXHEADER} ${LIBMLX} ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIBFT}:
	@make -sC ./libft -j

${LOCLIBMLX}: ${LIBMLX}
	@echo allow creation of the mlx librairy
	@sudo cp ${LIBMLX} ${LOCLIBREP}

${LIBMLX}:
	@make -sC ./minilibx-linux

${LOCMLXHEADER}:
	@echo allow creation of the mlx.h header
	@sudo mv ./minilibx-linux/mlx.h /usr/local/include/

all:	${NAME}

bonus:

clean:
	 ${RM} ${OBJS} ${BONUSOBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'i

.PHONY:		all clean fclean re coffee bonus
