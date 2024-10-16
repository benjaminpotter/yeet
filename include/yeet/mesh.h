
#include <vector>

#pragma once

namespace yeet {

struct MeshNode 
{
    // Fields
    double e = 0.0;
    double h = 0.0;

    // Physical Properties
    double rec_ep;
    double rec_mu;
};

class Mesh {
public:
    Mesh() = default;
    virtual ~Mesh() = default;

    void init(int max_steps);
    void step();

    inline const std::vector<MeshNode> &get_mesh() { return mesh; }

private:

    double dt;
    double dx; 

    double imp0;
    double mesh_constant;

    int max_steps;
    int step_count;

    std::vector<MeshNode> mesh;

};

}
