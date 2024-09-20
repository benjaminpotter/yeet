
#include <math.h>
#include <vector>
#include "yeet/application.h"
#include "yeet/window.h"

Application::Application() :
    mesh(100)
{
    // Initialize the mesh.	
    for(int i = 0; i < mesh.size(); ++i)
    {
	double x = (double) i * 2.0 * 3.14159265 / (double) mesh.size();
	double t = 0.0;

	mesh[i].e = 0.0;
	mesh[i].h = 0.0;

	mesh[i].ep = 1.0;
	mesh[i].mu = 1.0;
    }

    // Indicate source.
    mesh[0].e = 1.0;
    mesh[1].e = 1.0;
    mesh[2].e = 1.0;
}

void Application::start() 
{
    window.start();

    const double b = 1.0;
    const double w = 1.0;

    while(!window.should_close()) 
    {
	for(int i = 1; i < mesh.size()-1; ++i)
	{
	    double dt = GetFrameTime(); 

	    // dH/dt = 1/mu * dE/dx
	    // dE/dt = 1/ep * dH/dx
	    
	    double h0 = mesh[i-1].h;
	    double h1 = mesh[i+1].h;

	    double e0 = mesh[i-1].e;
	    double e1 = mesh[i+1].e;

	    double dhdx = (h1 - h0) / 2.0;
	    double dedx = (e1 - e0) / 2.0;

	    mesh[i].e += mesh[i].ep * dhdx * dt;
	    mesh[i].h += mesh[i].mu * dedx * dt; 
	}	

	window.update_mesh(mesh);
	window.update();
    }
}

