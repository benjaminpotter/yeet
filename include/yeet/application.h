
#include "mesh.h"
#include <vector>
#include "yeet/window.h"

#pragma once

class Application {

public:
    Application();
    virtual ~Application() = default;

    void start();

private:

    Window window;
    std::vector<MeshNode> mesh;
};

