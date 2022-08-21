COMMANDS = src/commands/init.cpp

INCLUDES = src/help.cpp src/command_builder.cpp $(COMMANDS)

OFLAGS = -Wall -Wextra

all: src/main.cpp
	g++ src/main.cpp -o bin/main.exe $(INCLUDES) $(OFLAGS)