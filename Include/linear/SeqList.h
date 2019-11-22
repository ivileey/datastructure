//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.2 ˳�����

#include <iostream>
using namespace std;
#include <iomanip>                                         //����
#include <exception>                                       //����C++ STL����׼��⣩�쳣��

template <class T>
class SeqList                                              //˳����࣬Tָ��Ԫ�����ͣ�T��������==��!=��ϵ�����
{
  protected:                                               //������Ա������ɼ�
    T *element;                                            //��̬����洢˳��������Ԫ��
    int length;                                            //˳������������
    int n;                                                 //˳���Ԫ�ظ��������ȣ�

  private:                                                 //˽�г�Ա��ֻ�ڱ���ɼ�
    void init(T values[], int n);                          //��ʼ��˳�����values�����ṩԪ�أ�nָ��Ԫ�ظ���

  public:                                                  //���г�Ա��������ɼ�
    SeqList(int length=32);                                //����ձ�lengthָ����Ĭ�ϣ�����
    SeqList(int length, T x);                              //����˳���length��Ԫ��ֵΪx
    SeqList(T values[], int n);                            //����˳�����values�����ṩԪ�أ�nָ��Ԫ�ظ���
    ~SeqList();                                            //�������� 

    bool empty();                                          //�ж�˳����Ƿ�Ϊ��
    int count();                                           //����˳���Ԫ�ظ���
    T& operator[](int i);                                  //�����±������
    friend ostream& operator<<<>(ostream&, SeqList<T>&);   //���˳�������Ԫ�أ���������������������<>��<>ʡ��T����ʽģ�����
    void printPrevious();                                  //����������Ӻ���ǰ

    void insert(int i, T x);                               //����x��Ϊ��i��Ԫ��
    virtual void insert(T x);                              //��˳���������x���麯��
    T remove(int i);                                       //ɾ����i��0��i<n����Ԫ�أ����ر�ɾ��Ԫ��
    void removeAll();                                      //ɾ��˳�������Ԫ��
    virtual int search(T key, int start=0);                //��start��ʼ˳������״γ��ֵĹؼ���ΪkeyԪ�أ�����Ԫ����ţ��麯��
    virtual void removeFirst(T key);                       //ɾ���״γ��ֵĹؼ���ΪkeyԪ�أ��麯��������First��������remove(int)������ͬ

    SeqList(SeqList<T> &list);                             //�������캯��
    SeqList<T>& operator=(SeqList<T> &list);               //����=��ֵ����������
    bool operator==(SeqList<T> &list);                     //�Ƚ�����˳�������ֵ�Ƿ����
    bool operator!=(SeqList<T> &list);
    void operator+=(SeqList<T> &list);                     //��*this��ǰ˳���֮��ϲ�����list
//    SeqList<T>& operator+=(SeqList<T> &list);            //���߾��ɣ������ͬ
    SeqList<T> operator+(SeqList<T> &list);                //����*this��list�ϲ����ӵĶ��󣻲��������麯��
    //���ϵ�2��ADT

    //ʵ��2 ˳����ң��麯��
    bool contains(T key);                                  //�ж��Ƿ�����ؼ���ΪkeyԪ��
    void removeAll(T key);                                 //ɾ�����йؼ���ΪkeyԪ��
    void replaceFirst(T key, T x);                         //���״γ��ֵĹؼ���ΪkeyԪ���滻Ϊx
    void replaceAll(T key, T x);                           //�����йؼ���ΪkeyԪ���滻Ϊx
    virtual int indexLast(T key, int start);               //��start��ʼ˳����������ֵĹؼ���ΪkeyԪ�أ�����Ԫ����ţ��麯��
};

//1.  ˳���Ļ���������Ч�ʷ���
//��1�� ˳���Ĺ��������
template <class T>
SeqList<T>::SeqList(int length)                            //�����˳���lengthָ������������Ĭ�ϣ�
{
    this->element = new T[length];                         //��length<0����C++����ֹ����
    this->length = length;
    this->n = 0;                                           //Ԫ�ظ���Ϊ0
}

