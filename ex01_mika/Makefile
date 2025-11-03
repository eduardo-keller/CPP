# Name of the final executable
NAME = phonebook

# Compiler to use
CXX = c++

# Compiler flags:
# -Wall: enable all warnings
# -Wextra: enable extra warnings
# -Werror: treat warnings as errors
# -std=c++98: enforce the C++98 standard
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Directory where source files are located
SRC_DIR = .

# Directory where object files will be stored
OBJ_DIR = objs

# List of source files
SRC_FILES = \
	main.cpp \
	PhoneBook.cpp \
	Contact.cpp \
	utils.cpp

# Convert source files to corresponding object file paths under OBJ_DIR
OBJ_FILES = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Default target: builds the executable
all: $(NAME)

# Rule to link object files into the final executable
$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

# Rule to compile source files into object files, placing them in OBJ_DIR
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to remove the object directory and its contents
clean:
	rm -rf $(OBJ_DIR)

# Rule to delete object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to clean and then rebuild everything
re: fclean all

# Special target that prevents conflicts with files named 'all', 'clean', etc.
.PHONY: all clean fclean re
