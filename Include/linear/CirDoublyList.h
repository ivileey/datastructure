//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.3.3   ˫����
//3. ѭ��˫������

#include <iostream>
using namespace std;
#include "DoubleNode.h"                                    //˫��������

template <class T>
class CirDoublyList                                        //��ͷ����ѭ��˫������
{
  public:
    DoubleNode<T> *head;                                   //ͷָ��

    CirDoublyList();                                       //�����ѭ��˫����
    CirDoublyList(T values[], int n);                      //����ѭ��˫������values�����ṩԪ��
    ~CirDoublyList();                                      //��������

    bool empty();                                          //�ж�ѭ��˫�����Ƿ�Ϊ��
    int count();                                           //����ѭ��˫������ 
    T& get(int i);                                         //���ص�i����0����Ԫ��
    virtual void set(int i, T x);                          //���õ�i����0����Ԫ��Ϊx���麯��
    friend ostream& operator<<<>(ostream& out, CirDoublyList<T>&); //���ѭ��˫����
    void printPrevious();                                  //���ѭ��˫�����Ӻ���ǰ������ǰ������ѭ��˫�������ӵĲ���
    DoubleNode<T>* insert(int i, T x);                     //����x��Ϊ��i����0�������
    virtual DoubleNode<T>* insert(T x);                    //��������xԪ�ؽ�㣻�麯��
    T remove(int i);                                       //ɾ����i����0�������
    void removeAll();                                      //���ѭ��˫����
    DoubleNode<T>* search(T key);                          //˳������״γ��ֵĹؼ���ΪkeyԪ�أ����ؽ���ַ����δ�ҵ�������NULL��T��������==�������Լ���Ƚ�����Ԫ����ȣ�==���Ĺ���
    virtual void operator+=(CirDoublyList<T> &list);       //��list�����ڵ�ǰѭ��˫����֮���麯��

    //ϰ���� ϰ2.6
    DoubleNode<T>* first();                                //���ص�һ������ַ
    DoubleNode<T>* next(DoubleNode<T> *p);                 //����p���ĺ�̽���ַ
    DoubleNode<T>* previous(DoubleNode<T> *p);             //����p����ǰ������ַ
    DoubleNode<T>* last();                                 //�������һ������ַ

    //��8�²��� 8.2.1 ˳����� ϰ�⣬T��������==��!=�����
/*
    void insertUnrepeatable(T x);               	//β���벻�ظ�Ԫ��
    virtual void removeFirst(T key);               	//ɾ���״γ��ֵ�Ԫ��ֵΪkey�Ľ��
DoubleNode<T>* search(T x);                             //˳������״γ��ֵ�Ԫ��ֵΪx���
    bool contain(T x);                                     //�ж��Ƿ����Ԫ��x
    void replaceFirst(T x, T y);                           //��Ԫ��x�滻ΪԪ��y
    void replaceAll(T x, T y);                             //������ֵΪxԪ���滻ΪԪ��y
    void removeFirst(T x);                                 //ɾ��Ԫ��x�״γ��ֽ��
    void removeLast(T x);                                  //ɾ�������ֵ�ֵΪx�Ľ��
    void removeAll(T x);                                   //ɾ������Ԫ��ֵΪx�Ľ��

    //ʵ����2
    bool operator==(CirDoublyList<T> &list);        //�Ƚ�����ѭ��˫�����Ƿ����
    CirDoublyList(CirDoublyList<T> &list);   //���������ѭ��˫����list
    CirDoublyList<T>& operator=(CirDoublyList<T> &list);   //��ֵ�����
    CirDoublyList(HSLinkedList<T> &list);           //�ɵ�������ѭ��˫�������
    CirDoublyList(CirHSLinkedList<T> &list);        //��ѭ����������ѭ��˫�������
    CirDoublyList(DoublyLinkedList<T> &list);       //��˫������ѭ��˫�������

    void concat(CirDoublyList<T> &list);            //��list����ϲ����ӵ���ǰ����*this��󣬲�����list����Ϊ�գ�ǳ����
    void insert(int i, CirDoublyList<T> &list);     //��list�����е����н�㸴�Ʋ��뵽��ǰ�����i�����֮ǰ�����
    void append(CirDoublyList<T> &list);            //��list�����е����н�㸴����ӵ���ǰ����������
    CirDoublyList<T> sub(int i, int n);             //���شӵ�i����㿪ʼ������Ϊn���ӱ����
    void remove(int i, int n);                             //ɾ���ӵ�i����㿪ʼ������Ϊn���ӱ�
    bool contain(CirDoublyList<T> &list);           //�ж��Ƿ����list��������н�㣬�ж�������Ӽ�
    DoubleNode<T>* search(CirDoublyList<T> &list);   //������listƥ����ӱ�BFģʽƥ��
    DoubleNode<T>* search(DoubleNode<T> *start, CirDoublyList<T> &list);  //��start��㿪ʼ������listƥ����ӱ�
    void removeAll(CirDoublyList<T> &list);         //ɾ��������listƥ����ӱ�
    void replaceAll(CirDoublyList<T> &patternlist, CirDoublyList<T> &replacementlist);
                                                           //����ǰ������������patternlistƥ����ӱ��滻Ϊreplacementlist�ӱ�
                                                           */
};

