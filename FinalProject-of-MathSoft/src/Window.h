#ifndef __MYWINDOW__
#define __MYWINDOW__

struct Point2d{
	double x;
	double y;
};

class Window{
private:
	Point2d origin = {0.0, 0.0};
	double dimension = 5.0;
	static const int height = 1080;
	static const int width = 1920;
public:
	explicit Window(){};
	explicit Window(double _ox, double _oy, double _d){
		origin.x = _ox;
		origin.y = _oy;
		dimension = _d;
	};

	const double get_dimension()const{return dimension;};
	const double get_height()const{return height;};
	const double get_width()const{return width;};
	const double get_ox()const{return origin.x;};
	const double get_oy()const{return origin.y;};
	const double get_lpp()const{return (dimension * 2.0 / width);};
};

#endif