template <class T>
SeqList<T>::SeqList(int length, T x)                       //����˳���length��Ԫ��ֵΪx�����캯�����ء����鼯����
{
    this->element = new T[length];
    this->length = this->n = length;
    for (int i=0; i<this->n; i++)
        this->element[i] = x;                              //ִ��T��=��ֵ��T��Ĭ��=��ֵ����
}

template <class T>
void SeqList<T>::init(T values[], int n)                   //��ʼ��˳�����values�����ṩԪ�أ�nָ��Ԫ�ظ���
{
    this->length = n*2;
    this->element = new T[this->length];
    this->n = n;
    for (int i=0; i<n; i++)
        this->element[i] = values[i];                      //ִ��T��=��ֵ��T��Ĭ��=��ֵ����
}

template <class T>
SeqList<T>::SeqList(T values[], int n)                     //����˳�����values�����ṩԪ�أ�nָ��Ԫ�ظ��������캯������
{
    this->init(values, n);
}

template <class T>
SeqList<T>::~SeqList()                                     //��������
{
//    cout<<"����~SeqList"<<*this;
    delete []this->element;                                //�ͷŶ�̬����elementռ�õĴ洢�ռ�
}

//��2�� ˳�����пա��󳤶Ⱥ������������
template <class T>
bool SeqList<T>::empty()                                   //�ж�˳����Ƿ�Ϊ�գ����շ���true��O(1)
{
    return this->n==0;
}
template <class T>
int SeqList<T>::count()                                    //����˳���Ԫ�ظ��������ȣ���O(1)
{
    return this->n;
}

//�����±�����������õ�i��0��i<n����Ԫ�ء���i<0��i��n�����׳��쳣
template <class T>
T& SeqList<T>::operator[](int i)
{
    if (i>=0 && i<this->n)
        return this->element[i];                           //����Ԫ������
    throw out_of_range("����iָ��Ԫ����ų�����Χ");       //�׳�C++ STL��ΧԽ���쳣
}

//��3�� ˳���ı������
//���˳�������Ԫ�أ�����<<��������������ʽΪ��(,)�����ձ���()
//Visual C++ 2008 ����<>��<>ʡ��T����ʽģ�������T��������<<����������
template <class T>
ostream& operator<<<>(ostream& out, SeqList<T> &list)
{
    out<<"(";
    if (list.n>0)
        out<<list.element[0];
 //   out.width(5);                                        //�п�������
    for (int i=1; i<list.n; i++)
        out<<", "<<list.element[i];              //ִ��T��<<��T��������<<
//        out<<", "<<setw(5)<<list.element[i];              //ִ��T��<<��T��������<<���п�ǰ����
    out<<")"<<endl;
    return out;
}

template <class T>
void SeqList<T>::printPrevious()                           //����������Ӻ���ǰ��Dijkstra��Floyd�㷨��
{
    cout<<"(";
    if (this->n > 0)
        cout<<this->element[this->n-1];
    for (int i=this->n-2; i>=0; i--)
        cout<<", "<<this->element[i]; 
    cout<<")";
}

//��4�� ˳���Ĳ������
//����x��Ϊ��i��Ԫ�ء���iָ�����Խ�磬��ȡ�ݴ��ʩ����������ǰ�����
template <class T>
void SeqList<T>::insert(int i, T x)
{
    if (i<0)                                               //����λ��i�ݴ�
        i=0;                                               //��������ǰ
    if (i>this->n)
        i=this->n;                                         //���������

    T *temp = this->element;  
    if (this->n==this->length)                             //����������������˳������������
    {
        this->length *=2;
        this->element = new T[this->length];               //��������һ���������������
        for (int j=0; j<i; j++)                            //���Ƶ�ǰ����ǰi-1��Ԫ��
            this->element[j] = temp[j];                    //ִ��T��=��ֵ����
    }
    for (int j=this->n-1; j>=i; j--)                       //��i��ʼ����β��Ԫ������ƶ��������ǴӺ���ǰ
        this->element[j+1] = temp[j];
    if (temp!=this->element)
        delete[] temp;                                     //�ͷ�ԭ����ռ�
    this->element[i] = x;
    this->n++;
}

template <class T>
void SeqList<T>::insert(T x)                               //��˳���������xԪ�أ���Ա��������
{
    this->insert(this->n, x); 
}