//��1�����Ա�ADT��������
template <class T>
CirDoublyList<T>::CirDoublyList()                          //�����ѭ��˫����
{
    this->head = new DoubleNode<T>();                      //����ͷ���
    this->head->prev = this->head->next = this->head;
}

template <class T>
CirDoublyList<T>::CirDoublyList(T values[], int n)         //����ѭ��˫������values�����ṩԪ��
{
    this->head = new DoubleNode<T>();                      //����ͷ���
    this->head->prev = this->head->next = this->head;
    for (int i=0; i<n; i++) 
        this->insert(values[i]);                           //��ѭ��˫������������
}

template <class T>
CirDoublyList<T>::~CirDoublyList()                         //��������
{
    this->removeAll();                                     //���ѭ��˫����
    delete this->head;                                     //�ͷ�ͷ���
}

template <class T>
bool CirDoublyList<T>::empty()                             //�ж�ѭ��˫�����Ƿ�Ϊ��
{
    return this->head->next==this->head;
}

//���º����㷨ͬѭ��������
template <class T>
int CirDoublyList<T>::count()                              //����ѭ��˫������
{
    int i=0;
    for (DoubleNode<T> *p=this->head->next; p!=this->head; p=p->next)
        i++;
    return i;
}

template <class T>
T& CirDoublyList<T>::get(int i)                            //���ص�i����0����Ԫ�ء���i��0����ڱ����׳��쳣��O(n)
{
    DoubleNode<T> *p=this->head->next;
    for (int j=0;  p!=this->head && j<i;  j++)             //����Ѱ�ҵ�i����㣨pָ��
        p=p->next;
    if (i>=0 && p!=NULL)                                   //��������iָ��Ԫ�������Ч
        return  p->data;                                   //���ص�i��Ԫ�أ�ִ��T�Ŀ������캯��
    throw out_of_range("����iָ��Ԫ����ų�����Χ");       //�׳�C++ STL��ΧԽ���쳣
}

//���õ�i����0����Ԫ��ֵΪx����i��0����ڱ����׳��쳣��O(n)
template <class T>
void CirDoublyList<T>::set(int i, T x)
{
    DoubleNode<T> *p=this->head->next;
    for (int j=0;  p!=this->head && j<i;  j++)             //����Ѱ�ҵ�i����㣬pָ���i�����
        p=p->next;
    if (i>=0 && p!=this->head)                             //��������iָ��Ԫ�������Ч
        p->data = x;                                       //ִ��T��=��ֵ����
    else throw out_of_range("����iָ��Ԫ����ų�����Χ");  //�׳�C++ STL��ΧԽ���쳣
}

//���ѭ��˫��������Ԫ�أ���ʽΪ��(,)����T��������<<�������㷨��O(n)
template <class T>
ostream& operator<<<>(ostream& out, CirDoublyList<T> &list)
{
    out<<"(";
    for (DoubleNode<T> *p=list.head->next; p!=list.head; p=p->next)
    {
        out<<p->data;
        if (p->next!=list.head)
            out<<", ";
    }
    out<<")\n";
    return out;
}

