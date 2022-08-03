/*This code will run on unix-based operating systems.
  Its shows a compliler error in windows because #include<sys/shm.h> is meant for unix-based operating systems.
*/
//C program to implement interprocess communication
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{

	int i;
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid=shmget((key_t)2345, 1024, 0666);
	printf("Key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("Process attached at %p\n",shared_memory);
	printf("Data read from shared memory is : %s\n",(char *)shared_memory);
}
