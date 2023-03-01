#include <iostream>
#include <cstdlib>
#include "Window.h"
#include "Julia.h"
#include "bitmap.h"

void Julia::forward_step(){
	iteration_point = iteration_point * iteration_point + iteration_const;
	iteration_times++;
	if (iteration_times == max_iteration)flag_disconvergence = true;
	if (std::abs(iteration_point) > 2.0)flag_stop = true;
};

bool Julia::stop_criterion(){return flag_stop;};
bool Julia::is_disconvergence(){return flag_disconvergence;};

int main(int argc, char *argv[]){
	if (argc < 5){
		std::cerr << "Usage: " << argv[0]
				  << " filename ox oy dimension" << std::endl;
		exit(-1);
	}
	
	Window win(std::atof(argv[2]), std::atof(argv[3]), std::atof(argv[4]));
	double lpp = win.get_lpp();
	double dim = win.get_dimension();
	int width = win.get_width();
	int height = win.get_height();
	double ox = win.get_ox() - dim;
	double oy = win.get_oy() - dim / width * height;
	int N = 100;

	char *cache = new char[width * height * 3];

	for (int j = 0; j < height; j++){
		for (int i = 0; i < width; i++){
			double x = ox + lpp * i;
			double y = oy + lpp * j;
			int pos = width * j + i; 
			Julia man(std::complex<double>{x, y},N,std::complex<double>{std::atof(argv[5]), std::atof(argv[6])});
			while (!man.stop_criterion()){
				man.forward_step();
				if (man.is_disconvergence())break;
			}
			if (man.stop_criterion()){
				cache[pos * 3] = (char)255;
				cache[pos * 3 + 1] = (char)255;
				cache[pos * 3 + 2] = (char)255;
			}
			else{
				cache[pos * 3] = 0;
				cache[pos * 3 + 1] = 0;
				cache[pos * 3 + 2] = 0;
			}
		}
	}
	build_bmp(argv[1], width, height, cache);
	delete [] cache;
	return 0;
};
