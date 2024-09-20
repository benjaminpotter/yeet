
#include "raylib.h"
#include "yeet/mesh.h"

#pragma once

class Window {

public:
    Window() = default;
    virtual ~Window();

    inline bool should_close() { return WindowShouldClose(); }

    void start();
    void update();
    void update_mesh(const std::vector<MeshNode> &mesh);

private:

    void draw_field(double amplitude, Vector2 anchor, Color col);

private:

    const Color e_col = { 0xFF, 0x00, 0x00, 0x80 };
    const Color h_col = { 0x00, 0x00, 0xFF, 0x80 };

    std::vector<MeshNode> mesh;

};
