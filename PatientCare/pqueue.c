#include "pqueue.h"

pq* create()
{	
	pq* a = (pq* ) malloc(sizeof(pq));
	printf("Enter the maximum size : ");
	scanf("%d",&(a->max_size));
	a->size = 1;
	a->data = (eletype *)malloc(a->max_size*sizeof(eletype));
	a->data[0] = -999;
	return a;
}

pq* creater(int sz)
{
	pq* a = (pq*)malloc(sizeof(pq));
	a->max_size=sz;
	a->size = 1;
	a->data = (eletype*)malloc(a->max_size * sizeof(eletype));
//	a->name = (char*)malloc(a->max_size * sizeof(char));
	a->data[0] = -999;
	return a;
}

int insert(pq *a, eletype x)
{
	int i = a->size;
	a->data[i]= x;
	(a->size)++;
	while(i>1)
	{
		if (a->data[i] < a->data[i/2])
		{
			eletype temp = a->data[i];
			a->data[i] = a->data[i/2];
			a->data[i/2] = temp;
			i = i/2;
		}
		else
		{
			break;
		}
	}
	return 0;
}

int delete_min(pq *a)
{
	eletype x = a->data[1];
	a->data[1]=a->data[a->size-1];
	int i=1;
    int  min_id;
	while(2*i<a->size)
	{
	if(a->data[i]>a->data[2*i])
	{
		min_id = 2*i;
		if((2*i+1)<a->size)
		{
			if(a->data[2*i]> a->data[2*i+1])
				min_id = 2*i+1; 
		}
		eletype temp = a->data[i];
		a->data[i] = a->data[min_id];
		a->data[min_id] = temp;
		i=min_id;
	}
	else if (a->data[i]>a->data[2*i+1] && 2*i+1<a->size)
    {
 		min_id = 2*i+1;
 		eletype temp = a->data[i];
 		a->data[i] = a->data[min_id];
 		a->data[min_id] = temp;
 		i = min_id;
 	}

	else
		break;
    }
    a->size--;
	return x;
}