//��5�� ˳����ɾ������
//ɾ����i��0��i<n����Ԫ�أ����ر�ɾ��Ԫ�أ���i<0��i��n�����׳��쳣
template <class T>
T SeqList<T>::remove(int i)
{
    if (this->n>0 && i>=0 && i<n)
    {
        T old = this->element[i];                          //old�д洢��ɾ��Ԫ��
        for (int j=i; j<n-1; j++)                          //Ԫ��ǰ�ƣ�ƽ���ƶ�n/2
            this->element[j] = element[j+1];
        this->n--;
        return old;                                        //����old�ֲ������洢�Ķ�����ִ�п������캯����������old
    }
    throw out_of_range("����iָ��Ԫ����ų�����Χ");       //�׳�C++ STL��ΧԽ���쳣
}

template <class T>
void SeqList<T>::removeAll()                               //ɾ��˳�������Ԫ�أ�δ�ͷ�����ռ�
{
    this->n=0;
}

//��6�� ˳���Ĳ��Ҳ���
//��start��ʼ˳������״γ��ֵĹؼ���ΪkeyԪ�أ�����Ԫ�����i��0��i<n���������Ҳ��ɹ�����-1
//start��0��Ĭ��0��T��������==�����
template <class T>
int SeqList<T>::search(T key, int start)
{
    for (int i=start; i<this->n; i++)
        if (this->element[i]==key)                         //T��������==
            return i;
    return -1;
}

template <class T>
void SeqList<T>::removeFirst(T key)                        //ɾ���״γ��ֵĹؼ���ΪkeyԪ�أ��麯��������First��������remove(int)������ͬ
{
    this->remove(this->search(key));                        //���ҵ���ɾ��������remove(i)
}

//����2.1��ʹ��˳������Լɪ�����⡣
//����2.2��������Ϣ����ͳ������ҡ�

//2. ˳����ǳ���������
//��1��˳����ǳ����
/*
template <class T>
SeqList<T>::SeqList(SeqList<T> &list)                      //Ĭ�Ͽ������캯����ǳ������
{
    this->length = list.length;
    this->n = list.n;
    this->element = list.element;                          //ָ�븳ֵ��ֻ�����������׵�ַ������ʱ����
}
template <class T>
SeqList<T>& SeqList<T>::operator=(SeqList<T> &list)        //��ֵ��ǳ������
{
    this->length = list.length;
    this->n = list.n;
    this->element = list.element;                          //ָ�븳ֵ��ֻ�����������׵�ַ������ʱ����
    return *this;
}*/

//��4�� ˳�������
template <class T>
SeqList<T>::SeqList(SeqList<T> &list)                      //������캯��������list
{
    this->init(list.element, list.n);                      //��ʼ����ǰ������list�����ṩԪ��
}

template <class T>
SeqList<T>& SeqList<T>::operator=(SeqList<T> &list)        //����=��ֵ����������ض������ã����
{
    if (this->length > list.n)
    {
        this->n = list.n;
        for (int i=0; i<this->n; i++)                      //����list��������Ԫ�أ�O(n)
            this->element[i] = list.element[i];            //ִ��T��=��ֵ���㣬TĬ��=��ֵ����
        return *this;                                      //���ص�ǰ��������
    }
    //��ǰ���������������Сʱ��������������
    this->~SeqList();                                      //���������������ͷ�element����ռ�
    this->init(list.element, list.n);                      //��ʼ����ǰ������list�������ṩԪ��
    return *this;                                          //���ص�ǰ��������
}

//3.  ˳������������
template <class T>
bool SeqList<T>::operator==(SeqList<T> &list)              //�Ƚ�����˳����Ƿ���ȣ�T��������!=�������O(n)
{
    if (this==&list || this->element==list.element)        //ָ��Ƚϣ���������������ͬһ��ʵ������˳���ǳ������������������ͬһ������ʱ
        return true;
    if (this->n!=list.n)                                   //�Ƚ����߳����Ƿ���ȣ����Ƚ���������
        return false;
    for (int i=0; i<n; i++)                                //�Ƚ�����˳��������Ԫ���Ƿ����
        if (this->element[i] != list.element[i])           //T��������!=�����
            return false;
    return true;
}

