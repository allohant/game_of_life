GXX = g++
CXXFLAGS = -g -Wall
OBJMODULES = cell.o field.o textField.o utility.o
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
life: life.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@
