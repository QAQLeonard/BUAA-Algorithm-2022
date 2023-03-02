#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1000050];
int current_num;

const int E =1000000005;

int cmpfunc(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void Insert(int elem)
{
	//将新添加的结点插入到队尾
	arr[current_num] = elem;
	current_num++;
	AdjustUp(current_num-1);
}

void AdjustUp(int i)
{
	int elem=arr[i];
	int selfIndex = i;
	int fatherIndex = (selfIndex - 1) / 2;
	//将新插入的元素放入到合理的位置
	while (fatherIndex >= 0 && selfIndex != 0)
	{
		if (arr[fatherIndex] <= elem)
			break;
		arr[selfIndex] = arr[fatherIndex];
		selfIndex = fatherIndex;
		fatherIndex = (fatherIndex - 1) / 2;
	}
	arr[selfIndex] = elem;
}

void AdjustDown(int i)
{
	if (current_num == 0)
		return;
	//堆顶元素
	int topEle = arr[i];
	int fatherIndex = i;
	int childIndex = fatherIndex * 2 + 1;
	while (childIndex < current_num)
	{
		//如果右孩子也存在，指向左右孩子中较小的结点
		if (childIndex + 1 < current_num && arr[childIndex] > arr[childIndex + 1])
			childIndex++;
		if (arr[childIndex] > topEle)
			break;
		arr[fatherIndex] = arr[childIndex];
		fatherIndex = childIndex;
		childIndex = childIndex * 2 + 1;
	}
	arr[fatherIndex] = topEle; 
}


void Delete(int x)
{
	int i;
	for (i = 0; i < current_num; i++)
	{
		if (arr[i] == x)
		{
			//将末尾元素赋值给该元素
			arr[i] = arr[current_num - 1];
			arr[current_num-1]=E;
			//将末尾元素删除
			current_num--;
			AdjustDown(i);
			AdjustUp(i);
			return;
		}
	}	
}

int main()
{
	//FILE *in = fopen("E2-1-STANDED.in", "r");
	//FILE *out = fopen("E2-1.out", "w");
	int op;
	int op_num;
	int temp;
	scanf("%d", &op_num);
	//fscanf(in, "%d", &op_num);
	for (int i = 0; i < op_num; i++)
	{
		scanf("%d", &op);
		//fscanf(in, "%d", &op);
		switch (op)
		{
		case 1:
			scanf("%d", &temp);
			//fscanf(in, "%d", &temp);
			Insert(temp);
			break;
		case 2:
			Delete(arr[0]);
			break;
		case 3:
			//fprintf(out, "%d:                        %d\n                         %d %d\n            %d %d %d %d\n%d %d %d %d %d %d %d %d\n   current:%d\n", i+2,arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],current_num);
			//fprintf(out,"%d\n", arr[0]);
			printf("%d\n", arr[0]);
			break;

		case 4:
			scanf("%d", &temp);
			//fscanf(in, "%d", &temp);
			Delete(temp);
			break;

		default:
			//fprintf(out,"ERROR!!!");
			printf("ERROR!!!");
			break;
		}
	}
	
	qsort(arr, current_num, sizeof(int), cmpfunc);

	for (int i = 0; i < current_num; i++)
	{
		printf("%d ", arr[i]);
		//fprintf(out,"%d ", arr[i]);
	}
	return 0;
}
