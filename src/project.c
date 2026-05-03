#include <engine/project.h>
#include <engine/array.h>
#include <raylib/raylib.h>
#include <engine/object.h>
#include <cJSON.h>

const char* mainthing = "int main() {";
const char* endblock = "}";

cJSON* generate_project_snek(SnekProject* proj) {
    cJSON* root = cJSON_CreateObject();

    cJSON_AddStringToObject(root, "name", proj->name);
    cJSON_AddNumberToObject(root, "compile_mode", proj->compile_mode);
    
    cJSON* objs = cJSON_AddObjectToObject(root, "objects");
    for (size_t i = 0; i < vector_size(proj->objs); i++)
    {
        SnekObject* obj = vector_get( proj->objs, i);
        cJSON* e = cJSON_AddObjectToObject(objs, obj->name);
        snek_generate_obj_data(obj, e);
    }
    
    return root;
}

void generate_project_files(SnekProject* proj) {
    MakeDirectory(proj->path);
    
    const char* src_path = TextFormat("%s/src/", proj->path);
    const char* bin_path = TextFormat("%s/bin/", proj->path);
    
    TraceLog(LOG_DEBUG, src_path);

    MakeDirectory(src_path);
    MakeDirectory(bin_path);
    MakeDirectory(
        TextFormat("%s/assets", bin_path)
    );

    cJSON* snek = generate_project_snek(proj);
    const char* out = cJSON_Print(snek);
    TraceLog(LOG_DEBUG, out);

    SaveFileText(
        TextFormat(
            "%s/project.snek",
            proj->path
        ),
        out
    );

    if (proj->compile_mode == 0)
    {
        SaveFileText(
            TextFormat(
                "%smain.c", src_path
            ),
            ""
        );
    }
}
