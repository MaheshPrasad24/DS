#include<stdio.h>
void towers(int,char,char,char);
int main()
{
	int n;
	printf("Enter the number of disk:\n");
	scanf("%d",&n);
	towers(n,'S','A','D');
	return 0;
}
void towers(int n,char A,char B,char C)
{
	if(n==1)
	{
		printf("\nMove disk 1 from peg %c to peg %c",A,C);
		return;
	}
	towers(n-1,A,C,B);
	printf("\nMove disk %d from peg %c to peg %c",n,A,C);
	towers(n-1,B,A,C);
}
