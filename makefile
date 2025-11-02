run : bin/animacion
	./bin/animacion

bin/animacion : src/animacion.cpp include/*.hpp
	@mkdir -p bin
	g++ -Iinclude -o bin/animacion src/animacion.cpp -std=c++17 -D_USE_MATH_DEFINES -lftxui-component -lftxui-dom -lftxui-screen -lm