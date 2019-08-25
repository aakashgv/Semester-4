#include<stdio.h>

int n=15,a[15];

void flip(int k)
{
	int i,b[n],j=k-1;
	for(i=k;i<n;i++)
		b[i]=a[i];
	for(i=n-1;i>=k;i--)
		a[++j]=b[i];
}

int checkorder()
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1])
			return 0;
	}
	return 1;
}

void main()
{
	int i,max=0,order=1,min=0,j,m=-1,k,c[15];
	char str[50],word[3],ch;
	j=-1;
	n=-1;
	FILE *f;
	f=fopen("input.txt","r");
	while(fgets(str,50,f)!=NULL)
	{
		j=-1;
		n=-1;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]==' ')
			{
				word[++j]='\0';
				a[++n]=atoi(word);
				word[0]='\0';
				j=-1;
			}
			else
				word[++j]=str[i];
		}
		word[++j]='\0';
		a[++n]=atoi(word);
		n++;
		flip(0);
		for(i=0;i<n;i++)
			c[i]=a[i];
		for(i=0;i<n;i++)
		{
			printf("%d ",c[i]);
		}
		printf("\n");
		for(j=0;j<n-1;j++)
		{
			if(checkorder()==1)
			{
				printf("0\n");
				break;
			}
			max=j;
			for(i=j;i<n;i++)
				if(a[max] < a[i])
					max=i;

			if(max!=n-1)
			{
				flip(max);
				printf("%d ",max+1);
			}
		
			flip(j);
			printf("%d ",j+1);
			if(checkorder()==1)
			{
				printf("0\n");
				break;			
			}
		}
	}
}
