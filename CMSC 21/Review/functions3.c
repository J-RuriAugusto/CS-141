#include <stdio.h>

//<return type> <function name> (<argument list>);
//function declaration
void displayhello();

int main(){
	int i=0;
	for(;i<5;i++)
		displayhello();

	return 0;
}

//function definition

void displayhello(){
	printf("Hello!\n");
}