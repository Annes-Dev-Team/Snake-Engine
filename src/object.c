#include <engine/object.h>
#include <raylib/rlgl.h>

void snek_draw_obj(SnekObject* obj) {

    rlPushMatrix();
    rlTranslatef(obj->x + obj->scalex / 2, obj->y + obj->scaley / 2, 0);
    rlRotatef(obj->rot, 0, 0, 1);

    float targetx = -obj->scalex/2;
    float targety = -obj->scaley/2;

    obj->hitbox.x = obj->x;
    obj->hitbox.y = obj->y;
    obj->hitbox.width = obj->scalex;
    obj->hitbox.height = obj->scaley;
    

    
    switch (obj->type)
    {
    case SNEK_RECTANGLE: {
        Rectangle rec = {
            targetx,
            targety,
            obj->scalex,
            obj->scaley
        };
        DrawRectangleRec(rec, obj->color);
        break;
    }
    
    case SNEK_ELLIPSE:
        DrawEllipse(0,0, obj->scalex, obj->scaley, obj->color);
        break;

    case SNEK_LINE:
        DrawLine(targetx, targety, targetx + obj->scalex, targety + obj->scaley, obj->color);
        break;
    
    default:
        
        break;
    }
    rlPopMatrix();
    
    if (obj->debug_hitbox)
    {
        Color clr = {
            255 - obj->color.r,
            255 - obj->color.g,
            255 - obj->color.b,
            125
        };
        DrawRectangleRec(obj->hitbox, clr);
    }
}
