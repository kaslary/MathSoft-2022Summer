cc = g++
prom = test
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.cpp")
obj = $(src:%.cpp=%.o) 
 
$(prom): $(obj)
	$(cc) -o $(prom) $(obj) -std=c++11
 
%.o: %.cpp $(deps)
	$(cc) -c $< -o $@ -std=c++11

clean:
	rm -rf $(obj) $(prom)