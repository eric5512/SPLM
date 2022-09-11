COMMANDS = src/commands/init.cpp

INCLUDES = src/help.cpp src/serializer.cpp src/data_types/parts.cpp src/parser_helper.cpp src/command_builder.cpp src/file_helper.cpp $(COMMANDS)

OFLAGS = -Wall -Wextra

all: src/main.cpp
	g++ -std=c++11 src/main.cpp -o bin/main.exe $(INCLUDES) $(OFLAGS)