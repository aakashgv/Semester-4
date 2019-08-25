#include<stdio.h>

struct poker
{
	char card[2];
}b[5],w[5];

char card[13]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

void winner()
{
	int count1[13],count2[13],i,j,max1,max2;
	int suit1[4],suit2[4],samesuit1,samesuit2;
	int twos1,twos2;
	twos1=twos2=0;
	int consecutive1=1,consecutive2=1;
	int cnt1=0,flag1=-1,cnt2=0,flag2=-1;
	int hand1,hand2;
	int card1[5],card2[5];

	for(i=0;i<13;i++)
		count2[i]=count1[i]=0;

	for(i=0;i<4;i++)
		suit2[i]=suit1[i]=0;

	for(i=0;i<13;i++)
	{
		for(j=0;j<10;j++)
		{
			if(j<5)
			{
				if(card[i]==b[j].card[0])	
				{
					count1[i]+=1;
					switch(b[j].card[1])
					{
						case 'C':suit1[0]+=1;
							break;
						case 'D':suit1[1]+=1;
							break;
						case 'H':suit1[2]+=1;
							break;
						case 'S':suit1[3]+=1;
							break;
					}
				}
			}
			else
			{
				if(card[i]==w[j-5].card[0])	
				{
					count2[i]+=1;
					switch(w[j-5].card[1])
					{
						case 'C':suit2[0]+=1;
							break;
						case 'D':suit2[1]+=1;
							break;
						case 'H':suit2[2]+=1;
							break;
						case 'S':suit2[3]+=1;
							break;
					}
				}
			}
		}
	}

	max1=max2=1;

	for(i=0;i<13;i++)
	{
		if(count1[i] > max1)
			max1=count1[i];
		else if(count2[i] > max2)
			max2=count2[i];
		if(count1[i]==2)
			twos1++;
		if(count2[i]==2)
			twos2++;

		if(flag1==-1 && count1[i]>0)
		{
			flag1=1;
			cnt1++;
		}

		else if(flag1==1 && count1[i]==0 && cnt1<5)
		{
			flag1=0;
			consecutive1=0;
		}
		else if(flag1==1 && count1[i]>0)
			cnt1++;

		if(flag2==-1 && count2[i]>0)
		{
			flag2=1;
			cnt2++;
		}

		else if(flag2==1 && count2[i]==0 && cnt2<5)
		{
			flag2=0;
			consecutive2=0;
		}
		else if(flag2==1 && count2[i]>0)
			cnt2++;
	}

	for(i=0;i<4;i++)
	{
		if(suit2[i]==5)
			samesuit2=1;
		else if(suit1[i]==5)
			samesuit1=1;
	}
	j=-1;
	int k=-1;
	for(i=12;i>=0;i--)
	{
		if(count1[i]==1)
			card1[++j]=i;
		else if(count1[i]==2)
		{
			card1[++j]=i;
			card1[++j]=i;
		}
		else if(count1[i]==3)
		{
			card1[++j]=i;
			card1[++j]=i;
			card1[++j]=i;
		}
		else if(count1[i]==4)
		{
			card1[++j]=i;
			card1[++j]=i;
			card1[++j]=i;
			card1[++j]=i;
		}
		else if(count1[i]==5)
		{
			card1[++j]=i;
			card1[++j]=i;
			card1[++j]=i;
			card1[++j]=i;
			card1[++j]=i;
		}

		if(count2[i]==1)
			card2[++k]=i;
		else if(count2[i]==2)
		{
			card2[++k]=i;
			card2[++k]=i;
		}
		else if(count2[i]==3)
		{
			card2[++k]=i;
			card1[++k]=i;
			card1[++k]=i;
		}
		else if(count2[i]==4)
		{
			card2[++k]=i;
			card2[++k]=i;
			card2[++k]=i;
			card2[++k]=i;
		}
		else if(count2[i]==5)
		{
			card2[++k]=i;
			card2[++k]=i;
			card2[++k]=i;
			card2[++k]=i;
			card2[++k]=i;
		}
	}

	//straight flush
	if(max1==5 && consecutive1==1 && samesuit1==1)
	{
		hand1=9;
	}

	//four of a kind
	else if(max1==4)
	{
		hand1=8;
	}

	//full house
	else if(max1==3 && twos1==1)
	{
		hand1=7;
	}

	//flush
	else if(max1==5 && consecutive1==0 && samesuit1==1)
	{
		hand1=6;
	}

	//straight
	else if(max1==5 && consecutive1==1)
	{
		hand1=5;
	}

	//three of a kind
	else if(max1==3)
	{
		hand1=4;
	}

	//two pairs
	else if(max1==2 && twos1==2)
	{
		hand1=3;
	}

	//pair
	else if(max1==2)
	{
		hand1=2;
	}

	//high card
	else
	{
		hand1=1;
	}

	//straight flush
	if(max2==5 && consecutive2==1 && samesuit2==1)
	{
		hand2=9;
	}

	//four of a kind
	else if(max2==4)
	{
		hand2=8;
	}

	//full house
	else if(max2==3 && twos2==1)
	{
		hand2=7;
	}

	//flush
	else if(max2==5 && consecutive2==0 && samesuit2==1)
	{
		hand2=6;
	}

	//straight
	else if(max2==5 && consecutive2==1)
	{
		hand2=5;
	}

	//three of a kind
	else if(max2==3)
	{
		hand2=4;
	}

	//two pairs
	else if(max2==2 && twos2==2)
	{
		hand2=3;
	}

	//pair
	else if(max2==2)
	{
		hand2=2;
	}

	//high card
	else
	{
		hand2=1;
	}

	if(hand1>hand2)
	{
		printf("Black wins : higher rank hand\n");
		return;
	}

	else if(hand2>hand1)
	{
		printf("White wins : higher rank hand\n");
		return;
	}

	int high1=-1,high2=-1;
	switch(hand1)
	{
		case 1:
			for(i=0;i<5;i++)
			{
				if(card1[i] > card2[i])
				{
					printf("Black wins : high card\n");
					return;
				}
				else if(card2[i] > card1[i])
				{
					printf("White wins : high card\n");
					return;
				}
			}
			printf("DRAW\n");
			break;

		case 2:
			for(i=12;i>=0;i--)
			{
				if(count1[i]==2)
					high1=i;
				if(count2[i]==2)
					high2=i;
			}
			if(high1>high2)
			{
				printf("Black wins : pair\n");
				return;
			}
			else if(high1 < high2)
			{
				printf("White wins : pair\n");
				return;
			}

			for(i=0;i<5;i++)
			{
				if(card1[i] > card2[i])
				{
					printf("Black wins : pair\n");
					return;
				}
				else if(card2[i] > card1[i])
				{
					printf("White wins : pair\n");
				}
			}
			printf("DRAW");
			break;

		case 3:
			for(i=12;i>=0;i--)
			{
				if(count1[i]==2)
					high1=i;
				if(count2[i]==2)
					high2=i;
			}
			if(high1>high2)
			{
				printf("Black wins : 2 pairs\n");
				return;
			}
			else if(high1 < high2)
			{
				printf("White wins : 2 pairs\n");
				return;
			}

			for(i=high1;i>=0;i--)
			{
				if(count1[i]==2)
					high1=i;
				if(count2[i]==2)
					high2=i;
			}
			if(high1>high2)
			{
				printf("Black wins : 2 pairs\n");
				return;
			}
			else if(high1 < high2)
			{
				printf("White wins : 2 pairs\n");
				return;
			}

			for(i=0;i<5;i++)
			{
				if(card1[i] > card2[i])
				{
					printf("Black wins : 2 pairs\n");
					return;
				}
				else if(card2[i] > card1[i])
				{
					printf("White wins : 2 pairs\n");
				}
			}
			printf("DRAW");
			break;

		case 4:
			for(i=13;i>=0;i--)
			{
				if(count1[i]==3)
					high1=i;
				if(count2[i]==3)
					high2=i;
			}
			if(high1>high2)
			{
				printf("Black wins : 3 kind\n");
				return;
			}
			else if(high1 < high2)
			{
				printf("White wins : 3 kind\n");
				return;
			}
			break;

		case 5:
			for(i=0;i<5;i++)
			{
				if(card1[i] > card2[i])
				{
					printf("Black wins : straight\n");
					return;
				}
				else if(card2[i] > card1[i])
				{
					printf("White wins : straight\n");
				}
			}
			break;

		case 6:
			for(i=0;i<5;i++)
			{
				if(card1[i] > card2[i])
				{
					printf("Black wins : flush\n");
					return;
				}
				else if(card2[i] > card1[i])
				{
					printf("White wins : flush\n");
				}
			}
			break;

		case 7:
			for(i=13;i>=0;i--)
			{
				if(count1[i]==3)
					high1=i;
				if(count2[i]==3)
					high2=i;
			}
			if(high1>high2)
			{
				printf("Black wins : housefull\n");
				return;
			}
			else if(high1 < high2)
			{
				printf("White wins : housefull\n");
				return;
			}
			break;

		case 8:
			for(i=13;i>=0;i--)
			{
				if(count1[i]==4)
					high1=i;
				if(count2[i]==4)
					high2=i;
			}
			if(high1>high2)
			{
				printf("Black wins : 4 kind\n");
				return;
			}
			else if(high1 < high2)
			{
				printf("White wins : 4 kind\n");
				return;
			}
			break;

		case 9:
			for(i=0;i<5;i++)
			{
				if(card1[i] > card2[i])
				{
					printf("Black wins : straight flush\n");
					return;
				}
				else if(card2[i] > card1[i])
				{
					printf("White wins : straight flush\n");
				}
			}
			break;
	}
}

void main()
{
	FILE *f;
	f=fopen("input.txt","r");
	char temp[25];
	char black[5][2],white[5][2];
	int i;
	while(fscanf(f,"%s",b[0].card)!=EOF)
	{
		i=1;
		while(i<5)
		{
			fscanf(f,"%s",b[i].card);
			i++;
		}
		while(i<10)
		{
			fscanf(f,"%s",w[i-5].card);
			i++;
		}
		winner();
	}
	fclose(f);
}