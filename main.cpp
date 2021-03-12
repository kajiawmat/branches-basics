#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("\nDue to the fact that the static massive takes up too much space, \nthe bosses urgently demanded to use dynamic massives\n\n");
	//Перевод: в силу того, что статический массив занимает слишком много места, начальство потребовало срочно воспользоваться динамическими массивами.
	int i,j,n;
	int FI[100]={0};
	int **C;
	float e,Gold,rat,rat1,dif;
	printf("Please, input size of massive:\t ");
	scanf("%i",&n);
	printf("Please, input precision of number:\t ");
	scanf("%f",&e);
	C= new int* [n];
	for(i=0;i<n;i++)
	{	
		C[i]= new int [i+1];
		for(j=0;j<=i;j++)
		{
			if(j==0 || j==i) C[i][j]=1;
			else C[i][j]=C[i-1][j-1]+C[i-1][j]; //Я создал треугольник Паскаля
		}
	}
	//Теперь давайте вычислим с помощью него числа фибоначчи (не зря ведь я увлекаюсь математикой);
	for(int k=0;k<n;k++)
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
	//Так как отношение между близкостоящими числами стремится к золотому сечению, то
	rat=(double)FI[1]/FI[0];
	rat1=(double)FI[2]/FI[1];
	i=1;
	dif=rat1-rat;
	if (dif<0) dif=-dif;
	while(dif>e)
	{
		i++;
		if(i==(n-1)) 
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
	for(i=0;i<n;i++)
	{
		delete []C[i];
	}
	delete []C;
	return 0;
}