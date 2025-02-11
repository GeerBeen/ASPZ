#include <stdio.h>

int get_int(const char *prompt){
	int num;
	while(1){
		printf("%s ", prompt);

		if(scanf("%d", &num) == 1){
			int c;
			while((c = getchar()) != '\n' && c != EOF);
			return num;
		}
		printf("Error, enter integer!\n");
		int c;
		while((c = getchar()) != '\n' && c != EOF);
	}	
}

int main(){
	int number = get_int("Enter int:");
	printf("Your num: %d\n", number);
	return 0;
}
