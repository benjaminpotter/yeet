
#include <chrono>
#include <math.h>
#include <vector>
#include "yeet/application.h"
#include "yeet/window.h"

namespace yeet {

void Application::start() 
{
    window.start();
    mesh.init(2000);

    bool play = false;
    auto last{std::chrono::steady_clock::now()};
    while(!window.should_close()) 
    {
	if(IsKeyPressed(KEY_SPACE))
	    play = !play;

	if(play || IsKeyPressed(KEY_S)) {
	    auto update{std::chrono::steady_clock::now()};
	    std::chrono::duration<double> update_duration{update-last};

	    if(update_duration.count() > 0.1) {
		mesh.step();
		window.update_mesh(mesh.get_mesh());
		last = update;	
	    }
	}
	    
	window.update();
    }
}

}
