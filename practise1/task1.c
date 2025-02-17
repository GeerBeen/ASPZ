#include <stdio.h>
#include <stdlib.h>
#define MAX 100;
#define MIN 1;


typedef struct {
   int *data;
   size_t size;
   size_t allocated_size;
} DynamicArray;


DynamicArray create_array(size_t size) {
   DynamicArray arr;
   arr.data = (int*)malloc(size * sizeof(int));


   if (arr.data == NULL) {
       printf("Malloc err!\n");
       arr.size = 0;
       arr.allocated_size = 0;
       return arr;
   }


   arr.size = size;
   arr.allocated_size = size * sizeof(int);
   printf("Allocated %zu bytes\n", arr.allocated_size);
   return arr;
}


void print_memory_status(DynamicArray *arr) {
   printf("Current usage: %zu bytes\n", arr->allocated_size);
   printf("Expected usage: %zu bytes\n", arr->size * sizeof(int));


   if (arr->allocated_size == arr->size * sizeof(int)) {
       printf("Memory alright\n");
   } else {
       printf("Memory error!\n");
       exit(1);
   }
}


void resize_array(DynamicArray *arr, size_t new_size) {
   int *new_data = (int*)realloc(arr->data, new_size * sizeof(int));


   if (new_data == NULL) {
       printf("Realloc error!\n");
       return;
   }


   arr->data = new_data;
   arr->allocated_size = new_size * sizeof(int);
   arr->size = new_size;
   printf("Realloc succes\n");
}


void free_array(DynamicArray *arr) {
   free(arr->data);
   arr->data = NULL;
   arr->size = 0;
   arr->allocated_size = 0;
   printf("Memory cleared/\n");
}


int get_int(const char* prompt, int min, int max){
   int n;
   int c;
   while(1){
       printf("%s",prompt);
       int i = scanf("%d", &n);
       if(i == 1 && n >= min && n <= max){
           while((c = getchar()) != '\n' && c != EOF);
           break;
       };
       printf("Error;\n");
       while((c = getchar()) != '\n' && c != EOF);
   }
   return n;
}


void fill_arr(DynamicArray *arr, size_t n){
   size_t size = arr->size;
   for(int i = 0; i < size; i++){
       arr->data[i] = (int)n;
   }
}


void print_arr(DynamicArray *arr){
   size_t size = arr->size;
   printf("arr: ");
   for(int i = 0; i < size; i++){
       printf("%d ", arr->data[i]);
   }
}


int main() {
   int min = MIN;
   int max = MAX;
   DynamicArray arr = create_array(get_int("enter int: ", min,max));
   print_memory_status(&arr);
   fill_arr(&arr, arr.size);
   print_arr(&arr);
   printf("\n");


   resize_array(&arr, get_int("enter int to realloc: ",min,max));
   print_memory_status(&arr);
   fill_arr(&arr, arr.size);
   print_arr(&arr);
   printf("\n");


   resize_array(&arr, get_int("enter int to realloc: ",min,max));
   print_memory_status(&arr);
   fill_arr(&arr, arr.size);
   print_arr(&arr);
   printf("\n");


   free_array(&arr);
   print_memory_status(&arr);


   return 0;
}
