run: build
	./bin/main

build: bin/main

bin/main: src/main.c src/functions.c src/constants.c bin
	gcc src/main.c src/functions.c src/constants.c -o bin/main

bin:
	mkdir -p bin
