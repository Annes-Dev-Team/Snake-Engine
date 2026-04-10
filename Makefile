.PHONY: build
build:
	cc src/*.c -c -std=c17 -Iinclude -g
	
	mv *.o obj/

	c++ src/*.cpp obj/*.o -lraylib -o bin/app -std=c++20 -Iinclude \
		-framework Cocoa \
		-framework IOKit \
		-framework CoreVideo \
		-framework CoreFoundation -g

	c++ src/*.cpp obj/*.o -lraylib -shared -o bin/snek.dylib -std=c++20 -Iinclude \
		-framework Cocoa \
		-framework IOKit \
		-framework CoreVideo \
		-framework CoreFoundation -g
	
	cc src/*.c -S -std=c17 -Iinclude -O0 # asm thingy

	mv *.s obj/

	#rm a.out

	cp -r ./include/engine ./bin/engine


run: build
	./bin/app
