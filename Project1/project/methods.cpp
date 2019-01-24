#include "methods.h"

// Uniform distribution for s in [0, 1]
std::uniform_real_distribution<double> RNG(0.0,1.0);

int Metropolis(double R, double seed, double step, double alpha){
    double wf_old = wavefunction(alpha, R);
    //double r = RNG(seed);
    double R_t = R + RNG(seed)*step;
    double wf_new = wavefunction(alpha,R_t);
    int accept = 0;

    //Metropolis test
    if (RNG(seed) <= wf_new*wf_new/wf_old/wf_old){
        R = R_t;
        accept ++;
    }

    return 0;
}

double wavefunction(double alpha, double R){
    double wf = exp(-alpha*R*R);
    return wf;
}

double local_energy(double step, double alpha, double R, double wf_old, double E){
    double e_kinetic, R_p, R_m, wf_p, wf_m;
    e_kinetic = 0;

    R_p = R + step; R_m = R - step;
    wf_p = wavefunction(alpha, R_p);
    wf_m =wavefunction(alpha, R_m);

    e_kinetic -= (wf_m + wf_p - 2*wf_old);

    E = e_kinetic;

    return E;
}
