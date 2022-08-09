#ifndef my_pq_h
#define my_pq_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int eletype;

typedef struct{
	eletype *data;
	int size;
	int max_size;
}pq;

typedef struct{
	char name[30];
	char cmp[30];
	int age,p_id,pq_id;
}patient;

pq* create();
pq* creater(int sz);
int insert (pq *a, eletype x);
int delete_min(pq *a);
int prioritize(char *cmp);
patient* details(patient *p,int );
int print(patient *p,int n);
int search(char name[]);
char* consult_dept(char cmp[]);

#endif

