
#include <raylib.h>
#include <vector>
#include "yeet/window.h"


Window::~Window() 
{
    CloseWindow();
}

void Window::start() 
{
    InitWindow(800, 450, "yeet");
}

void Window::update() 
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    int step_width_pixels = 5;	
    for(int i = 0; i < mesh.size(); ++i)
    {
	Vector2 anchor = { i * 5 + 100, 200 };
	draw_field(mesh[i].e, (Vector2){anchor.x,anchor.y}, e_col);
	draw_field(mesh[i].h, (Vector2){anchor.x,anchor.y}, h_col);
    }

    DrawLineV((Vector2){75, 100}, (Vector2){75, 300}, BLACK);
    DrawLineV((Vector2){50, 200}, (Vector2){800, 200}, BLACK);

    EndDrawing();
}

void Window::update_mesh(const std::vector<MeshNode> &mesh)
{
    this->mesh = mesh;
}

void Window::draw_field(double amplitude, Vector2 anchor, Color col)
{
    double height = amplitude * 200.0;
    
    Rectangle rect;
    if(height > 0) {
	rect = { anchor.x, anchor.y - height, 5, height };
    } else {
	rect = { anchor.x, anchor.y, 5, -height };
    }

    DrawRectangleRec(rect, col);
}

