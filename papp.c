#include "pqueue.h"
#include <string.h>

patient* details(patient *p,int num)
{
	char temp,str[30];
	int x;
	for(x=0;x<num;x++){
		printf("name:");
		scanf("%s",&p[x].name);
		fflush(stdin);
		printf("complaints:");
		scanf("%[^;]s",&str);
		p[x].pq_id=prioritize(str);
		strcpy(p[x].cmp,str);
		fflush(stdin);
		printf("age:");
		scanf("%d",&p[x].age);
		srand(time(0));
		p[x].p_id=rand() % 100;
	}
	return p;
}

int prioritize(char *cmp)
{
	char level_1[6][30]={
	"head injury","convulsions","trauma",
	"stroke","drowsiness","unresponsive"};
	
	char level_2[6][30]={
	"acute abdominal pain","sudden loss of vision","fracture",
	"combative and hostile","suicidal thoughts","sudden onset slurred speech"};
	
	char level_3[6][30]={
	"lower quadrant pain","lower leg pain","palpitations",
	"breathlessness","nose bleed","swelling"};
	
	char level_4[5][30]={
	"skin rash","ankle injury","ear pain",
	"redness and watering of eyes","throat pain"};
	
	char level_5[7][30]={
	"prescription refill","common cold","loss of appetite","joint pain",
	"diminished vision","toothache","acne"};
	
	int p_level=0;
	int i,j,k,n,m;
	char *s;
	for(i=0;i<6;i++){
		s=level_1[i];
		if(!strcmp(cmp,s))
			p_level= 1;
	}
	

	for(j=0;j<6;j++){
		if(!strcmp(level_2[j],cmp))
			p_level= 2;
	}

	for(k=0;k<6;k++){
		if(!strcmp(level_3[k],cmp))
			 p_level= 3;
	}

	for(m=0;m<5;m++){
		if(!strcmp(level_4[m],cmp))
			 p_level= 4;
	}

	for(n=0;n<7;n++){
		if(!strcmp(level_5[n],cmp))
			 p_level= 5;
	}
	
	return p_level;
}
