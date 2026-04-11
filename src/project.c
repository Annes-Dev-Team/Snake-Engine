#include <engine/project.h>

#include <raylib/raylib.h>

const char* mainthing = "int main() {";
const char* endblock = "}";

void generate_project_files(SnekProject* proj) {
    MakeDirectory(proj->path);
    
    const char* src_path = TextFormat("%ssrc/", proj->path);
    TraceLog(LOG_DEBUG, src_path);

    MakeDirectory(src_path);

    SaveFileText(
        TextFormat(
            "%sproject.snek",
            proj->path
        ),
        ""
    );
}
