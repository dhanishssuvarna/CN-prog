#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char res[100];

void sender(){
	int i,n,len;
	char frame[100], l[100];
	printf("Enter the number of frames : ");
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		printf("Enter the Frame No. %d : ",i+1);
		scanf("%s",&frame);
		len=strlen(frame);
		printf("No. of bytes in frame no. %d is %d\n",i+1,len);
		sprintf(l,"%d",len);
		strcat(l,frame);
		strcat(res,l);
	}
}

void receiver(){
	int i,j,len;

	printf("Received Frame\n");
	for(i=0;i<strlen(res);i++){
		len=res[i]-'0';
		for(j=i+1;j<=i+len;j++){
			printf("%c",res[j]);
		}
		i=i+len;
		printf("\n");
	}
}

void main(){
	sender();
	receiver();
}