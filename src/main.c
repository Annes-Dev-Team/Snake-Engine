#include <raylib/raylib.h>
#include <engine/object.h>
#include <engine/array.h>
#include <engine/movement.h>

#include <math.h>

VectorHandle objs;
Menu menu;

void draw_objs() {
    for (size_t i = 0; i < vector_size(objs); i++)
    {
        snek_draw_obj(vector_get(objs, i));
    }
    
}

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800,600,"Snake Engine");
    SetTargetFPS(60);
    
    SnekObject opo = {
        .x = 100,
        .y = 100,
        .scalex = 100,
        .scaley = 100,
        .type = SNEK_RECTANGLE,
        .rot = 0,
        .color = GREEN,
        .debug_hitbox = false
    };

    SnekObject opo2 = {
        .x = 100,
        .y = 300,
        .scalex = 100,
        .scaley = 100,
        .type = SNEK_ELLIPSE,
        .rot = 0,
        .color = RED,
        .debug_hitbox = true
    };

    objs = create_vector(sizeof(SnekObject));

    menu.mode = SNEKMODE_NONE;
    menu.rot_snap = 0;
    menu.snap = 0;

    vector_push_back(objs, &opo);
    vector_push_back(objs, &opo2);

    while (!WindowShouldClose())
    {

        menu_the_objs(objs, &menu);

        BeginDrawing();
        ClearBackground(WHITE);

        draw_objs();

        DrawText(TextFormat("Collided: %p", snek_get_collided_obj(objs)), 0, 50, 20, BLACK);

        draw_menu(&menu, 0, 0, snek_get_collided_obj(objs));

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
