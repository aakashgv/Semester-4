#include<stdio.h>
#include<time.h>

void naive(char *,char *);
void kmp(char *,char *);
void rabin(char *,char *);
void fin(char *,char *);

int m,n;
char text[]="thisisitlsakfujoaisijflaskjfaoisijlkdsjfaosijdf";
char pat[]="is";

void main()
{
	clock_t t;
	double time;

	printf("\nNaive method : ");

	t=clock();
	naive(text,pat);
	t=t-clock();
	time=((double)t)/CLOCKS_PER_SEC;

	printf("\nTime taken : %lf",time);

	printf("\n\nKMP method : ");

	t=clock();
	kmp(text,pat);
	t=t-clock();
	time=((double)t)/CLOCKS_PER_SEC;

	printf("\nTime taken : %lf",time);

	printf("\nRabin method : ");

	t=clock();
	rabin(text,pat);
	t=t-clock();
	time=((double)t)/CLOCKS_PER_SEC;

	printf("\nTime taken : %lf",time);

	printf("\nFinite Automata method : ");

	t=clock();
	fin(text,pat);
	t=t-clock();
	time=((double)t)/CLOCKS_PER_SEC;

	printf("\nTime taken : %lf",time);
}