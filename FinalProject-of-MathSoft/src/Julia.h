#ifndef __MANDERBROT__
#define __MANDERBROT__
#include <complex>

class Iteration{
protected:
	std::complex<double> iteration_point{0.0, 0.0};
	int iteration_times = 0;
	int max_iteration = 20;
	std::complex<double> iteration_const{0.0, 0.0};
	bool flag_stop = false;
	bool flag_disconvergence = false;
public:
	explicit Iteration(){};
	explicit Iteration(std::complex<double> _ip,
			  int _max_it,
			  std::complex<double> _ic) :
		iteration_point(_ip),
		max_iteration(_max_it),
		iteration_const(_ic) {};
	explicit Iteration(double _ix,
			  double _iy,
			  int _max_it,
			  double _cx,
			  double _cy) :
		iteration_point(std::complex<double>{_ix, _iy}),
		max_iteration(_max_it),
		iteration_const(std::complex<double>{_cx, _cy}) {};
	const std::complex<double> get_iteration_point()const{return iteration_point;};
	const int get_iteration_times()const{return iteration_times;};
	const std::complex<double> get_iteration_const()const{return iteration_const;};
	const int get_max_iteration(){return max_iteration;};
	virtual void forward_step() = 0;
	virtual bool stop_criterion() = 0;
	virtual bool is_disconvergence() = 0;
};

class Julia : public Iteration{
public:
	explicit Julia() : Iteration() {};
	explicit Julia(std::complex<double> _ip,
			   int _max_it,
			   std::complex<double> _ic) : Iteration(_ip, _max_it, _ic) {};
	explicit Julia(double _ix,
			   double _iy,
			   int _max_it,
			   double _cx,
			   double _cy) : Iteration(_ix, _iy, _max_it, _cx, _cy) {};
	virtual void forward_step();
	virtual bool stop_criterion();
	virtual bool is_disconvergence();
};


#endif
