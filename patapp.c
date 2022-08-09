#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pqueue.h"

int main() 
{
	int num,arr[30];int c,d,count=0;
	int b[30];
	printf("No of patients?");
	scanf("%d",&num);
	pq *plevel;
	plevel=creater(10);
	patient *p=(patient* ) malloc(num*sizeof(patient));
	details(p,num);
	int b1;
	for(b1=0;b1<num;b1++){
		int t=p[b1].pq_id;
		insert(plevel,t);
	}
	int i,c1,n,temp=0,p_no=0;
	for(i=0;i<num;i++){
		temp=delete_min(plevel);
		arr[i]=temp;
	}
	for (c = 0; c < num; c++)
  	{
    	for (d = 0; d < count; d++)
    	{
      		if(arr[c] == b[d])
        		break;
    	}
    	if (d == count)
    	{
      		b[count] = arr[c];
      		count++;
    	}
  	}
	int j;
	for(c1=0;c1<num;c1++)
	{
		for(n=0;n<num;n++){
		if(p[n].pq_id==b[c1])
		{
			p_no=n;
			
		if(b[c1]==1)
		{
			printf("\nPRIORITY LEVEL 1");
			printf("\nSeverely unstable, must be seen immediately by a physician. ");
		}
		if(b[c1]==2){
			printf("\n\nPRIORITY LEVEL 2");
			printf("\nPotentially unstable, must be seen promptly by a physician.");
		}
		if(b[c1]==3){
			printf("\n\nPRIORITY LEVEL 3");
			printf("\nStable and should be seen urgently by a physician .");
		}
		if(b[c1]==4){
			printf("\n\nPRIORITY LEVEL 4");
			printf("\nStable, may be seen non-urgently by a physician and require minimal testing or a procedure.");
		}
		if(b[c1]==5){
			printf("\n\nPRIORITY LEVEL 5");
			printf("\nStable, may be seen non-urgently by a physician and require no testing or a procedure. ");
		}
		char str[20];
		strcpy(str,consult_dept(p[p_no].cmp));
		print(p,p_no);
		printf("\nCALL %s",str);
		}
		}
	}
		char s[10],flag[2];
		printf("\n\nSearch Patient?(Y/N)");
		scanf("%s",flag);
		if(strcmp(flag,"Y")==0)
		{
			printf("\nEnter name to search...");
			scanf("%s",s);
			search(s);
		}
	return 0;
	
}

int print(patient *p,int n)
{
	FILE *fptr;
	fptr=fopen("patientlist.txt","a");
	printf("\nName: %s  \nAge: %d \nPatient ID: %d\nComplaint: %s",p[n].name,p[n].age,p[n].p_id,p[n].cmp);
	fprintf(fptr,"\n%s %d %d %s",p[n].name,p[n].age,p[n].p_id,p[n].cmp);
	fclose(fptr);
	return 0;
}

int search(char name[])
{
	char pat_name[20],cmp[30];
	int id,age;
	FILE *fptr;
	fptr=fopen("patientlist.txt","r");
	while(fscanf(fptr,"\n%s %d %d %[^\n]s",&pat_name,&age,&id,&cmp)!=EOF)
	{
		if(strcmp(name,pat_name)==0)
		{
			printf("\n\nName: %s  \nAge: %d\nPatient ID: %d\nComplaint: %s",pat_name,age,id,cmp);
		}	
	}
	fclose(fptr);
	return 0;
}

char* consult_dept(char cmp[])
{
	char fdept[9][20]={"neurosur.txt","neuro.txt","opthal.txt","ent.txt","derm.txt",
	"surgeon.txt","ortho.txt","psych.txt","genphys.txt"};
	int i;
	char s[20];
	char str[30],comp[20];
	for(i=0;i<9;i++)
	{	
		if(i==0)strcpy(s,"NEURO SURGEON");
		if(i==1)strcpy(s,"NEUROLOGIST");
		if(i==2)strcpy(s,"Ophthalmologist");
		if(i==3)strcpy(s,"ENT");
		if(i==4)strcpy(s,"DERMATOLOGIST");
		if(i==5)strcpy(s,"GENERAL SURGEON");
		if(i==6)strcpy(s,"ORTHOPEDIST");
		if(i==7)strcpy(s,"PSYCHIATRIST");
		if(i==8)strcpy(s,"GENERAL PHYSICIAN");
		
		FILE *fp;
		fp=fopen(fdept[i],"r");
		while(fscanf(fp,"\n%[^\n]s",&comp)!=EOF)
		{
			if(strcmp(cmp,comp)==0)
			{
				strcpy(str,s);
			}
		}
		fclose(fp);
	}
	return str;
}
