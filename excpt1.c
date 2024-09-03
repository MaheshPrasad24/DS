#include<stdio.h>
#include<stdlib.h>
struct day
{
	char* dayname;
	int date;
	char* activitydescription;
};
struct day* createday()
{
	struct day* newday=(struct day*)malloc(sizeof(struct day));
	newday->dayname=(char*)malloc(sizeof(char));
	newday->activitydescription=(char*)malloc(sizeof(char));
	
	printf("Enter the day name: ");
	scanf("%s",newday->dayname);
	printf("Enter date:");
	scanf("%d",&(newday->date));
	printf("Enter activity description;");
	scanf(" %[^\n]",newday->activitydescription);
	return newday;
}
	
	
void read(struct day* calender[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("Enter details for day %d:\n",i+1);
		calender[i]=createday();
	}
}
void display(struct day* calender[],int size)
{
	printf("\nWeek's Activity Details:\n");
	for(int i=0;i<size;i++)
	{
		printf("day %d:\n",i+1);
		printf("day name: %s\n",calender[i]->dayname);
		printf("date: %d\n",calender[i]->date);
		printf("activity description: %s\n",calender[i]->activitydescription);
		printf("\n");
	}
}
void freememory(struct day* calender[], int size)
{
	for(int i=0;i<size;i++)
	{
		free(calender[i]->dayname);
		free(calender[i]->activitydescription);
		free(calender[i]);
	}
}

int main()
{
	struct day* week[7];
	read(week,7);
	display(week,7);
	freememory(week,7);
	return 0;
}

