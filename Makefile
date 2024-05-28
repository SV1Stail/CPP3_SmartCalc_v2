COMPILE_FLAGS = -Wall -Werror -Wextra
EXECUTABLE = tests
TAR_FILE = calc.tar
APP = build/Calculator
ifeq ($(shell uname), Linux)
	BUILD_FLAGS = -lcheck_pic -lsubunit -lm
endif
ifeq ($(shell uname), Darwin)
	BUILD_FLAGS = -lcheck -lm
endif
all: install

install:
	@mkdir -p build
	cd build && cmake .. -DBUILD_MY_MAIN=ON && make
	@mkdir -p $(HOME)/Desktop/SmartCalc/
	@cp -rf $(APP) $(HOME)/Desktop/SmartCalc/
	make clean

volg:
	@mkdir -p test_build
	cd test_build && cmake .. -DBUILD_MY_EXECUTABLE=ON && make
	cd test_build && valgrind --tool=memcheck --leak-check=yes  ./CalculatorTests

more_volg:
	@mkdir -p test_build
	cd test_build && cmake .. -DBUILD_MY_EXECUTABLE=ON && make
	cd test_build && valgrind --leak-check=full \
			 --show-leak-kinds=all \
			 --track-origins=yes \
			 --verbose  ./CalculatorTests

test:
	@mkdir -p test_build
	cd test_build && cmake .. -DBUILD_MY_EXECUTABLE=ON && make
	cd test_build && ./CalculatorTests


unisntall:
	rm -rf  $(HOME)/Desktop/SmartCalc/

dist: install
	mkdir -p $(HOME)/Desktop/dist
	@cp -rf $(HOME)/Desktop/SmartCalc $(HOME)/Desktop/dist/
	@cd $(HOME)/Desktop/dist && tar cvzf SmartCalc_v2.0.tgz *
	@cd $(HOME)/Desktop/dist && rm -rf SmartCalc
	make uninstall
	
dvi: 
	open readme.md



clean:
	rm -rf build test_build
	
format:
	clang-format -i --style=google calc/*.cpp calc/*.cc calc/*.h

