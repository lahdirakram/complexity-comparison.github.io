#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>   /* gettimeofday, timeval (for timestamp in microsecond) */
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
unsigned long long int recSum(unsigned long long int n){
	if(n==0){
		return 0;
	}else{
		return (n+recSum(n-1));
	}
}
unsigned long long int forSum(unsigned long long int n){
	unsigned long long int somme=0,i;
	for(i=0;i<=n;i++){
		somme=somme+i;
	}
	return somme;
}
unsigned long long int whileSum(unsigned long long int n){
	unsigned long long int somme=0,i=0;
	somme=0;
	while(i<=n){
		somme=somme+i;
		i++;
	}
	return somme;
}
unsigned long long int doSum(unsigned long long int n){
	unsigned long long int somme=0,i=0;
	somme=0;
	do{
		somme=somme+i;
		i++;
	}while(i<=n);
	return somme;
}
long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}
int main(int argc, char *argv[]) {
	
	unsigned long long int n,i,somme,result;
	int p=0;
	unsigned long long int T[26];
	long t1,t2;
	
	
	for(i=0;i<26;i++){
			T[i]=pow(10,p);
			T[i+1]=2*T[i];
			p++;
//			printf("%llu\n",T[i]);
//			printf("%llu\n",T[i+1]);
			i++;	
	}
	printf("Recursive [");
	for(i=0;i<26;i++){
		t1=getMicrotime();
		result=recSum(T[10000]);
		t2=getMicrotime();
		printf("[%llu,%llu],",T[i],t2-t1);
	}
	printf("]\n %llu\n",result);
	
	printf("FOR [");
	for(i=0;i<26;i++){
		t1=getMicrotime();
		result=forSum(T[i]);
		t2=getMicrotime();
		printf("[%llu,%llu],",T[i],t2-t1);
	}
	printf("]\n %llu\n",result);
	printf("WHILE[");
	for(i=0;i<26;i++){
		t1=getMicrotime();
		result=whileSum(T[i]);
		t2=getMicrotime();
		printf("[%llu,%llu],",T[i],t2-t1);
	}
	printf("]\n %llu\n",result);
	printf("DO [");
	for(i=0;i<26;i++){
		t1=getMicrotime();
		result=doSum(T[i]);
		t2=getMicrotime();
		printf("[%llu,%llu],",T[i],t2-t1);
	}
	printf("]\n %llu\n",result);
	return 0;
}	














