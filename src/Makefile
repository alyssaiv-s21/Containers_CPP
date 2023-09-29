CC = g++
SOURCE_FILES = s21_*.hpp
OBJ_FILES = s21_*.o
CFLAGS = -std=c++17 -Wpedantic -Wall -Werror -Wextra -g
COVFLAGS = --coverage
TFLAGS = -lgtest_main -lgcov -lgtest
#ASAN = -g -fsanitize=address

all: clean test gcov_report
	
test: 
	$(CC) $(CFLAGS) $(ASAN) test/test_main.cpp $(TFLAGS) -o output
	./output

gcov_report:
	$(CC) $(COVFLAGS) $(CFLAGS) test/test_main.cpp -L.  $(TFLAGS) -o output
	./output
	lcov -t "output" -c -d  ./ --no-external --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

check:
	clang-format -i *.hpp *.h test/*.cpp
	cppcheck --enable=all --force --suppress=missingIncludeSystem --language=c++ *.hpp test/*.cpp

leak: test
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./output
	leaks --atExit -- ./output

clean:
	rm -rf *.o *.a *.css *.html *.gcno *.gcda *.out *.info *.dSYM *.gcov *.gch report output

rebuild: clean all

.PHONY: all clean rebuild check leakscheck test gcov_report
