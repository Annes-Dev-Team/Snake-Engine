#include <engine/array.h>

typedef struct
{
    VectorHandle objs;
    /*
    0 = executable
    1 = lib
    */
    unsigned char compile_mode;
    const char* path;
    
} SnekProject;

void generate_project_files(SnekProject* proj);
