# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
SRC = Data.cpp  main.cpp  Serializer.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = convert

# Colors
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
CYAN   = \033[1;36m
RED    = \033[1;31m
RESET  = \033[0m

# Règles
.PHONY: all clean fclean re

all: header build

header:
	@echo "$(CYAN)=== Début de la compilation ===$(RESET)"

build: $(TARGET)

$(TARGET): $(OBJ)
	@echo "$(BLUE)🔧 Création de l'exécutable $(TARGET)...$(RESET)"
	$(CXX) $(OBJ) -o $(TARGET)
	@echo "$(GREEN)✅ Compilation terminée avec succès !$(RESET)"

PhoneBook.o: PhoneBook.cpp
	@echo "$(YELLOW)📄 Compilation de $<...$(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

Contact.o: Contact.cpp
	@echo "$(YELLOW)📄 Compilation de $<...$(RESET)" 
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp
	@echo "$(YELLOW)📄 Compilation de $<...$(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Suppression des fichiers objets...$(RESET)"
	rm -f $(OBJ)
	@echo "$(RED)🧼 Fichiers objets supprimés !$(RESET)"

fclean: clean
	@echo "$(RED)🗑️ Suppression de l'exécutable $(TARGET)...$(RESET)"
	rm -f $(TARGET)
	@echo "$(RED)🧽 Exécutable supprimé !$(RESET)"

re: fclean all