#include "array_list.h"

struct array_list* array_list_initialization() {
  struct array_list* list = malloc(sizeof(struct array_list));
  list->data = malloc(sizeof(void*) * ARRAY_LIST_INITIAL_CAPACITY);
  list->size = 0;
  list->capacity = ARRAY_LIST_INITIAL_CAPACITY;
  return list;
}

void array_list_add(struct array_list* list, void* element) {
  if (list->size >= list->capacity) {
    size_t previous_capacity = list->capacity;
    list->capacity += ARRAY_LIST_INITIAL_CAPACITY;
    list->data = realloc(list->data, sizeof(void*) * list->capacity);
    for (size_t index = previous_capacity; index < list->capacity; index++) {
      list->data[index] = NULL;
    }
  }
  list->data[list->size] = element;
  list->size++;
}

void array_list_remove(struct array_list* list, size_t index) {
  if (index >= list->size) {
    return;
  }
  for (size_t i = index + 1; i < list->size - 1; i++) {
    list->data[i - 1] = list->data[i];
  }
  list->size--;
}

void* array_list_get(struct array_list* list, size_t index) {
  if (index >= list->size) {
    return NULL;
  }
  return list->data[index];
}

void array_list_free(struct array_list* list) {
  free(list->data);
  free(list);
}
