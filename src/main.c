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

    Texture2D e = LoadTexture("lol.png");

    Vector2 oaw[3] = {
        (Vector2){25, 0},
        (Vector2){0, 50},
        (Vector2){50, 50}
    };
    
    SnekObject opo = {
        .x = 100,
        .y = 100,
        .scalex = 100,
        .scaley = 100,
        .type = SNEK_POLY,
        .rot = 0,
        .color = GREEN,
        .debug_hitbox = true
    };

    opo.extra_data = (SnekObjectData){
        .verts = oaw,
        .vert_len = 3
    };

    SnekObject opo2 = {
        .x = 100,
        .y = 300,
        .scalex = 100,
        .scaley = 100,
        .type = SNEK_TEXTURE,
        .rot = 0,
        .color = WHITE,
        .debug_hitbox = false
    };

    opo2.extra_data = (SnekObjectData){
        .filter = TEXTURE_FILTER_BILINEAR,
        .texture = &e,
    };

    SnekObject* selected = NULL;
    SnekObject* hovered = NULL;

    objs = create_vector(sizeof(SnekObject));

    menu.mode = SNEKMODE_NONE;
    menu.rot_snap = 0;
    menu.snap = 0;

    vector_push_back(objs, &opo);
    vector_push_back(objs, &opo2);

    while (!WindowShouldClose())
    {
        hovered = snek_get_collided_obj(objs);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseY() > 50)
        {
            selected = hovered;
        }

        menu_the_objs(objs, &menu);

        BeginDrawing();
        ClearBackground(WHITE);

        draw_objs();

        DrawText(TextFormat("Collided: %p", selected), 0, 50, 20, BLACK);

        draw_menu(&menu, 0, 0, selected);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
