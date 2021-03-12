#include<stdio.h>
#include<stdlib.h>
int const N=30;
int main()
{
	printf("\nIn this branch \"we decided\" modify this algoritm Thanks to cycle.\n\n");
	//Перевод: В этой ветке мы решили модифицировать алгоритм с помощью цикла (а то зачем нам массив в самом деле).
	int i;
	int FI[N];
	float e,Gold,rat,rat1,dif;
	printf("Please, input precision of number: ");
	scanf("%f",&e);
	FI[0]=1;
	FI[1]=1;
	for(i=2;i<N;i++)
	{
		FI[i]=FI[i-1]+FI[i-2];
	}
	//Так как отношение между близкостоящими числами стремится к золотому сечению, то
	rat=(double)FI[1]/FI[0];
	rat1=(double)FI[2]/FI[1];
	i=1;
	dif=rat1-rat;
	if (dif<0) dif=-dif;
	while(dif>e)
	{
		i++;
		if(i==(N-1)) 
		{
			printf("Massive of numbers is too small for this");
			break;
		}
		rat=rat1;
		rat1=(double)FI[i+1]/FI[i];
		dif=rat1-rat;
		if (dif<0) dif=-dif;
	}
	Gold=rat1;
	printf("\n\nGolden ratio is equal:\t %f",Gold);
	return 0;
}