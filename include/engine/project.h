#include <engine/array.h>
#include <cJSON.h>
typedef struct
{
    VectorHandle objs;
    /*
    0 = executable
    1 = lib
    */
    unsigned char compile_mode;
    const char* path;
    const char* name;
    
} SnekProject;

void generate_project_files(SnekProject* proj);
cJSON* generate_project_snek(SnekProject* proj);
