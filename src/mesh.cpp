
#include <iostream>
#include <math.h>
#include "raylib.h"
#include "yeet/mesh.h"

namespace yeet {

void Mesh::init(int max_steps)
{
    mesh.resize(500);

    this->max_steps = max_steps;
    step_count = 0;

    imp0 = 377.0;

    // Initialize the mesh.	
    for(int i = 0; i < mesh.size(); ++i)
    {
	mesh[i].e = 0.0;
	mesh[i].h = 0.0;
    }
}

void Mesh::step()
{
    if(step_count >= max_steps)
	return;

    // dH/dt = 1/mu * dE/dx
    // dE/dt = 1/ep * dH/dx
    //
    // H' = H + 1/mu * dE/dx * dt
    // E' = E + 1/ep * dH/dx * dt
    //
    // H' = H + 1/mu * dE * (dt/dx)
    // E' = E + 1/ep * dH * (dt/dx)
    //
    // H' = H + 1/mu * dE * mesh_constant
    // E' = E + 1/ep * dH * mesh_constant

    // Update H.
    for(int i = 0; i < mesh.size()-1; ++i)
    {
	double e0 = mesh[i-0].e;
	double e1 = mesh[i+1].e;

	double dE = (e1 - e0);

	mesh[i].h += dE / imp0;
    }	

    // Update E.
    for(int i = 1; i < mesh.size(); ++i)
    {
	double h0 = mesh[i-1].h;
	double h1 = mesh[i+0].h;

	double dH = (h1 - h0);

	mesh[i].e += dH * imp0; 
    }	

    // Additive gaussian source at node 50.
    mesh[50].e += exp(-(step_count - 30.) * (step_count - 30.) / 100.);

    step_count++;
}

}

