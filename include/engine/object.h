#include <raylib/raylib.h>

#pragma once

typedef enum {
    SNEK_RECTANGLE = 0,
    SNEK_ELLIPSE,
    SNEK_LINE,
    SNEK_POLY,
    SNEK_TEXTURE
    
} SnekObjectType;

typedef struct
{
    Texture2D* texture; // texture
    Vector2* verts; // verts array
    unsigned short vert_len; // array length
    TextureFilter filter; // texture filter
} SnekObjectData;

typedef struct
{
    float x;
    float y;
    float scalex;
    float scaley;
    float rot;
    Color color;
    Rectangle hitbox;
    SnekObjectData extra_data;
    bool debug_hitbox;

    SnekObjectType type;
} SnekObject;

typedef struct
{
    Camera2D cam;
} SnekCamera;

void snek_draw_obj(SnekObject* obj);