template <class T>
bool SeqList<T>::operator!=(SeqList<T> &list)              //�Ƚ�����˳����Ƿ����
{
    return !(*this==list);
}

//2.2.3   ����˳���
//10.  �麯�����ͺ�����

//��*this��ǰ˳���֮��ϲ�����list���ı�*this���󣬲��ı�list����
//��������Ϊ�������ã���������ʱ��ִ�п������캯����
template <class T>
void SeqList<T>::operator+=(SeqList<T> &list)
{ 
    for (int i=0; i<list.n; i++)
        this->insert(list[i]);                             //ִ���ĸ����insert(x)������
} 
//���У���insert(x)����Ϊ�麯��������ʱ���ǣ�����ִ��β���룻SortedSeqList����ִ��������롣
//��ˣ�����������Ҫ�����า�ǣ�����Ҫ����Ϊ�麯����

//�����������У����ͬ�ϡ�
/*template <class T>
SeqList<T>& SeqList<T>::operator+=(SeqList<T> &list)
{ 
    for (int i=0; i<list.n; i++)
        this->insert(list[i]);                             //ִ���ĸ����insert(x)������
    return *this;
} */

//�̲ĵ�49ҳ��˼����2-2��
//����*this��list�ϲ����ӵĶ��󣻲��ı�*this��list����
//����ֵ����Ϊ���󣬲�������ʱִ�п������캯��
template <class T>
SeqList<T> SeqList<T>::operator+(SeqList<T> &list)
{
    SeqList<T> temp(*this);                                //ִ�п������캯��������*this��ǰ�����temp
    temp += list;
    return temp;                                           //����temp�ֲ������洢�Ķ�����ִ�п������캯����������temp
}
//�������⣬��temp�ǻ��࣬+=��ִ�л����insert(x)������ʱȷ������˻�����У����಻�С�
//�ҷ���ֵ���ͣ����ܷ��ظ�ʵ�ʲ���Ϊ����ĵ��á�����Ϊʲô����
//�����������������ʱ����Ϊ�鲢�����ߣ���Ҫ���÷�����ƣ�����*this�ǻ�������࣬�ֱ𿽱����������ʵ����
//�����޸�Ҳ���С�
/*
template <class T>
SeqList<T> SeqList<T>::operator+(SeqList<T> &list)
{ 
    SeqList<T> *p = new SeqList<T>(*this);                 //��Ȼִ��SeqList�������캯�����޷��Զ�����
    *p += list;
    return *p;
}*/



//ʵ��2��˳�����ڲ��ҵ�ɾ�����滻����
template <class T>
bool SeqList<T>::contains(T key)                           //�ж��Ƿ�����ؼ���ΪkeyԪ��
{
    return search(key)>=0;                                 //�Բ��ҽ���ж��Ƿ����ָ��Ԫ��
} 

template <class T>
void SeqList<T>::removeAll(T key)                          //ɾ�����йؼ���ΪkeyԪ�ء��㷨ÿԪ���ƶ����
{
    int i=0;
    while ((i=this->search(key,i))!=-1)                     //��i��ʼ˳����ҹؼ���ΪkeyԪ��
        this->remove(i);                                   //���ҵ���ɾ��������remove(i)
}

template <class T>
void SeqList<T>::replaceFirst(T key, T x)                  //���״γ��ֵĹؼ���ΪkeyԪ���滻Ϊx
{
    int i=this->search(key,0);
    if (i!=-1) 
        this->element[i] = x;                              //���ҵ����滻
}

template <class T>
void SeqList<T>::replaceAll(T key, T x)                    //�����йؼ���ΪkeyԪ���滻Ϊx
{
    int i=-1;
    while ((i=this->search(key,i+1))!=-1)                   //��i+1��ʼ�ٴβ��ҹؼ���ΪkeyԪ��
        this->element[i] = x;                               //���ҵ����滻
}

//��start��ʼ˳����ҹؼ���ΪkeyԪ�أ�����������Ԫ����ţ���δ�ҵ�����-1���麯��
template <class T>
int SeqList<T>::indexLast(T key, int start)
{
    for (int i=this->n-1; i>=start; i--)
        if (this->element[i]==key)
            return i;
    return -1;
}

