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
	//������ӵĽ����뵽��β
	arr[current_num]=e;
	current_num++;
	//�õ��Լ��͸��ڵ������
	int selfIndex = current_num - 1;
	int fatherIndex = (selfIndex - 1) / 2;
	//���²����Ԫ�ط��뵽�����λ��
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
	//�Ѷ�Ԫ��
	int topEle = arr[0];
	int fatherIndex = 0;
	int childIndex = fatherIndex * 2 + 1;
	while (childIndex < current_num)
	{
		//����Һ���Ҳ���ڣ�ָ�����Һ����нϴ�Ľ��
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
	//ɾ���Ѷ�Ԫ��
	if (current_num!=0)
	{
		//��ĩβԪ�ظ�ֵ���Ѷ�
		arr[0] = arr[current_num - 1];
		//��ĩβԪ��ɾ��
		current_num--;
	}
	//���ϵ��¶Զѽ��е���
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
