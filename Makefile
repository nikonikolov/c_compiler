CPPFLAGS += -std=c++11 
DATA_STRUCTURE_SRCS = \
    $(wildcard src/DataStructures/*.cpp)
DATA_STRUCTURE_OBJS=$(patsubst %.cpp, %.o, $(DATA_STRUCTURE_SRCS))

#bin/c_parser: src/c_parser.tab.cpp src/c_parser.tab.hpp src/c_lexer.yy.cpp
#	g++ $(CPPFLAGS) src/c_parser.tab.cpp src/c_parser.tab.hpp src/c_lexer.yy.cpp -o bin/c_parser

bin/c_parser: src/c_parser.tab.cpp src/c_parser.tab.hpp src/c_lexer.yy.cpp src/helper.cpp src/helper.hpp $(DATA_STRUCTURE_OBJS)
	g++ $(CPPFLAGS) src/c_parser.tab.cpp src/helper.cpp src/c_lexer.yy.cpp $(DATA_STRUCTURE_OBJS) -o bin/c_parser

src/c_parser.tab.cpp src/c_parser.tab.hpp: src/c_parser.y
	bison -d src/c_parser.y -o src/c_parser.tab.cpp

bin/c_lexer: src/c_lexer.yy.cpp
	g++ $(CPPFLAGS) src/c_lexer.yy.cpp -o bin/c_lexer

src/c_lexer.yy.cpp: src/c_lexer.lex
	flex -o src/c_lexer.yy.cpp src/c_lexer.lex

ctest: syntaxtest.c
	gcc -std=c90 -pedantic syntaxtest.c -o ctest

$(DATA_STRUCTURE_OBJS): src/DataStructures/%.o : src/DataStructures/%.cpp
	g++ $(CPPFLAGS) -c $< -o $@


clean:
	rm src/c_lexer.yy.cpp
	rm src/c_parser.tab.hpp
	rm src/c_parser.tab.cpp
	rm bin/c_lexer
	rm src/DataStructures/*.o
	rm bin/c_parser

