#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int i,j,k;
char *text=(char*)malloc(sizeof(text));
char *pattern=(char*)malloc(sizeof(pattern));
char *replace=(char*)malloc(sizeof(replace));
printf("Enter text:\n");
scanf(" %[^\n]",text);
printf("Enter pattern:\n");
scanf(" %[^\n]",pattern);
printf("Enter the replace string:\n");
scanf(" %[^\n]",replace);
int textlength=strlen(text);
int patternlength=strlen(pattern);
int replacelength=strlen(replace);
for(i=0;i<=textlength-patternlength;i++)
{
	for(j=0;j<patternlength;j++)
	{
	 if(text[i+j]!=pattern[j])
	 {
		break;
	 }
	}
	if(j==patternlength)
	{
		printf("Position is %d\n",i);
		break;
	}
}
if(replacelength==patternlength)
{
	for(k=0;k<replacelength;k++)
	{
		text[i]=replace[k];
		i++;
	}
	printf("\nUpdated Text is:%s",text);
}
else
{
	printf("Not possible to replace the string\n");
}
}
	
