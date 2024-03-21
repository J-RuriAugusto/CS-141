#include <stdio.h>

//<return type> <function name> (<argument list>);
//function declaration
int length(char[]);
int smallest(int[],int);

int main(){
	char st1[50], st2[50];
	int l1, l2, arr[3] = {78,34,52};

	//scanf("%s%s",st1,st2);
	//l1 = length(st1);
	//l2 = length(st2);
	//printf("%i ---- %i\n",length(st1),length(st2));
	printf("%i\n",smallest(arr));
	return 0;
}

//function definition

int length(char st[]){
	int i=0;
	for(;st[i]!='\0';i++);

	return i;
}

int smallest(int A[], int s){

	int m = A[0], i=1;

	for(; i<s; i++)
		if(A[i] < m)
			m = A[i];

	return m;
}