template <class T>
void CirDoublyList<T>::printPrevious()                     //���ѭ��˫�����Ӻ���ǰ������ǰ����
{
    cout<<"listPrevious: (";
    for (DoubleNode<T> *p=this->head->prev;  p!=this->head;  p=p->prev)
    {
        cout<<p->data;
        if (p->prev!=head)
            cout<<", ";
    }
    cout<<")\n";
}

//����x��Ϊ��i����0����Ԫ�أ����ز������ַ��
//��i��0������x��Ϊ��0��Ԫ�أ���i���ڱ�������x��Ϊ���һ��Ԫ�ء�O(n)
template <class T>
DoubleNode<T>* CirDoublyList<T>::insert(int i, T x)
{
    DoubleNode<T> *front=this->head;                       //frontָ��ͷ���
    for (int j=0; front->next!=head && j<i; j++)           //����Ѱ�Ҳ���λ��
        front = front->next;                               //ѭ��ֹͣʱ��front��λ����i-1���������һ�����
        //������front֮�����x��㣬����ͷ���루i��0�����м�/β���루i��0��
    DoubleNode<T> *q = new DoubleNode<T>(x, front, front->next);
    front->next->prev = q;
    front->next = q;
    return q;                                              //���ز������ַ
}

template <class T>
DoubleNode<T>* CirDoublyList<T>::insert(T x)               //��������xԪ�ؽ�㣬���ز������ַ��O(1)
{
    DoubleNode<T> *q = new DoubleNode<T>(x, this->head->prev, this->head);
    this->head->prev->next = q;                            //������ͷ���֮ǰ���൱��β����
    this->head->prev = q;
    return q;
}

//ɾ����i����0������㣬���ر�ɾ��Ԫ�ء���i��0����ڱ����׳��쳣��O(n)
template <class T>
T CirDoublyList<T>::remove(int i)
{
    DoubleNode<T> *p=this->head->next;
    for (int j=0;  p!=this->head && j<i;  j++)             //����Ѱ�ҵ�i����㣬pָ���i�����
        p=p->next;
    if (i>=0 && p!=this->head)                             //ɾ��p����Լ�
    {
        T old = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        return old;                                        //ִ��T�Ŀ������캯��
    }    
    throw out_of_range("����iָ��Ԫ����ų�����Χ");
}

template <class T>
void CirDoublyList<T>::removeAll()                             //���ѭ��˫����
{
    DoubleNode<T> *p=this->head->next;
    while (p!=this->head)
    {
        DoubleNode<T> *q = p;
        p = p->next;
        delete q;
    }
    this->head->next = this->head->prev = this->head;      //����ѭ��˫����Ϊ��
}
//�����ǵ�2�����ݣ�ʵ�����Ա�ADT
//����2.3.3��


/*//ϰ�����2��
//������������
template <class T>
class CirDoublyList : public SinglyList<T>        //ѭ��˫�����࣬�̳е�������
*/

//ϰ���� ϰ2.6 ѭ��˫����ĵ�����
template <class T>
DoubleNode<T>* CirDoublyList<T>::first()                   //����ѭ��˫�����һ������ַ��O(1)
{
    return head->next==head ? NULL : head->next;
}

template <class T>
DoubleNode<T>* CirDoublyList<T>::next(DoubleNode<T> *p)     //����p���ĺ�̽���ַ��O(1)
{
    return (head->next==head || p==NULL || p==head || p==head->prev) ? NULL : p->next;
}

template <class T>
DoubleNode<T>* CirDoublyList<T>::previous(DoubleNode<T> *p) //����p����ǰ������ַ��O(1)
{
    return (head->next==head || p==NULL || p==head || p==head->next) ? NULL : p->prev;
}

template <class T>
DoubleNode<T>* CirDoublyList<T>::last()                    //����ѭ��˫�������һ������ַ��O(1)
{
    return head->prev==head ? NULL : head->prev;
}

//ϰ���� ϰ2.7
//��list����ϲ����ӵ���ǰ����*this��󣬲�����list����Ϊ��
template <class T>
void CirDoublyList<T>::operator+=(CirDoublyList<T> &list)
{
    DoubleNode<T> *rear=this->head->prev;                   //rearָ��ǰ�������һ�����
    rear->next = list.head->next;
    list.head->next->prev = rear;
    rear=list.head->prev;
    rear->next = this->head;
    this->head->prev = rear;
    list.head->prev = list.head; 
    list.head->next = list.head; 
}