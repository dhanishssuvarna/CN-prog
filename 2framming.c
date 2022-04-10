#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void receiver(int *frame, int l){
	int i, msg[100], j=0, count=0;

	l=l-8;
	for(i=8;i<l;i++){
		if(frame[i]==0){
			if(count==5){
				count=0;
			}else{
				msg[j++]=frame[i];
				count=0;
			}
		}else{
			msg[j++]=frame[i];
			count++;
		}
	}

	printf("Received Frame\n");
	for(i=0;i<j;i++)
		printf("%d",msg[i]);
	printf("\n");
}

void sender(){
	int i, n, data[100], frame[100], j=0, count=0, zero=0, zeroadded=0, framelen;

	printf("Enter the no. of bits : ");
	scanf("%d",&n);

	printf("Enter the data for bits\n");
	for(i=0;i<n;i++){
		scanf("%d",&data[i]);
	}

	frame[j++]=0; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=0;
	for(i=0;i<n;i++){
		if(data[i]==0){
			frame[j++]=data[i];
			zero=1;
			count=0;
		}else{
			if((count==5)&& (zero==1)){
				frame[j++]=0;
				zeroadded++;
				count=0;
				frame[j++]=data[i];
				count++;
			}else{
				frame[j++]=data[i];
				count++;
			}
		}
	}
	frame[j++]=0; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=1; 
	frame[j++]=0;

	framelen=16+n+zeroadded;

	if(j==framelen){
		printf("The length of the frame sent is : %d\n", framelen);
		printf("Frame Sent\n");
		for(i=0;i<framelen;i++)
			printf("%d",frame[i]);
		printf("\n");
		receiver(frame,framelen);
	}else{
		printf("Error while bitstuffing\n");
	}
}

void main(){
	sender();
}