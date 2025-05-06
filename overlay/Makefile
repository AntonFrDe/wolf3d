##
## EPITECH PROJECT, 2024
## FinalProject
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC = ./src/main/main.c	\
	  ./src/main/init.c  \
	  ./src/main/display.c \
	  ./src/main/event.c \
	  ./src/ammo.c	\
	  ./src/weapon.c	\
	  ./src/update.c	\
	  ./src/hud.c 	\

TARGET = weapon_viewer

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
