# Name of the final executable
NAME    = megaphone

# Compiler to use
CC     = c++

# Compiler flags:
# -Wall: enable all warnings
# -Wextra: enable extra warnings
# -Werror: treat warnings as errors
# -std=c++98: enforce the C++98 standard
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS    = megaphone.cpp

# Object files (compiled .cpp -> .o)
OBJS    = $(SRCS:.cpp=.o)

# Default target: builds the executable
all: $(NAME)

# Rule to link the object files into the final executable
$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

# Rule to remove the object directory and its contents
clean:
	rm -f $(OBJS)

# Rule to delete object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to clean and then rebuild everything
re: fclean all

# Special target that prevents conflicts with files named 'all', 'clean', etc.
.PHONY: all clean fclean re