#include <engine/array.h>
#include <engine/object.h>

typedef enum {
    SNEKMODE_NONE = 0,
    SNEKMODE_LOCATION,
    SNEKMODE_ROTATION,
    SNEKMODE_SCALE
} MenuModeType;

typedef struct
{
    int snap;
    int rot_snap;
    MenuModeType mode;
} Menu;


SnekObject* snek_get_collided_obj(VectorHandle ar);
void draw_menu(Menu* menu, int x, int y, SnekObject* selected);
void menu_the_objs(VectorHandle ar, Menu* menu);
