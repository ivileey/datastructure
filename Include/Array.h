//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����1.3����������С�
//����9.1�����������㷨��

#include <iostream>
using namespace std;
#include <stdlib.h>                                        //�������������rand()


//����1.3����������С�
//��������n�����������Χ��0��size-1�������value����ǰn��Ԫ��
void random(int value[], int n, int size)
{
    for (int i=0; i<n; i++)
        value[i] = rand() % size;                          //����һ��0��size-1֮��������
}

template <class T>
void print(T value[], int n)                               //���value�����ǰn��Ԫ��
{
    for (int i=0; i<n; i++)
        cout<<value[i]<<"  ";                              //T��������<<����������
    cout<<endl;
}


//��3��ϰ���� ϰ1.2
//�ж�����Ԫ���Ƿ��Ѱ����������������򷵻�true�����򷵻�false��T��������>�����
template <class T>
bool isSorted(T value[], int n)
{
    for (int i=0; i<n; i++)
        if (value[i]>value[i+1])
            return false;
    return true;
}


//����9.1�����������㷨��
//��3���9�� ����
//9.2.1 ֱ�Ӳ�������
//ֱ�Ӳ����������򣩣���keys����Ԫ�ذ������������У�nָ������Ԫ�ظ�����T��������<
template <class T>
void insertSort(T keys[], int n) 
{
    for (int i=1; i<n; i++)                                //n-1��ɨ�裬���β���n-1����
    {
        T temp = keys[i];                                  //ÿ�˽�keys[i]���뵽ǰ���������������
        int j;
        for (j=i-1; j>=0 && temp<keys[j]; j--)             //��ǰ��ϴ�Ԫ������ƶ���T��������<
             keys[j+1] = keys[j];
        keys[j+1] = temp;                                  //temp�������λ��
        cout<<"��"<<i<<"��  temp="<<temp<<"\t  ";
        print(keys, n);                                    //�������Ԫ�أ�������Array.h����ʡ��
    }
    cout<<endl;
}

//9.2.2   ϣ������
template <class T>
void shellSort(T keys[], int n)                            //ϣ���������򣩣�T��������<
{
    for (int delta=n/2; delta>0; delta/=2)                 //�����ˣ���������ÿ�˼���
    {
        for (int i=delta; i<n; i++)                        //һ�˷������飬ÿ��ֱ�Ӳ�������
        {
            T temp = keys[i];                              //keys[i]�ǵ�ǰ������Ԫ��
            int j; 
            for (j=i-delta; j>=0 && temp<keys[j]; j-=delta)//����ֱ�Ӳ�������
                keys[j+delta] = keys[j];                   //ÿ��Ԫ�����deltaԶ
            keys[j+delta] = temp;                          //����Ԫ��
        }
        cout<<"delta="<<delta<<"  ";
        print(keys,n);
    }
    cout<<endl;
}

//9.3.1   ð������
//���� prim 
template <class T>
void swap(T keys[], int i, int j)       //����keys[i]��keys[j]����Ԫ�أ�i��j��Χ�ɵ����߿���
{ 
    T temp = keys[j];
    keys[j] = keys[i];
    keys[i] = temp;
}

template <class T>
void bubbleSort(T keys[], int n)                           //ð���������򣩣�T��������>
{
    bool exchange=true;                                    //�Ƿ񽻻��ı��
    for (int i=1; i<n && exchange; i++)                    //�н���ʱ�ٽ�����һ�ˣ����n-1��
    {
        exchange=false;                                    //�ٶ�Ԫ��δ���� 
        for (int j=0; j<n-i; j++)                          //һ�˱Ƚϡ�����
            if (keys[j]>keys[j+1])                         //����Ԫ�رȽϣ��������򽻻�
            {   swap(keys, j, j+1); 
                exchange=true;                             //�н��� 
            }
        cout<<"��"<<i<<"��  ";
        print(keys,n);
    }
    cout<<endl;
}

//9.3.2   ��������
template <class T>
void quickSort(T keys[], int n)                           //�����������򣩣�T��������<=
{
    quickSort(keys, n, 0, n-1);
}

//�Դ���keys����begin��end֮��������н���һ�˿������򣬵ݹ��㷨
template <class T>
void quickSort(T keys[], int n, int begin, int end)
{ 
    if (begin>=0 && begin<n && end>=0 && end<n && begin<end)   //������Ч
    {
        int i=begin, j=end;                                //i��j�±�ֱ�������е�ǰ�����˿�
        T vot=keys[i];                                     //�����е�һ��ֵ��Ϊ��׼ֵ
        while (i!=j)
        {
            while (i<j && vot<=keys[j])                    //�Ӻ���ǰѰ�ҽ�Сֵ�����ƶ����׼ֵ���Ԫ��
                j--;
            if (i<j)
                keys[i++]=keys[j];                         //�����к�˽�СԪ����ǰ�ƶ�

            while (i<j && keys[i]<=vot)                    //��ǰ���Ѱ�ҽϴ�ֵ�����ƶ����׼ֵ���Ԫ��
                i++;
            if (i<j)
                keys[j--]=keys[i];                        //������ǰ�˽ϴ�Ԫ������ƶ�
        }
        keys[i]=vot;                                      //��׼ֵ������λ��
        cout<<begin<<".."<<end<<", vot="<<vot<<",  ";
        print(keys, n);
        quickSort(keys, n, begin, j-1);                   //ǰ�������������򣬵ݹ����
        quickSort(keys, n, i+1, end);                     //��������������򣬵ݹ����
    }
}

