#include <raylib/raylib.h>
#include <raylib/raygui.h>

void gui_text_box(float x, float y, float w, float h, char* text, int text_size, bool edit) {
    GuiTextBox((Rectangle){x,y,w,h},
        text,
        text_size,
        edit
    );
}

void gui_value_boxf(float x, float y, float w, float h, const char* text, char* text_value, float* value, bool edit) {
    GuiValueBoxFloat((Rectangle){x,y,w,h},
        text,
        text_value,
        value,
        edit
    );
}