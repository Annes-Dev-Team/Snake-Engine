#include <engine/array.h>
#include <cJSON.h>

typedef enum {
    COMPILE_EXECUTABLE = 0,
    COMPILE_LIB
} CompileMode;

typedef struct
{
    VectorHandle objs;
    VectorHandle images;
    VectorHandle sounds;
    /*
    0 = executable
    1 = lib
    */
    CompileMode compile_mode;
    const char* path;
    const char* name;
    
} SnekProject;

void generate_project_files(SnekProject* proj);
cJSON* generate_project_snek(SnekProject* proj);
