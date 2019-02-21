#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <rfftw.h>              //the numerical simulation FFTW library

class Simulation {
	public:
		Simulation(); // constructor using defaul values

		void init_simulation(int);
		void FFT(int);
		int clamp(float);
		float max(float,float);
		void solve(int,fftw_real*,fftw_real*,fftw_real*,fftw_real*,fftw_real,fftw_real);
		void diffuse_matter(int fftw_real*,fftw_real*,fftw_real*,fftw_real*,fftw_real);
		void set_forces(void);
		void do_one_simulation_step(void);

	private:
		//--- SIMULATION PARAMETERS ------------------------------------------------------------------------
	    const int DIM = 50;             //size of simulation grid
	    double dt = 0.4;                //simulation time step
	    float visc = 0.001;             //fluid viscosity
	    fftw_real *vx, *vy;             //(vx,vy)   = velocity field at the current moment
	    fftw_real *vx0, *vy0;           //(vx0,vy0) = velocity field at the previous moment
	    fftw_real *fx, *fy;             //(fx,fy)   = user-controlled simulation forces, steered with the mouse
	    fftw_real *rho, *rho0;          //smoke density at the current (rho) and previous (rho0) moment
	    rfftwnd_plan plan_rc, plan_cr;  //simulation domain discretization

	    // Need this from the visualization section as the simulation itself stops, not just the visualization
	    int frozen = 0;               //toggles on/off the animation
}

#endif SIMULATION_H_