DFLAGS = -ggdb
CXXFLAGS = -Wall -std=c++11 $(DFLAGS)

SPLIT_SRCS = split.cpp
SPLIT_OBJS = $(SPLIT_SRCS:%.cpp=%.o)

OBJS = $(SPLIT_OBJS)

TARGETS = split


all : $(TARGETS)

split: $(SPLIT_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(TARGETS) $(OBJS)

test: split
	./split "abc def"
	./split " \"abc def\"  "
	./split " \"abc def\"  \"ghi  "



