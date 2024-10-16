
#include <raylib.h>
#include <vector>
#include "yeet/window.h"

namespace yeet {

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
	Vector2 anchor = { i * 1.0 + 100, 200 };
	draw_field(mesh[i].e, (Vector2){anchor.x,anchor.y}, e_col);
	draw_field(mesh[i].h, (Vector2){anchor.x,anchor.y}, h_col);
    }

    DrawLineV((Vector2){75, 100}, (Vector2){75, 300}, BLACK);
    DrawLineV((Vector2){50, 200}, (Vector2){800, 200}, BLACK);

    DrawText("E Field = Red", 50, 350, 10, BLACK);
    DrawText("H Field = Blue", 50, 370, 10, BLACK);
    // DrawText(TextFormat("Sim Time = %f", 0.0), 50, 400, 10, BLACK);

    EndDrawing();
}

void Window::draw_field(double amplitude, Vector2 anchor, Color col)
{
    double height = amplitude * 100.0;
    
    Rectangle rect;
    if(height > 0) {
	rect = { anchor.x, anchor.y - height, 1, height };
    } else {
	rect = { anchor.x, anchor.y, 1, -height };
    }

    DrawRectangleRec(rect, col);
}

}

