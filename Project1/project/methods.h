#ifndef METHODS_H
#define METHODS_H
#include <random>
#include <iostream>

void Metropolis(double& R, std::mt19937_64& seed, double step, double alpha, double wf);
double wavefunction(double alpha, double R);
double local_energy(double step, double alpha, double R, double wf_old);

class methods
{
public:
    methods();
};

#endif // METHODS_H