//9.4.1 ֱ��ѡ������
//min ����Сֵ����
template <class T>
void selectSort(T keys[], int n)                           //ֱ��ѡ���������򣩣�T��������<
{
    for (int i=0; i<n-1; i++)                              //n-1�ˣ�ÿ���ڴ�keys[i]��ʼ����������Ѱ����СԪ��
    {
        int min=i; 
        for (int j=i+1; j<n; j++)                          //���������в�����Сֵ��min��ס������СԪ���±�
            if (keys[j]<keys[min])
                min = j;
              
        if (min!=i)                                        //��������СԪ�ؽ�����ǰ��
            swap(keys, i, min);
        cout<<"��"<<i+1<<"��  min="<<min<<"��\t";
        print(keys, n);
    }
    cout<<endl;
}

//9.4.2 ������
//��keys��������beginΪ����������������С�ѣ������з�ΧΪbegin��end��T��������>
template <class T>
void sift_minheap(T keys[], int n, int begin, int end)
{
    int parent=begin, child=2*parent+1;                    //parent�������ĸ���child��parent������
    T value = keys[parent];
    while (child<=end)                                     //�ؽ�Сֵ���ӽ������ɸѡ
    {
        if (child<end && keys[child]>keys[child+1])        //child��ס����ֵ��С�ߣ��ĳ�<Ϊ���ѣ�
            child++;
        if (value>keys[child])                             //����ĸ���ֵ�ϴ󣨸ĳ�<Ϊ���ѣ�
        {   keys[parent] = keys[child];                    //����С���ӽ��ֵ����
            parent = child;                                //����һ��
            child = 2*parent+1;
        }
        else break; 
    }
    keys[parent] = value;                                  //��ǰ������ԭ��ֵ�������λ��
    cout<<"sift  "<<begin<<".."<<end<<"  ";
    print(keys, n);
}

template <class T>
void heapSort_down(T keys[], int n)                        //�����򣨽��򣩣���С�ѣ�T��������>
{
    cout<<"������С������"<<endl;
    for (int i=n/2-1; i>=0; i--)                           //������С�ѣ������ֵ��С
        sift_minheap(keys, n, i, n-1);
        
    cout<<"�����򣨽���"<<endl;
    for (int i=n-1; i>0; i--)                              //ÿ�˽���Сֵ���������棬�ٵ�������С��
    {
        swap(keys, 0, i);
        sift_minheap(keys, n, 0, i-1);
    }
    cout<<endl;
}

//9.5 �鲢����
//һ�ι鲢����X�зֱ���begin1��begin2��ʼ���������������й鲢��Y�У�X��Y���鳤��Ϊlen�������г����Ϊn
//T��������<
template <class T>
void merge(T X[], int len, T Y[], int begin1, int begin2, int n)
{
    int i=begin1, j=begin2, k=begin1;
    while (i<begin1+n && j<begin2+n && j<len)              //��X���������������й鲢��Y
        if (X[i] < X[j])                                   //����Сֵ���Ƶ�Y��
            Y[k++]=X[i++];
        else
            Y[k++]=X[j++];

    while (i<begin1+n && i<len)                            //��ǰһ��������ʣ��Ԫ�ظ��Ƶ�Y�У������г��ȿ��ܲ���n
        Y[k++]=X[i++];
    while (j<begin2+n && j<len)                            //����һ��������ʣ��Ԫ�ظ��Ƶ�Y��
        Y[k++]=X[j++];
}

template <class T>
void mergepass(T X[], int len, T Y[], int n)               //һ�˹鲢�������г���Ϊn
{
    cout<<"�����г���n="<<n<<"  ";
    for (int i=0;  i<len;  i+=2*n)                         //X���������������й鲢��Y��
        merge(X, len, Y, i, i+n, n);                       //��X����������������һ�ι鲢��Y������
    print(Y, len);
}

template <class T>
void mergeSort(T X[], int len)                             //�鲢����X���鳤��Ϊlen��T��������<
{
    T *Y = new T[len];                                     //Y���鳤��ͬX����
    int n=1;                                               //���������г���
    while (n<len)
    {
        mergepass(X, len, Y, n);                           //һ�˹鲢����X�����и������й鲢��Y��
        n*=2;                                              //�����г��ȼӱ�
        if (n<len)
        {
            mergepass(Y, len, X, n);                       //��Y�����и��������ٹ鲢��X��
            n*=2;
        }
    }
    cout<<endl;
}
    