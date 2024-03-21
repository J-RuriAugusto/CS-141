#include <stdio.h>

//<return type> <function name> (<argument list>);
//function declaration
void f1();
void f2();
void f3();
void f4();
void f7();

int main(){
	
	f1();
	f7();
	return 0;
}

//function definition



void f1(){
	printf("f1\n");
	f2();
	printf("from f2\n");
}
void f2(){
	printf("f2\n");
	f3();
	printf("from f3\n");
}

void f3(){
	printf("f3\n");
	f4();
	printf("from f4\n");
}

void f4(){
	printf("f4\n");
	f7();
	printf("from f7\n");
}

void f7(){
	printf("f7\n");
}