

bin/c_lexer : src/c_lexer.yy.cpp
	g++ -std=gnu++11 src/c_lexer.yy.cpp -o bin/c_lexer

src/c_lexer.yy.cpp : src/c_lexer.lex
	flex -o src/c_lexer.yy.cpp src/c_lexer.lex

clean :
	rm src/c_lexer.yy.cpp
	rm bin/c_lexer

