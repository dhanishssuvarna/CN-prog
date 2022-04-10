#include<stdio.h>
#include<stdlib.h>

void main() {
		int size, cap, p[10], i, a, rate, delay, count, capacity, t, t1, t2;

		printf ("enter the queue size:");
		scanf ("%d",&size);

		printf ("enter leaky bucket capacity:");
		scanf ("%d",&cap);

		printf ("enter the size of the packets in the queue:");
		for (i=0; i<size; i++){
				scanf ("%d", &a);
				if (a > cap){
						i--;
						printf ("packets cannot be entered");
				}
				else
					p[i] = a;
		}

		printf ("enter the output rate:");
		scanf ("%d", &rate);

		delay = cap / rate;

		printf ("delay=%d\n", delay);

		count=size;
		while (count){
				capacity = cap;
				while (capacity >= p[0] && count > 0){
						printf ("\npacket of size %d is put into the bucket\n", p[0]);
						capacity = capacity - p[0];
						printf ("\navailable space %d\n", capacity);
						count--;
						for (i=0; i<count; i++)
							p[i] = p[i+1];
				}

				t = delay;
				long int t1= (long) time(NULL);
				long int t2 = (long) time(NULL);

				while ( (t2-t1) < delay){
						t2 = (long) time(NULL);
						if ( (delay-t) == (t2 - t1)){
								printf ("\ntransmitting packets in the leaky bucket:%d seconds\n", t);
								t--;
						}
				}

				printf ("\npackets in the queue:\n");
				for (i=0; i<count; i++)
					printf ("%d\t", p[i]);
		}
}