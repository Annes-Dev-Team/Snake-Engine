#include <stddef.h>
typedef void* VectorHandle;

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Create a new vector that stores elements of `elem_size` bytes
VectorHandle create_vector(size_t elem_size);

// Destroy the vector
void destroy_vector(VectorHandle handle);

// Push element (data points to elem_size bytes)
void vector_push_back(VectorHandle handle, const void* data);

// Get number of elements
size_t vector_size(VectorHandle handle);

// Get pointer to element at index
void* vector_get(VectorHandle handle, size_t index);

#ifdef __cplusplus
}
#endif