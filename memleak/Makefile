
CXX=$(shell root-config --cxx)
CXXFLAGS=$(shell root-config --cflags) -D_GLIBCXX_ASSERTIONS=1 -g
LDFLAGS=$(shell root-config  --ldflags --libs --glibs) -g
TARGET=memleak
$(TARGET): $(TARGET).o
	$(CXX) $<  $(LDFLAGS)  -o $@

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(TARGET) *.o
