//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.2.3 ����˳������򣩡�

#include "SeqList.h"                                       //˳�����
#include "Array.h"                                         //�������򣬵�9��

//����˳����ࣨ���򣩣����м̳�˳����࣬T��������==��!=��>��>=��ϵ�����
template <class T>
class SortedSeqList : public SeqList<T>
{
  public:
    SortedSeqList(){}                                      //���������˳���Ĭ��ִ��SeqList<T>()
    SortedSeqList(T values[], int n);                      //��������˳�����values���������ṩԪ��
//    SortedSeqList(T values[], int n):SeqList<T>(values, n){}   //��������˳�����values���������ṩԪ�أ�ֻ��8.1��
    SortedSeqList(SortedSeqList<T> &list):SeqList<T>(list){}//Ĭ�Ͽ������캯�����������͸�ֵ���ݣ���ʡ��
    SortedSeqList(SeqList<T> &list);                       //���ؿ������캯������˳���������˳���
//    SortedSeqList<T>& operator=(SortedSeqList<T> &list);   //Ĭ�ϸ�ֵ�����̳л����=����ʡ��
//    ~SortedSeqList(){}                                     //���ܼ̳л��������������Զ�ִ��~SeqList<T>()����ʡ��

    void insert(T x);                                      //���룬����Ԫ��x��Сȷ������λ�ã�����ʱ����
    int search(T key, int start=0);                         //��start��ʼ���ҹؼ���ΪkeyԪ�أ�����ʱ����
    void removeFirst(T key);                               //ɾ���״γ��ֵĹؼ���ΪkeyԪ�أ�����ʱ����
//    void set(int i, T x);                                  //��֧�ָò������׳��쳣������ʱ����
    void insertUnrepeatable(T x);                          //���벻�ظ�Ԫ��
    
    //��˼����2-2��
    SortedSeqList<T> operator+(SeqList<T> &list);
//    SortedSeqList<T> operator+(SortedSeqList<T> &list);

    //ʵ��2

    //8.2  ��������˳���Ķ��ַ�����
    int binarySearch(T key);
    int binarySearch(T key, int begin, int end);

};

//3.  ���಻�ܼ̳л���Ĺ��캯��
//��������˳�������ִ�л����SeqList<T>(int)���캯����ֱ�Ӳ��������㷨
template <class T>
SortedSeqList<T>::SortedSeqList(T values[], int n): SeqList<T>(n*2)
{
    for (int i=0; i<n; i++)
        this->insert(values[i]);                            //���ñ����Ա�������������
}

//7.  ��̬ԭ�����า�ǻ���ͬ����Ա����
//��start��ʼ˳������״γ��ֵĹؼ���ΪkeyԪ�أ�����Ԫ�����i��0��i<n���������Ҳ��ɹ�����-1��
//start��0��Ĭ��0�����ǻ����ͬ����Ա�����������б���ͬ������ֵ��ͬ��
//T��������==��ϵ����������ڲ���ʱʶ�����T��������>=��Լ�������������
template <class T>
int SortedSeqList<T>::search(T key, int start)
{
    for (int i=0; i<this->n && key>=this->element[i]; i++)  //T��������>=
        if (this->element[i]==key)                          //T��������==
            return i;
    return -1;
}

//���룬����xԪ�ش�С˳�����xȷ������λ�á������ڵ�ֵ���֮ǰ��T��������>�����
//�����˻����insert(int i, T x)��insert(T x)���������۲����б��Ƿ���ͬ������ֵ��ͬ
template <class T>
void SortedSeqList<T>::insert(T x)
{
    int i=0;
    while (i<this->n && x > this->element[i])              //T��������>
        i++;
    SeqList<T>::insert(i, x);                              //����x��Ϊ��i��Ԫ�أ����ñ����ǵĻ����Ա����
}

//ɾ���״γ��ֵĹؼ���ΪkeyԪ�ء����ǻ����removeFirst(T key)�����������б���ͬ������ֵ��ͬ��
//û�и��ǻ����remove(int i)������
//�㷨Ҫ�ȵ���search(key)����������ȷ��ɾ��Ԫ��λ�ã���ˣ�Ҫ��T��������==��>=��
template <class T>
void SortedSeqList<T>::removeFirst(T key)
{
    remove(this->search(key));                              //���ú���remove(i)
//    this->~SeqList(); //�����'SortedSeqList<T>' : ��û�� ����������������Ϊ '~SeqList'��֤�����������̳У���
//    SortedSeqList<T>::~SortedSeqList();          //û������,Ҳ�ܵ��ã�֤����Ĭ������
}

