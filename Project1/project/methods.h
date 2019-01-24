#ifndef METHODS_H
#define METHODS_H
#include <random>
#include <iostream>

int Metropolis(double R, std::mt19937_64& seed, double step, double alpha);
double wavefunction(double alpha, double R);
double local_energy(double step, double alpha, double R, double wf_old, double E);

class methods
{
public:
    methods();
};

#endif // METHODS_H
