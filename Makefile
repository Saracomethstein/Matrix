CC = gcc
FLAGS = -Wall -Werror -Wextra --std=c11
TEST_FLAGS = -fprofile-arcs -ftest-coverage

MAIN_FILE = manual_test/main.c
TOOLS_FILE = tools/*.c
MATRIX_FILE = matrix_operations/*.c
TEST_FILE = tests/*.c
GCNO_F = ./*.gcno

SRC_FILES = $(filter-out test.c, $(SRCS))
OBJS=$(SRC_FILES:.c=.o)
LIB=`pkg-config --libs gtk+-3.0`
LDFLAGS=-g2

SRCS = $(wildcard $(TOOLS_FILE) $(MATRIX_FILE))
SRCS_TEST = $(wildcard $(TOOLS_FILE) $(MATRIX_FILE) $(TEST_FILE))

all: $(OBJS) matrix.a

test: $(SRCS_TEST)
	@$(CC) -o $@ $(TEST_FLAGS) `pkg-config --cflags --libs check` $(SRCS_TEST)
	@./test

matrix.a:
	$(CC) $(FLAGS) -c $(SRCS)
	@ar rc $@ ./*.o
	ranlib $@

gcov_report: test
	@gcov $(GCNO_F) -m
	@lcov -t "gcov_report" -o gcov_report.info -c -d .
	@genhtml -o ./ gcov_report.info
	@open ./index-sort-f.html

main: matrix.h $(MAIN_FILE) $(TOOLS_FILE) $(MATRIX_FILE)
	@$(CC) $(FLAGS) matrix.h $(MAIN_FILE) $(TOOLS_FILE) $(MATRIX_FILE) -o manual_test.out
	@./manual_test.out

style:
	@clang-format --style=Google -i $(MAIN_FILE) $(TOOLS_FILE) $(MATRIX_FILE) $(TEST_FILE)
	
clang:
	@clang-format --style=Google -n $(MAIN_FILE) $(TOOLS_FILE) $(MATRIX_FILE) $(TEST_FILE)

.PHONY: clean matrix.a gcov_report clang test
clean:
	@rm -rf matrix.a tools/*.o manual_test/*.o matrix_operations/*.o manual_test.out *.o *.gcno *.gcda test \
	tests/*.html matrix_operations/*.html tools/*.html *.gcov *.png *.css *.info cmd_line *.html