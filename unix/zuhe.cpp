//��������� ��n������1....n����k���������....
//�磺combination(5,3)
//Ҫ�������543��542��541��532��531��521��432��431��421��321��

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int pop(int *);
int push(int );
void combination(int ,int );

int *stack = NULL;
int top=-1;
int value,number;

int main()
{
    printf("Input two numbers:\n");
    while( (2!=scanf("%d%*c%d",&value,&number))) {
        fflush(stdin);
        printf("Input error! Again:\n");
    }
    stack = (int *)malloc(number * sizeof(int));
    if(!stack){
        printf("malloc for stack erro!!!\n");
        return EXIT_FAILURE;
    }

    combination(value,number);
    printf("\n");
}

void combination(int value,int number)
{
    int temp=value;
    push(temp);
    while(1) {
        if(1==temp) {
            if(pop(&temp)&& *(stack + 0)==number) //��ջ��Ԫ�ص���&&Ϊ����ȡ����Сֵ��ѭ���˳�
                break;
        } else if( push(--temp)) {
            int i = 0;
            for(i = 0; i < number; ++i)
                printf("%d",*(stack + i));
            printf(" ");
            pop(&temp);
        }
    }
}

int push(int i)
{
    *(stack + (++top))=i;
    if(top < number - 1)
        return 0;
    else
        return 1;
}

int pop(int *i)
{
    *i=*(stack + (top--));
    if(top >= 0)
        return 0;
    else
        return 1;
}
