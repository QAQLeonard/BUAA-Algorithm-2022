#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[100005];
int current_num;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );
}

void Insert(int e)
{
	//将新添加的结点插入到队尾
	arr[current_num]=e;
	current_num++;
	//得到自己和父节点的索引
	int selfIndex = current_num - 1;
	int fatherIndex = (selfIndex - 1) / 2;
	//将新插入的元素放入到合理的位置
	while (fatherIndex >= 0 && selfIndex != 0)
	{
		if (arr[fatherIndex] >= e)
			break;
		arr[selfIndex] = arr[fatherIndex];
		selfIndex = fatherIndex;
		fatherIndex = (fatherIndex - 1) / 2;
	}
	arr[selfIndex] = e;
}

void Adjust()
{
	if (current_num==0)
		return;
	//堆顶元素
	int topEle = arr[0];
	int fatherIndex = 0;
	int childIndex = fatherIndex * 2 + 1;
	while (childIndex < current_num)
	{
		//如果右孩子也存在，指向左右孩子中较大的结点
		if (childIndex + 1 < current_num && arr[childIndex] < arr[childIndex + 1])
			childIndex++;
		if (arr[childIndex] <= topEle)
			break;
		arr[fatherIndex] = arr[childIndex];
		fatherIndex = childIndex;
		childIndex = childIndex * 2 + 1;
	}
	arr[fatherIndex] = topEle;
}

void Delete()
{
	//删除堆顶元素
	if (current_num!=0)
	{
		//将末尾元素赋值给堆顶
		arr[0] = arr[current_num - 1];
		//将末尾元素删除
		current_num--;
	}
	//从上到下对堆进行调整
	Adjust();

}


int main()
{
	int op;
	int op_num;
	int temp;
	scanf("%d",&op_num);
	for(int i=0; i<op_num; i++)
	{
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				scanf("%d",&temp);
				Insert(temp);
				break;
			case 2:
				Delete();
				break;
			case 3:
				printf("%d\n",arr[0]);
				break;
			default:
				printf("ERROR!!!");
				break;
		}
	}
	qsort(arr,current_num,sizeof(int),cmpfunc);
	
	for(int i=0; i<current_num; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
