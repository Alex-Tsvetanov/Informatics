CXX = g++
RM = rm

CXXFLAGS = -O2 -std=c++14 -Wall

TARGET = buildMain
csharp = main.cpp

all:
	cat $(csharp) > $(TARGET).cpp
	echo -ne "\nrun_main\n" >> $(TARGET).cpp
	$(CXX) $(TARGET).cpp -o $(TARGET) $(CXXFLAGS)
run:
	./$(TARGET)
clean:
	$(RM) $(TARGET) $(TARGET).cpp
