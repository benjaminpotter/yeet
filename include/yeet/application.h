
#include "yeet/window.h"

#pragma once

namespace yeet {

class Application {

public:
    Application() = default;
    virtual ~Application() = default;

    void start();

private:

    Window window;
    Mesh mesh;
};

}