//8.  ���಻��ɾ�������Ա
/*
template <class T>
void SortedSeqList<T>::set(int i, T x)                     //��֧�ָò������׳��쳣������ʱ����
{
    throw logic_error("��֧��set(int i, T x)����");        //�׳�C++ STL�߼������쳣
}*/

//9.  ���͵Ķ�̬����������ǻ�����󣬸�ֵ����
//��ȷ
template <class T>
SortedSeqList<T>::SortedSeqList(SeqList<T> &list)          //���ؿ������캯������˳���������˳���
{                                                          //�˴��Զ�ִ��SeqList<T>()���๹�캯��
    for (int i=0; i<list.count(); i++) 
        this->insert(list[i]);                             //����˳������Ԫ��
}
//�����������Ķ��������⣺
//SortedSeqList<T>::SortedSeqList(SortedSeqList<T> &list)  //������캯������˳���������˳���

//�̲ĵ�49ҳ��˼����2-2���𰸣���ϰ2.2��
//������������˳���*this��list�鲢��Ķ��󣻲��ı�*this��list����
//����ֵ����Ϊ���󣬲�������ʱִ�п������캯��
//���ǣ������б���ͬ������ֵ���Ͳ�ͬ
//�㷨ͬSeqList�ֻ࣬��temp���Ͳ�ͬ
template <class T>
SortedSeqList<T> SortedSeqList<T>::operator+(SeqList<T> &list)
{
    SortedSeqList<T> temp(*this);
    temp += list;                                          //ִ��SortedSeqList�̳е�+=������˳������
    return temp;
}


//9.5   �鲢����
//�鲢��������˳�������+�����������*this+list���󣬲��ı�*this��list����
//һ�˹鲢�����㷨��������+=������
/*template <class T>
SortedSeqList<T> SortedSeqList<T>::operator+(SortedSeqList<T> &list)
{
    SortedSeqList<T> temp(*this);                                //ִ�п������캯��������*this��ǰ�����temp
    temp += list;
    return temp;                                           //����temp�ֲ������洢�Ķ�����ִ�п������캯����������temp
}*/
//���������ԣ���


//8.2  ��������˳���Ķ��ַ�����
//������˳��������У����ַ����ҹؼ���ΪkeyԪ�أ����ҵ������±꣬���򷵻�-1
//T��������==��<�����
template <class T>
int SortedSeqList<T>::binarySearch(T key)
{
    return binarySearch(key, 0, this->count()-1);
}
//������˳������򣩴�begin��end��Χ�ڣ����ַ����ҹؼ���ΪkeyԪ��
template <class T>
int SortedSeqList<T>::binarySearch(T key, int begin, int end)
{
    while (begin<=end)                                     //�߽���Ч
    {
        int mid = (begin+end)/2;                           //�м�λ�ã���ǰ�Ƚ�Ԫ��λ��
        cout<<this->element[mid]<<"? ";                    //��ʾ�Ƚ��м�������ʡ��
        if (element[mid]==key)                             //�Ƚ϶�����ȣ�T��������==
            return mid;                                    //���ҳɹ�������Ԫ���±�
        if (key < element[mid])                            //�Ƚ϶����С��T��������<
            end = mid-1;                                   //keyֵС�����ҷ�Χ��С��ǰ���
        else begin = mid+1;                                //���򣬲��ҷ�Χ��С������
    }
    return -1;                                             //���Ҳ��ɹ�
}  

//��3���9�� ����
//����9.2������˳�����������㷨��
//��1���������³�Ա���������﷨���� : Ӧ���롰{�������ǡ�;��
//    SortedSeqList(SeqList<T> &list):SeqList<T>(list);        //���ؿ������캯������˳���������˳�����9��

//��2����ȷ
//���ؿ������캯������˳���������˳����������û��࿽�����캯�����ٵ���һ�������㷨
/*template <class T>
SortedSeqList<T>::SortedSeqList(SeqList<T> &list):SeqList<T>(list)
{
    shellSort(this->element, this->n);                 //ϣ����������
}
*/
