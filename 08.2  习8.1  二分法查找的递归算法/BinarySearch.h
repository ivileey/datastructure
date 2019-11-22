////�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//8.2   ��������˳���Ķ��ַ�����
//��ϰ8.1��  ���ַ����ҵĵݹ��㷨��
//������洢

//�ڰ��������е�value�����ǰn��Ԫ���У����ַ����ҹؼ���ΪkeyԪ�أ����ҵ������±꣬���򷵻�-1
template <class T>
int binarySearch(T value[], int n, T key)
{
    return binarySearch(value, 0, n-1, key);
}  

//���ַ����ҵݹ��㷨���ڴ�begin��end��Χ�ڡ����������е�value�����У����ַ����ҹؼ���Ϊkey��Ԫ��
template <class T>
int binarySearch(T value[], int begin, int end, T key)
{
    if (begin<=end)                                         //�߽���Ч
    {
        int mid = (begin+end)/2;                            //�м�λ�ã���ǰ�Ƚ�Ԫ��λ��
        cout<<value[mid]<<"? ";
        if (value[mid]==key)                                //�Ƚ϶�����ȣ�T��������==
            return mid;                                     //���ҳɹ�������Ԫ���±�
        if (key < value[mid])                               //keyֵС�����ҷ�Χ��С��ǰ���
            return binarySearch(value, begin, mid-1, key);  //�ݹ����
        return binarySearch(value, mid+1, end, key);        //���򣬲��ҷ�Χ��С�����Σ��ݹ����
    }
    return -1;
}

/*�ǵݹ��㷨��ͬ����˳���
//�ڴ�begin��end��Χ�ڡ����������е�value�����У����ַ����ҹؼ���Ϊkey��Ԫ��
template <class T>
int binarySearch(T value[], int begin, int end, T key)
{
    while (begin<=end)                                     //�߽���Ч
    {
        int mid = (begin+end)/2;                           //�м�λ�ã���ǰ�Ƚ�Ԫ��λ��
        cout<<value[mid]<<"? ";                            //��ʾ�Ƚ��м�������ʡ��
        if (value[mid]==key)                               //�Ƚ϶�����ȣ�T��������==
            return mid;                                    //���ҳɹ�������Ԫ���±�
        if (key < value[mid])                              //�Ƚ϶����С��T��������<
            end = mid-1;                                   //keyֵС�����ҷ�Χ��С��ǰ���
        else begin = mid+1;                                //���򣬲��ҷ�Χ��С������
    }
    return -1;                                             //���Ҳ��ɹ�
}  */


//��2����8.1����8.2��
#include <string.h>
//�ַ�������Ķ��ַ����ң�value����Ԫ���Ѱ��������У���value�����ж��ַ�����keyԪ�أ�begin��end��ʾ���ҷ�Χ���½���Ͻ�
//�����ҳɹ�����Ԫ���±꣬���򷵻�-1
int binarySearch(char* value[], char* str, int begin, int end)
{
    while (begin<=end)
    {
        int mid = (begin+end)/2;
        cout<<value[mid]<<"? ";
        if (strcmp(value[mid], str)==0)            //�����ַ������
            return mid;
        if (strcmp(str, value[mid])==-1)           //str�ַ���ֵС
            end = mid-1;
        else
            begin = mid+1; 
    }
    return -1;
}  
