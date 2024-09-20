
#include "yeet/application.h"
#include <math.h>
#include <vector>
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
    }
}

void Application::start() 
{
    window.start();

    const double b = 1.0;
    const double w = 1.0;

    double t = 0.0; // in ms
    while(!window.should_close()) 
    {
	for(int i = 0; i < mesh.size(); ++i)
	{
	    double x = (double) i * 2.0 * 3.14159265 / (double) mesh.size();
	    double dt = GetFrameTime();

	    t += dt; 

	    mesh[i].e = sin(b*x + w*t/1000.0);
	    mesh[i].h = cos(b*x + w*t/1000.0);
	}	

	window.update_mesh(mesh);
	window.update();
    }
}

