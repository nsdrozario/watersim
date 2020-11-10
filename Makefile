CXX := g++
CXXFLAGS := -Wall -Werror -Iinclude/ -std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

OBJS := Cell.o Data.o Physics.o UI.o main.o

%.o : %.cpp
	$(CXX) $^ -c -o $@ $(CXXFLAGS)

watersim: $(OBJS)
	$(CXX) $^ -o watersim $(LIBS)

clean:
	rm -rf *.o *.exe