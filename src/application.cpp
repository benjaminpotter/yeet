
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <sstream>
#include <vector>
#include "yeet/application.h"
#include "yeet/window.h"

namespace yeet {

std::string get_utc() {
    // Get current time as a time_point
    auto now = std::chrono::system_clock::now();
    
    // Convert to time_t
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    
    // Convert to UTC struct tm
    std::tm utc_tm = *std::gmtime(&now_time_t);

    // Create a string stream to format the date and time
    std::ostringstream oss;
    oss << std::put_time(&utc_tm, "%y-%m-%d-%H-%M-%S");

    return oss.str();
}

void Application::start() 
{
    window.start();
    mesh.init(2000);

    // Create a unique ID for this runtime.
    std::string id = get_utc();
    std::ofstream file("./data/" + id + ".dat", std::ios::app);

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

		std::stringstream ss;
		for(auto node : mesh.get_mesh()) {
		    ss << node.e << ",";
		}
		
		std::string line = ss.str();
		line.pop_back();

		file << line << std::endl;
	    }
	}
	    
	window.update();
    }

    file.close();
}

}
