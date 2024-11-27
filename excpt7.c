 #include<stdio.h>
 #include<stdlib.h>
 struct node
 {
 	char usn[25],name[25],programme[25];
 	int sem;
 	long int phone;
 	struct node *next;
 };
 typedef struct node *NODE;
 NODE front=NULL;
 int count=0;
 NODE create()
 {
 	NODE snode;
 	snode=(NODE)malloc(sizeof(struct node));
 	printf("\nEnter the USN,Name<Programme,sem,PhoneNo of the student:");
 	scanf("%s %s %s %d %ld",snode->usn,snode->name,snode->programme,&snode->sem,&snode->phone);
 	snode->next=NULL;
 	count++;
 	return snode;
 }
 NODE insertfront()
 {
 	NODE temp;
 	temp=create();
 	if(front==NULL)
 	{
 		return temp;
 	}
 	temp->next=front;
 	return temp;
 }
 NODE deletefront()
 {
 	NODE temp;
 	if(front==NULL)
 	{
 		printf("Linked list is empty");
 		return NULL;
 	}
 	if(front->next==NULL)
 	{
 		printf("\n The Student node with usn.%s is deleted",front->usn);
 		count--;
 		free(front);
 		return NULL;
 	}
 	temp=front;
 	front=front->next;
 	printf("\n The student node with usn.%s is deleted",temp->usn);
 	count--;
 	free(temp);
 	return front;
 }
  NODE deleteend()
 {
 	NODE cur,prev;
 	if(front==NULL)
 	{
 		printf("Linked list is empty");
 		return NULL;
 	}
 	if(front->next==NULL)
 	{
 		printf("\n The Student node with usn.%s is deleted",front->usn);
 		count--;
 		free(front);
 		return NULL;
 	}
 	prev=NULL;
 	cur=front;
 	while(cur->next!=NULL)
 	{
 		prev=cur;
 		cur=cur->next;
 	}
 	printf("\n The student node with usn.%s is deleted",cur->usn);
 	free(cur);
 	prev->next=NULL;
 	count--;
 	return front;
 }
 NODE insertend()
 {
 	NODE cur,temp;
 	temp=create();
 	if(front==NULL)
 	{
 		return temp;
 	}
 	cur=front;
 	while(cur->next!=NULL)
 	{
 		cur=cur->next;
 	}
 	cur->next=temp;
 	return front;
 }
 void display()
 {
 	NODE cur;
 	int num=1;
 	if(front==NULL)
 	{
 		printf("\n No Contents to display in SLL\n");
 		return;
 	}
 	printf("\nThe contents of SLL:\n");
 	cur=front;
 	while(cur!=NULL)
 	{
 		printf("\n||%d|| USN:%s| Name:%s| Programme:%s| Sem:%d| Ph:%ld|",num,cur->usn,cur->name,cur->programme,cur->sem,cur->phone);
 		cur=cur->next;
 		num++;
 	}
 	printf("\n No. of student nodes is %d\n",count);
 }
 void stackdemo()
 {
 	int ch;
 	while(1)
 	{
 		printf("\n~~~Stack Demo using SLL~~~\n");
 		printf("\n1:Push operation \n2:Pop operation \n3:Display \n4:Exit\n");
 		printf("\nEnter your choice for stack demo:");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:front=insertfront();
 				break;
 			case 2:front=deletefront();
 				break;
 			case 3:display();
 				break;
 			default:return;
 		}
 	}
 	return;
 }
 int main()
 {
 	int ch,i,n;
 	while(1)
 	{
 		printf("\n****Menu***");
 		printf("\n Enter your choice for SLL operation\n");
 		printf("\n 1:Create SLL of student Nodes");
 		printf("\n 2:Display Status");
 		printf("\n 3:Insert At End");
 		printf("\n 4:Delete At the End");
 		printf("\n 5:Stack Demon using SLL(Insertion and Deletion at Front)");
 		printf("\n 6:Exit\n");
 		printf("\n Enter your choice:");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:printf("\nEnter the number of students: ");
 				scanf("%d",&n);
 				for(i=1;i<=n;i++)
 				front=insertfront();
 				break;
 			case 2:display();
 				break;
 				case 3:front=insertend();
 				break;
 				case 4:front=deleteend();
 				break;
 			case 5:stackdemo();
 				break;
 			case 6:exit(0);
 			default:printf("\nPlease enter the valid choice");
 		}
 	}
 }
 
