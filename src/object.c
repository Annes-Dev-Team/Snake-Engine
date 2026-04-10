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
        Rectangle rec = {
            targetx,
            targety,
            obj->scalex,
            obj->scaley
        };
    switch (obj->type)
    {
    case SNEK_RECTANGLE: {
        DrawRectangleRec(rec, obj->color);
        break;
    }
    
    case SNEK_ELLIPSE:
        DrawEllipse(0,0, obj->scalex, obj->scaley, obj->color);
        break;

    case SNEK_LINE:
        DrawLine(targetx, targety, targetx + obj->scalex, targety + obj->scaley, obj->color);
        break;
    
    case SNEK_TEXTURE: {
        SetTextureFilter(*obj->extra_data.texture, obj->extra_data.filter);
        DrawTexturePro(*obj->extra_data.texture, 
            (Rectangle){ 0, 0, (float)obj->extra_data.texture->width, (float)obj->extra_data.texture->height },
            rec,
            (Vector2){0, 0},
            0, obj->color
        );
    }

    case SNEK_POLY: {
        DrawTriangleFan(obj->extra_data.verts, obj->extra_data.vert_len, obj->color);
    }
    
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
