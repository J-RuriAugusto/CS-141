#include <stdio.h>

//<return type> <function name> (<argument list>);
//function declaration
int pew(int,int);

int main(){
	int x, y, z, ans=1, res=1,i;

	scanf("%i%i%i",&x,&y,&z); //x^(y^z)

	ans = pew(x,pew(y,z));

	printf("%i\n",ans);
	return 0;
}

//function definition

int pew(int b, int e){
	/*task of the function -- todo*/
	printf("Inside pew!\n");
	int i, ans;

	for(i=0,ans=1; i < e; i++)
		ans *= b; //ans = ans * b;

	return ans;
}