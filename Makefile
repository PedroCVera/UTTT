NAME		= UltimateTicTacToe
OBJ_PATH	= obj

SRCS		= $(shell find src/ -name '*.cpp')

OBJS		= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(basename $(SRCS))))
INCLUDES	= inc/

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -I$(INCLUDES) -fsanitize=address -g
RM			= rm -f

all: $(NAME)

$(OBJ_PATH)/%.o:%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) -I /usr/local/include -c -o $@ $<

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@  $^

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re r m