
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
    while(!window.should_close()) 
    {
	if(IsKeyPressed(KEY_SPACE))
	    play = !play;

	if(play || IsKeyPressed(KEY_S)) {
	    mesh.step();
	    window.update_mesh(mesh.get_mesh());
	}
	    
	window.update();
    }
}

}
