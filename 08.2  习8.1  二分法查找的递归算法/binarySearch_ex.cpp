//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//8.2   ��������˳���Ķ��ַ�����
//��ϰ8.1��  ���ַ����ҵĵݹ��㷨��

#include "Array.h"
#include "BinarySearch.h"

int main()
{
    const int N=10, SIZE=100;
    int values[N]={0};
    random(values, N, SIZE);                               //����N��0��size-1֮����������������Array.h��
    insertSort(values, N);                                 //ֱ�Ӳ����������򣩣��㷨��9.1�ڡ�
    cout<<"������������У�";
    print(values, N);                                      //������Array.h��

    int keys[]={values[N/2],10,99};
    for (int i=0; i<3; i++)
        cout<<"���ַ����� "<<keys[i]<<"��"<<((binarySearch(values, N, keys[i])==-1)?"��":"")<<"�ɹ�\n";

    system("pause");
    return 0;
}

/* 
�������н�����£�
������������У�0  24  34  41  58  62  64  67  69  78  
58? 67? 62? ���ַ����� 62���ɹ�
58? 24? 0? ���ַ����� 10�����ɹ�
58? 67? 69? 78? ���ַ����� 99�����ɹ�

*/

