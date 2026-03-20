NAME = longest_substring_without_repeating
SRCS = main.cpp lengthOfLongestSubstring.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
CXX = c++
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

all: $(NAME)

run: all
	./$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all run clean fclean re
