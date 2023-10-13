#include <stdio.h>

//#define VECTOR_SIZE(x) (sizeof(x) / sizeof(*x))
#define NUMELTS 10

void	mediana(int *vector, int size)
{
	float		mediana;

	if (size % 2 == 0)
	{
		mediana =  (float)(vector[size/2] + vector[(size/2)-1]) / 2.0;
		printf("Mediana: %.1f\n", mediana);
	}
	else 
	{
		mediana = (float)vector[size/2]; 
		printf("Mediana: %.1f\n", mediana);
	}
}

int		main(void)
{
	int		vector[NUMELTS];
	int		len;
	int		i;
	
	printf("Insert vector length(0-10):\n");
	scanf("%d", &len);
	i = 0;
	printf("Insert numbers:\n");
	while(i < len)
		scanf("%d", &vector[i++]);
	mediana(vector, len);

	return (0);
}
