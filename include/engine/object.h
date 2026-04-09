#include <raylib/raylib.h>

#pragma once

typedef enum {
    SNEK_RECTANGLE = 0,
    SNEK_ELLIPSE,
    SNEK_LINE,
    
} SnekObjectType;

typedef struct
{
    float x;
    float y;
    float scalex;
    float scaley;
    float rot;
    Color color;
    Rectangle hitbox;
    bool debug_hitbox;

    SnekObjectType type;
} SnekObject;

typedef struct
{
    Camera2D cam;
} SnekCamera;

void snek_draw_obj(SnekObject* obj);
