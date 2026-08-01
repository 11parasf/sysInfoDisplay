CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20


sysInfoDisplay: build/main.o build/cpuInfo.o build/diskUtilization.o build/memInfo.o
	$(CXX) build/main.o build/cpuInfo.o build/diskUtilization.o build/memInfo.o -o build/sysInfoDisplay

build/main.o: main.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build

run: build/sysInfoDisplay
	./build/sysInfoDisplay

rebuild: clean
	make



.PHONY: clean run



