#include "exercises.h"
#include <random>


int exe_b(){
    int MC = 10;
    double a_ho = 1.; //CHECK THIS UNIT

    double alpha = 1./(2*a_ho*a_ho);

    double R;
    double trial = exp(-alpha*R*R)*exp(-alpha*R*R);
    double step = 10E-3;

    double energy = 0; double dE; double wf;

    std::mt19937_64 seed(1234); //Mersienne twister

    for (int cycle = 0; cycle < MC; cycle++){

        dE = 0; wf = 0;
        wf = wavefunction(alpha, R);
        Metropolis(R, seed, step, alpha, wf);
        local_energy(step, alpha, R, wf, dE);
        energy += dE;
    }


  return 0;
}
