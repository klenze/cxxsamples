
CXX=g++
CXXFLAGS= -D_GLIBCXX_ASSERTIONS=1 -g # $(shell root-config --cflags)
LDFLAGS= # $(shell root-config  --ldflags --libs --glibs)
TARGET=segfault
$(TARGET): $(TARGET).o
	$(CXX) $<  $(LDFLAGS)  -o $@

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(TARGET) *.o

# edit segfault.cxx C(0) --> C(1)
# make clean ; make
# ulimit -c unlimited
# ./segfault
# Segmentation fault (core dumped)

