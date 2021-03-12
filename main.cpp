#include<stdio.h>
#include<stdlib.h>
int const N=30;
int main()
{
	printf("\nFirst of all, let's calculate the Fibonacci numbers\n using a static matrix(triangle of Pascal), which will take up extra memory.\n\n");
	//Перевод: в первую очередь, вычислим числа фибонначи с помощью статической матрицы, которая будет занимать лишнюю память.
	int i,j;
	int C[100][100],FI[100];
	float e,Gold,rat,rat1,dif;
	printf("Please, input precision of number: ");
	scanf("%f",&e);
	for(i=0;i<N;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0 && j==i) C[i][j]=1;
			else C[i][j]=C[i-1][j-1]+C[i-1][j]; //Я создал треугольник Паскаля
		}
	}
	//Теперь давайте вычислим с помощью него числа фибоначчи (не зря ведь я увлекаюсь математикой);
	for(int k=0;k<N;k++)
	{
		i=k;
		j=0;
		while(j<=i)
		{
			FI[k]+=C[i][j];	//Я не буду объяснять почему это числа Фибоначчи, примите как данность;
			i--;
			j++;
		}
	}
	//Так как отношение между близкостоящими числа
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