#include <engine/base64.h>
#include <engine/assetsb64.h>
#include <raylib/raylib.h>

char* encode_image(const char* path) {
    Image img = LoadImage(path);

    // Force a known format (RGBA = 4 bytes per pixel)
    ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);

    size_t size = img.width * img.height * 4;

    char* buf = encode_base64((unsigned char*)img.data, size);

    UnloadImage(img);
    return buf;
}