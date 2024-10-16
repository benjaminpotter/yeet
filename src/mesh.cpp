
#include <iostream>
#include <math.h>
#include "raylib.h"
#include "yeet/mesh.h"

namespace yeet {

void Mesh::init()
{
    mesh.resize(500);

    double c = 299792458.0; // m/s

    // Minimum visible wavelength in humans is 380nm.
    // dx must be <= 10% of this.
    dx = 1550.0 / 9.0; // nm

    // In order to prevent numerical dispersion, dt must be <= dx/c.
    // c = 299 792 458 m/s
    dt = dx / c; // nsec
    
    // Cache the result of these values.
    mesh_constant = dt / dx; // s/m
			     
    std::cout << "init (dx, dt): (" << dx << ", " << dt << ")" << std::endl;
    std::cout << "mesh constant: " << mesh_constant << std::endl;

    double ep0 = 8.8541878188e-12; // Constant permittivity of free space.
    double mu0 = 1.2566370612e-06; // Constant permeability of free space.

    // Initialize the mesh.	
    for(int i = 0; i < mesh.size(); ++i)
    {
	mesh[i].e = 0.0;
	mesh[i].h = 0.0;

	mesh[i].rec_ep = 1.0/ep0;
	mesh[i].rec_mu = 1.0/mu0;
    }

    // Initialize source.

    // B = 2pi / lambda => lambda = 500nm
    // const double b =  2 * 3.14159265 / 500e-9;
    // for(int i = 0; i < 100; ++i)
    // {
    //     double x_e = (double) (i - 0.5) / 100.0;
    //     double x_h = (double) (i - 0.0) / 100.0;

    //     mesh[i + 100].e = sin(b * x_e);
    //     mesh[i + 100].h = cos(b * x_h);
    // }
    
    for(int i = 0; i < 100; ++i)
	mesh[i+100].e = 1.0;

}

void Mesh::step()
{
    for(int i = 1; i < mesh.size()-1; ++i)
    {
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
	
	double h0 = mesh[i-0].h;
	double h1 = mesh[i+1].h;

	double e0 = mesh[i-1].e;
	double e1 = mesh[i+0].e;

	double dH = (h1 - h0);
	double dE = (e1 - e0);

	// std::cout << dH * mesh_constant << std::endl;

	mesh[i].e += mesh[i].rec_ep * dH * mesh_constant; // V/m
	mesh[i].h += mesh[i].rec_mu * dE * mesh_constant; // A/m
    }	

    step_count++;
}

}

