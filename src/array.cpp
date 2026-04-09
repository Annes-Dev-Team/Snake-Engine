// array.cpp
#include <vector>
#include <cstdlib>
#include <cstring>

extern "C" {

// Opaque handle to a generic vector
typedef void* VectorHandle;
struct VecWrapper {
    std::vector<char> data;
    size_t elem_size;
};

// Create a new vector that stores elements of `elem_size` bytes
VectorHandle create_vector(size_t elem_size) {
    VecWrapper* v = new VecWrapper();
    v->elem_size = elem_size;
    return v;
}

// Destroy the vector
void destroy_vector(VectorHandle handle) {
    delete static_cast<struct VecWrapper*>(handle);
}

// Push element (data points to elem_size bytes)
void vector_push_back(VectorHandle handle, const void* data) {
    auto* v = static_cast<struct VecWrapper*>(handle);
    const char* bytes = static_cast<const char*>(data);
    v->data.insert(v->data.end(), bytes, bytes + v->elem_size);
}

// Get number of elements
size_t vector_size(VectorHandle handle) {
    auto* v = static_cast<struct VecWrapper*>(handle);
    return v->data.size() / v->elem_size;
}

// Get pointer to element at index
void* vector_get(VectorHandle handle, size_t index) {
    auto* v = static_cast<struct VecWrapper*>(handle);
    return v->data.data() + index * v->elem_size;
}

}
