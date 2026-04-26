#include <engine/project.h>

#include <raylib/raylib.h>

const char* mainthing = "int main() {";
const char* endblock = "}";

void generate_project_files(SnekProject* proj) {
    MakeDirectory(proj->path);
    
    const char* src_path = TextFormat("%s/src/", proj->path);
    const char* bin_path = TextFormat("%s/bin/", proj->path);
    
    TraceLog(LOG_DEBUG, src_path);

    MakeDirectory(src_path);
    MakeDirectory(bin_path);

    SaveFileText(
        TextFormat(
            "%s/project.snek",
            proj->path
        ),
        ""
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
