#!/bin/bash
CPPFLAGS += -std=c++11 
DATA_STRUCTURE_SRCS = \
    $(wildcard src/DataStructures/*.cpp)
DATA_STRUCTURE_OBJS=$(patsubst %.cpp, %.o, $(DATA_STRUCTURE_SRCS))
MAKEFILE="Makefile"

#bin/c_parser: src/c_parser.tab.cpp src/c_parser.tab.hpp src/c_lexer.yy.cpp
#	g++ $(CPPFLAGS) src/c_parser.tab.cpp src/c_parser.tab.hpp src/c_lexer.yy.cpp -o bin/c_parser

# For testing functionality of expressions
bin/parser_expr: src_tmp/parser_expr.tab.cpp src_tmp/parser_expr.tab.hpp src/c_lexer.yy.cpp src/helper.cpp src/helper.hpp $(DATA_STRUCTURE_OBJS)
	g++ $(CPPFLAGS) src_tmp/parser_expr.tab.cpp src/helper.cpp src/c_lexer.yy.cpp $(DATA_STRUCTURE_OBJS) -o bin/parser_expr

src_tmp/parser_expr.tab.cpp src_tmp/parser_expr.tab.hpp: src_tmp/parser_expr.y
	bison -d src_tmp/parser_expr.y -o src_tmp/parser_expr.tab.cpp

# Build Parser and dependencies
bin/c_parser: src/c_parser.tab.cpp src/c_parser.tab.hpp src/c_lexer.yy.cpp src/helper.cpp src/helper.hpp $(DATA_STRUCTURE_OBJS)
	g++ $(CPPFLAGS) src/c_parser.tab.cpp src/helper.cpp src/c_lexer.yy.cpp $(DATA_STRUCTURE_OBJS) -o bin/c_parser

src/c_parser.tab.cpp src/c_parser.tab.hpp: src/c_parser.y
	bison -d src/c_parser.y -o src/c_parser.tab.cpp

# Build Lexer and dependencies
bin/c_lexer: src/c_lexer.yy.cpp
	g++ $(CPPFLAGS) src/c_lexer.yy.cpp -o bin/c_lexer

src/c_lexer.yy.cpp: src/c_lexer.lex
	flex -o src/c_lexer.yy.cpp src/c_lexer.lex

# Build c90 executable to test c90 features
ctest: syntaxtest.c
	gcc -std=c90 -pedantic syntaxtest.c -o ctest

# Build DataStructure Objects
$(DATA_STRUCTURE_OBJS): src/DataStructures/%.o : src/DataStructures/%.cpp
	g++ $(CPPFLAGS) -c $< -o $@


clean:
#	if [ -e src/c_lexer.yy.cpp ]; then 
#		rm src/c_lexer.yy.cpp
#	fi
#	if [ -e src/c_parser.tab.cpp ]; then 
#		rm src/c_parser.tab.cpp
#	fi
#	if [ -e src/c_parser.tab.hpp ]; then 
#		rm src/c_parser.tab.hpp
#	fi
#	if [ -e bin/c_lexer ]; then 
#		rm bin/c_lexer
#	fi
#	if [ -e src/DataStructures/*.o ]; then 
#		rm src/DataStructures/*.o
#	fi
#	if [ -e bin/c_parser ]; then 
#		rm bin/c_parser
#	fi
	rm src/c_lexer.yy.cpp
	rm src/c_parser.tab.cpp
	rm src/c_parser.tab.hpp
	rm src/DataStructures/*.o
	rm bin/c_parser
	rm bin/c_lexer

