#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_int(char* prompt, int min, int max){
	int n;
	int c;
	while(1){
		printf("%s", prompt);
		int i = scanf("%d", &n);
		if (i == 1 && n > min && n < max){
			while((c = getchar()) != '\n' && c != EOF);
			break;
		};
		printf("Error;\n");
		while((c = getchar()) != '\n' && c != EOF);
	}
	return n;
}

int main(){
	const int min = 0;
	const int max = SHRT_MAX;
	char* prompt = "Enter int:"; 
	int n = get_int(prompt,min,max);
	int *arr = (int*)malloc(n*sizeof(int));

	if(arr == NULL){
		printf("Malloc fail\n");
		return 1;
	}
	
	printf("Allocated %lu bytes.\n",n * sizeof(*arr));

	for(int i = 0; i < n; i++){
		arr[i] = n;
	}
	printf("Array: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	prompt = "Enter int to realloc: ";
	int new_n = get_int(prompt,min,max);

	arr = (int*)realloc(arr, new_n * sizeof(int));
	if(arr == NULL){
		printf("Realloc failed");
		return 0;
	}

	if(new_n > n){
		for(int i = n; i < new_n; i++){
			arr[i] = new_n;
		}
	}

	printf("New arr: ");

	for(int i = 0; i < new_n; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");
	
		
	return 0;
};
