#include <stdio.h>
#include <stdlib.h>

typedef struct Elem{
	int data;
	struct Elem* next;
}Node;

typedef Node* list;

list addToList(list a,int num)
{

	list step, temp;
	int i=0;

	if(a==NULL)
	{
		a = (list)malloc(sizeof(Node));
		a->data = num;
		a->next = NULL;
	}
	else{
		step = a;

		while(step->next!=NULL)
		{
			step = step->next;
		}

		temp = (list)malloc(sizeof(Node));
		temp->data = num;
		temp->next = NULL;
		step->next = temp;
	}
	return a;
}

list deleteFromList(list a,int pos)
{
	int i=0;
	list temp, step;

	if(a!=NULL)
	{
		step = a;

		if(pos == 0)
		{
			a = a->next;
			step->next = NULL;
			free(step);
		}

		else{
			while(i++!=pos-1)
			step = step->next;
			temp = step->next;
			step->next = temp->next;
			temp->next = NULL;
			free(temp);
		}
	}
	return a;
}

void printList(list a)
{
	list temp = a;

	printf("List contains following elements : \n");

	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

void exer1(){

	int* pc;
	int c;
	c=22;
	printf("Address of c:%d\n",&c);
	printf("Value of c:%d\n\n",c);
	pc=&c;
	printf("Address of pointer pc:%d\n",pc);
	printf("Content of pointer pc:%d\n\n",*pc);
	c=11;
	printf("Address of pointer pc:%d\n",pc);
	printf("Content of pointer pc:%d\n\n",*pc);
	*pc=2;
	printf("Address of c:%d\n",&c);
	printf("Value of c:%d\n\n",c);

}

void bubble_sort(int *arr, int size)
{
	     int t;
	     for (int i = 0; i < size-1; i++)
	     {
	 	for(int j = 0; j < size - i - 1; j++)
	 	{
			if(arr[j]>arr[j+1])
			{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	     }
}

void exer2()
{
	int n;
	printf("Введите размер массива: ");
  	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	bubble_sort(a, n);
	for(int j = 0; j< n; j++)
		printf("%d%s", a[j], j == n ? "\n":" ");
}

void exer3()
{
	list a = NULL;
	int i, size;
	scanf("%d", &size);
	int arr[size];
	for(int i = 0; i<size;i++)
		scanf("%d",&arr[i]);
	if(size == 1)
		printf("Only one element in the list",arr[0]);
	else{
		for(i=0;i<size;i++)
			a = addToList(a,arr[i]);
		printList(a);

		do{
			printf("\nEnter position of element to be removed (0-%d) : ", size-1);

			scanf("%d",&i);

			if(i<size){
				a = deleteFromList(a,i);
				printList(a);
			}
		}while(i>size);
	}
}

void quick_sort(int *arr, int n)
{
	if(n < 2) return;

	int pivot = arr[n/2];

	int i,j;
	for(i = 0; j = n-1; i++, j--)
	{
		while(arr[i] < pivot) i++;
		while(arr[j] > pivot) j--;

		if(i>=j) break;

		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	quick_sort(arr,i);
	quick_sort(arr+i, n-i);
}

void exer4()
{
	int n;
	scanf("%d", &n);
	int input[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &input[i]);
	quick_sort(input, n);
	for(int j = 0; j < n; j++)
		printf("%d%s", input[j], j==n ? "\n":" ");
}

int main()
{
	//exer1();
	//exer2();
	//exer3();
	//exer4();
	return 0;
}
