#include <engine/array.h>
#include <engine/object.h>
#include <engine/movement.h>

#include <raylib/raygui.h>

#include <engine/renderer.h>

#include <math.h>
#include <stdio.h>

SnekObject* snek_get_collided_obj(VectorHandle ar) {
    for (size_t i = 0; i < vector_size(ar); i++)
    {
        SnekObject* poop = vector_get(ar, i);
        if (CheckCollisionPointRec(GetMousePosition(), poop->hitbox))
        {
            return poop;
        }
    }
    return NULL;
}

void draw_menu(Menu* menu, int x, int y, SnekObject* selected) {
    char _buf[256];
    
    Rectangle nonerect = {
        .x = x,
        .y = y,
        .width = 50,
        .height = 50
    };
    Rectangle moverect = {
        .x = x + 50,
        .y = y,
        .width = 50,
        .height = 50
    };
    Rectangle rotrect = {
        .x = x + 100,
        .y = y,
        .width = 50,
        .height = 50
    };
    Rectangle scalerect = {
        .x = x + 150,
        .y = y,
        .width = 50,
        .height = 50
    };

    if (GuiButton( nonerect, TextFormat("#%i#", ICON_CROSS)) // none
    )
    {
        menu->mode = SNEKMODE_NONE;
    }
    if (GuiButton( moverect, TextFormat("#%i#", ICON_CURSOR_MOVE)) // movement
    )
    {
        menu->mode = SNEKMODE_LOCATION;
    }
    if (GuiButton( rotrect, TextFormat("#%i#", ICON_ROTATE)) // rotation
    )
    {
        menu->mode = SNEKMODE_ROTATION;
    }
    if (GuiButton( scalerect, TextFormat("#%i#", ICON_SCALE)) // scaling
    )
    {
        menu->mode = SNEKMODE_SCALE;
    }

    // Information

    int key = GetKeyPressed();

    if (!selected)
    {
        return;
    }
    
    snprintf(_buf, sizeof(_buf), "%.2f", selected->x);
    gui_value_boxf(x + 250, y, 80, 40, "X:", _buf, &selected->x);

    snprintf(_buf, sizeof(_buf), "%.2f", selected->y);
    gui_value_boxf(x + 350, y, 80, 40, "Y:", _buf, &selected->y);

    snprintf(_buf, sizeof(_buf), "%.2f", selected->rot);
    gui_value_boxf(x + 500, y, 80, 40, "Rotation:", _buf, &selected->rot);

    snprintf(_buf, sizeof(_buf), "%.2f", selected->scalex);
    gui_value_boxf(x + 630, y, 80, 40, "Scale X:", _buf, &selected->scalex);

    snprintf(_buf, sizeof(_buf), "%.2f", selected->scaley);
    gui_value_boxf(x + 780, y, 80, 40, "Scale Y:", _buf, &selected->scaley);
}

int snap(float tosnap, int amountofsnap) {
    if (amountofsnap == 0)
    {
        return tosnap;
    }
    
    return roundf(tosnap);
}

void menu_the_objs(VectorHandle ar, Menu* menu) {
    SnekObject* obj = snek_get_collided_obj(ar);
    if (!obj || !IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        return;
    }

    // The object is valid and the mouse is down
    switch (menu->mode)
    {
    case SNEKMODE_LOCATION: {
        SetMouseCursor(MOUSE_CURSOR_CROSSHAIR);
        Vector2 melta = GetMouseDelta();

        obj->x += snap(melta.x, menu->snap);
        obj->y += snap(melta.y, menu->snap);

        break;
    }
    case SNEKMODE_ROTATION: {
        SetMouseCursor(MOUSE_CURSOR_RESIZE_NS);
        float my = GetMouseDelta().y;
        obj->rot += my;

        // clamp it
        if (obj->rot >= 360)
        {
            obj->rot = 0;
        }
        if (obj->rot < 0)
        {
            obj->rot = 360;
        }
        break;
    }

    case SNEKMODE_SCALE: {
        SetMouseCursor(MOUSE_CURSOR_RESIZE_ALL);
        Vector2 melta = GetMouseDelta();
        obj->scalex += snap(melta.x, menu->snap);
        obj->scaley += snap(melta.y, menu->snap);
        break;
    }
    
    default:
        break;
    }
}
