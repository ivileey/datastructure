//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.3.2   ������
//3.  ��ͷ���ĵ�����

#include <iostream>
using namespace std;
#include "Node.h"                                          //����������

template <class T>
class SinglyList                                           //��ͷ���ĵ������࣬Tָ��Ԫ�����ͣ�T��������==��ϵ�����
{
  public:
    Node<T> *head;                                         //ͷָ�룬ָ�������ͷ���

    SinglyList();                                          //����յ�����
    SinglyList(T values[], int n);                         //���쵥������values�����ṩԪ��
    ~SinglyList();                                         //��������
 
    bool empty();                                          //�жϵ������Ƿ�Ϊ��
    int count();                                           //���ص������� 
    T& get(int i);                                         //���ص�i����0����Ԫ������
    virtual void set(int i, T x);                          //���õ�i����0����Ԫ��Ϊx���麯��
    friend ostream& operator<<<>(ostream&, SinglyList<T>&);//�������������Ԫ��
    Node<T>* insert(int i, T x);                           //����x��Ϊ��i����0������㣬���ز������ַ
    virtual Node<T>* insert(T x);                          //�ڵ�����������xԪ�أ��麯��
    T remove(int i);                                       //ɾ����i����0������㣬���ر�ɾ��Ԫ��
    void removeAll();                                      //��յ�����

    //5.2.2 ϡ��������Ԫ���еĵ����� �ã�8.2.1 ɢ�б��ã�T��������==��!=�����
	Node<T>* search(T key);                                //˳������״γ��ֵĹؼ���ΪkeyԪ�أ����ؽ���ַ����δ�ҵ�������NULL��
                                                           //T��������==�������Լ���Ƚ�����Ԫ����ȣ�==���Ĺ���
    void insertUnrepeatable(T x);                          //β���벻�ظ�Ԫ��
    virtual void removeFirst(T key);                       //ɾ���״γ��ֵ�Ԫ��ֵΪkey�Ľ��

	bool operator==(SinglyList<T> &list);                  //���ع�ϵ�����==���Ƚ������������Ƿ����
    bool operator!=(SinglyList<T> &list);                  //���ع�ϵ�����!=���Ƚ������������Ƿ����
    SinglyList(SinglyList<T> &list);                       //������캯�������Ƶ�����list�����н��
    SinglyList<T>& operator=(SinglyList<T> &list);         //����=��ֵ����������
    virtual void operator+=(SinglyList<T> &list);          //��list�����ڵ�ǰ������֮���麯��

    //ϰ�����2��ϰ2.4
    Node<T>* first();                                      //���ص������һ������ַ
    Node<T>* next(Node<T> *p);                             //����p���ĺ�̽���ַ
    Node<T>* previous(Node<T> *p);                         //����p����ǰ������ַ
    Node<T>* last();                                       //���ص��������һ������ַ

    //��ϰ2.5����ת������
    void reverse();                                        //����ǰ��������ת

    //ʵ��2
    bool contain(T x);                           //�жϵ������Ƿ����Ԫ��x
    bool isSorted();                             //�жϵ������Ƿ�����������
    void replaceFirst(T key, T x);                 //���������е�Ԫ��key�滻ΪԪ��x
    void replaceAll(T key, T x);                   //������ֵΪkeyԪ���滻ΪԪ��x
                                                 //��������sourcelistƥ����ӱ��滻Ϊdestlist�ӱ�
    void removeAll(T x);                         //ɾ������Ԫ��ֵΪkey�Ľ��

    //4.4 �ݹ��㷨
  private:
    Node<T>* create(T values[], int n, int i);    //��ָ�����鹹�쵥����
    int count(Node<T> *p);                       //���ش�p��㿪ʼ�ĵ�������
    void print(Node<T> *p);                       //�����p��㿪ʼ�ĵ�����
    bool equals(Node<T> *p, Node<T> *q);         //�Ƚ������������Ƿ����
    Node<T>* copy(Node<T> *p);                   //���Ƶ������ݹ��㷨
    void replaceAll(Node<T> *p, T key, T x);       //������ֵΪkeyԪ���滻ΪԪ��x
//    void removeAll(T x);                         //ɾ������Ԫ��ֵΪkey�Ľ��

};

template <class T>
SinglyList<T>::SinglyList()                                //����յ�����
{
//    cout<<"SinglyList()"<<endl;
    this->head = new Node<T>();                            //����ͷ��㣬data������δ��ʼ��
}

template <class T>
SinglyList<T>::SinglyList(T values[], int n)                //���쵥������values�����ṩԪ�أ�β����
{
    this->head = new Node<T>();                            //����ͷ��㣬���������
    Node<T> *rear = this->head;                            //rearָ���������һ�����
    for (int i=0; i<n; i++)                                //��n>0������ǿ�����
    {
        rear->next = new Node<T>(values[i]);                //�����������rear���֮��β����
        rear = rear->next;                                 //rearָ���µ���β���
    }
}

template <class T>
SinglyList<T>::~SinglyList()                               //��������
{
//    cout<<"����~SinglyList()"<<*this;
    this->removeAll();                                         //��յ�����
    delete this->head;                                     //�ͷ�ͷ���
}

template <class T>
bool SinglyList<T>::empty()                              //�жϵ������Ƿ�Ϊ�գ�O(1)
{
    return this->head->next==NULL;
}

//�������������Ԫ�أ���ʽΪ��(,)����T��������<<������������㷨��O(n)
template <class T>
ostream& operator<<<>(ostream& out, SinglyList<T> &list)
{
//    out<<"0x"<<list.head->next;
    out<<"(";
    for (Node<T> *p=list.head->next;  p!=NULL;  p=p->next) //p����������
    {
        out<<p->data;                                      //ִ��T��<<��T��������<<����������
        if (p->next!=NULL)
            out<<", ";
    }
    out<<")\n";
    return out;
}

template <class T>
int SinglyList<T>::count()                                 //���ص������ȣ�����������㷨��O(n)
{
    int i=0;
    for (Node<T> *p=this->head->next;  p!=NULL;  p=p->next)//p����������
        i++;
    return i;
}

template <class T>
T& SinglyList<T>::get(int i)                               //���ص�i����0����Ԫ�ء���i��0����ڱ����׳��쳣��O(n)
{
    Node<T> *p=this->head->next;
    for (int j=0;  p!=NULL && j<i;  j++)                   //�������ֵ�����Ѱ�ҵ�i����㣨pָ��
        p=p->next;
    if (i>=0 && p!=NULL)                                   //������������iָ��Ԫ�������Ч
        return  p->data;                                   //���ص�i��Ԫ�أ�ִ��T�Ŀ������캯��
    throw out_of_range("����iָ��Ԫ����ų�����Χ");       //�׳�C++ STL��ΧԽ���쳣
}
           
//���õ�i����0����Ԫ��ֵΪx����i<0����ڱ����׳��쳣��O(n)
template <class T>
void SinglyList<T>::set(int i, T x)
{
    Node<T> *p=this->head->next;
    for (int j=0;  p!=NULL && j<i;  j++)                   //����Ѱ�ҵ�i����㣬pָ���i�����
        p=p->next;
    if (i>=0 && p!=NULL)                                   //������������iָ��Ԫ�������Ч
        p->data = x;                                       //ִ��T��=��ֵ����
    else throw out_of_range("����iָ��Ԫ����ų�����Χ");  //�׳�C++ STL��ΧԽ���쳣
}

//����x��Ϊ��i����0����Ԫ�أ����ز������ַ��
//��i��0������x��Ϊ��0��Ԫ�أ���i���ڱ�������x��Ϊ���һ��Ԫ�ء�O(n)
template <class T>
Node<T>* SinglyList<T>::insert(int i, T x) 
{
    Node<T> *front=this->head;                             //frontָ��ͷ���
    for (int j=0; front->next!=NULL && j<i; j++)           //�������ֵ�����Ѱ�Ҳ���λ��
        front=front->next;                                 //ѭ��ֹͣʱ��front��λ����i-1���������һ�����
    front->next = new Node<T>(x, front->next);
                               //��front֮�����x��㣬����ͷ���루i��0�����м�/β���루i��0��
    return front->next;                                    //���ز������ַ
}

template <class T>
Node<T>* SinglyList<T>::insert(T x)                        //�ڵ�����������xԪ�ؽ�㣬���ز������ַ��O(n)
{
    Node<T> *rear=this->head;
    while (rear->next!=NULL)                               //����Ѱ�ҵ�����β��㣬�������
        rear=rear->next;
    rear->next = new Node<T>(x);                           //��rear���֮�����ֵΪx���
    return rear->next;                                     //���ز������ַ
}

//ɾ����i����0������㣬���ر�ɾ��Ԫ�ء���i<0����ڱ����׳��쳣��O(n)
template <class T>
T SinglyList<T>::remove(int i)
{
    Node<T> *front=this->head;                             //frontָ��ͷ���
    for (int j=0; front!=NULL && j<i;  j++)                //�������ֵ�����front��λ����i-1�����
        front=front->next;
    if (i>=0 && front!=NULL && front->next!=NULL)          //��front�ĺ�̽�����ʱ��ɾ��֮
    {
        Node<T> *q=front->next;                            //q���Ϊfront�ĺ�̽��
        T old = q->data;
        front->next = q->next;
        delete q;
        return old;                                        //ִ��T�Ŀ������캯��
    }
    throw out_of_range("����iָ��Ԫ����ų�����Χ");
}

template <class T>
void SinglyList<T>::removeAll()                            //��յ�����O(n)
{
    Node<T> *p=this->head->next;
    while (p!=NULL)
    {
        Node<T> *q = p;
        p = p->next;                                       //����p�ĺ�̽��
        delete q;                                          //�ͷ�q�����ռ�õĴ洢��Ԫ
    }
    head->next=NULL;                                       //���õ�����Ϊ�գ��������д�
}

//��5�� ϡ��������Ԫ���еĵ�������������
//˳������״γ��ֵĹؼ���ΪkeyԪ�أ����ؽ���ַ����δ�ҵ�������NULL��
//T��������==�������Լ���Ƚ�����Ԫ����ȣ�==���Ĺ���
template <class T>
Node<T>* SinglyList<T>::search(T key)
{
    for (Node<T>* p=this->head->next;  p!=NULL;  p=p->next)
        if (p->data==key)                                  //T��������==�����
            return p;
    return NULL;
}

//�Ƚ������������Ƿ���ȣ��������ж�Ӧ���Ԫ������ҳ�����ȡ�T��������==�����
template <class T>
bool SinglyList<T>::operator==(SinglyList<T> &list)
{
    if (this==&list || this->head==list.head)
              //ָ��Ƚϣ���������������ͬһ��ʵ����������ǳ������������������ͬһ��������ʱ
        return true;
    Node<T> *p=this->head->next, *q=list.head->next;
    while (p!=NULL && q!=NULL && p->data==q->data)         //T��������==�����
    {
        p = p->next;
        q = q->next;
    }
    return p==NULL && q==NULL;
}
template <class T>
bool SinglyList<T>::operator!=(SinglyList<T> &list)        //�Ƚ������������Ƿ����
{
    return !(*this==list);
}

//5.  �������ǳ���������
/*
template <class T>
SinglyList<T>::SinglyList(SinglyList<T> &list)   //Ĭ�Ͽ������캯����ǳ����
{
    this->head = list.head;                      //��Ӧ��Ա������ֵ��ָ�븳ֵ��������������ָ��ͬһ����������������
}
template <class T>
SinglyList<T>& SinglyList<T>::operator=(SinglyList<T> &list)   //Ĭ��=��ֵ��ǳ����
{
    this->head = list.head;                      //��Ӧ��Ա������ֵ��ָ�븳ֵ��������������ָ��ͬһ����������������
    return *this;
}*/

//����=��ֵ������������ɾ���ٸ��Ʋ����㷨
//�����㽫ִ��T��=���㣬�Ƿ���Ԫ�ض���ȡ����T��=��ǳ���������
template <class T>
SinglyList<T>& SinglyList<T>::operator=(SinglyList<T> &list)
{
    this->removeAll();                                     //��յ�ǰ������ֻʣͷ��㣬�ͷ��������
    Node<T> *rear = this->head;                            //rearָ���������һ�����
    for (Node<T> *p=list.head->next;  p!=NULL;  p=p->next) //p����list������
    {
        rear->next = new Node<T>(p->data);                 //���ƽ��β���뵽this������
        rear = rear->next;                                 //rearָ���µ���β���
    }
    return *this;
}

template <class T>
SinglyList<T>::SinglyList(SinglyList<T> &list)             //��������Ƶ�������������=
{
    this->head = new Node<T>();                            //����ͷ���
    *this=list;                                            //ִ�е�����ֵ�����
}

//����2.3����������������
//��list�����ڵ�ǰ������֮����β��Ӻϲ���һ��������
template <class T>
void SinglyList<T>::operator+=(SinglyList<T> &list)  //�����Ƕ�������
//void SinglyList<T>::mergeWith(SinglyList<T> list) //�����Ƕ��󣬲�������ʱִ�п������캯��
{
    Node<T> *rear=this->head;
    while (rear->next!=NULL)                               //�ҵ���ǰ����������һ�����
        rear = rear->next;
    rear->next = list.head->next;                          //������������β������Ӻϲ���һ��������
    list.head->next = NULL;                                //����list������Ϊ�գ��������д�
//    cout<<*this<<list;                          //���������
}
//�����ǵ�2�����ݣ�ʵ�����Ա�ADT

/*���д�ϰ�����2��
template <class T>
void SinglyList<T>::removeAll()                          //��յ�����O(n)
{
    for (Node<T> *p=this->head->next;  p!=NULL;  p=p->next)
    {
        Node<T> *q=p;
        delete q;                                          //�ͷ�q�����ռ�õĴ洢��Ԫ
    }
    head->next=NULL;                                       //���õ�����Ϊ�գ��������д�
}*/

//��2��˼���⣬ɢ�б���
//β���벻�ظ�Ԫ��x�����ڲ����㷨��T��������==�������
template <class T>
void SinglyList<T>::insertUnrepeatable(T x)
{
    Node<T> *front=this->head, *p=front->next;
    while (p!=NULL && p->data!=x)                          //���ң�T��������!=�����
    {
        front = p;                                         //front��p��ǰ�����
        p = p->next;
    }
    if (p==NULL)                                           //β����ֵΪx��㣬�������ظ�Ԫ��
        front->next = new Node<T>(x); 
}

//ɾ���״γ��ֵ�Ԫ��ֵΪx�Ľ�㣬T��������!=�������ɢ�б���
template <class T>
void SinglyList<T>::removeFirst(T x)
{
    Node<T> *front=this->head, *p=front->next;
    while (p!=NULL && p->data!=x)                          //����ֵΪx��㣬T��������!=�����
    {
        front = p;
        p=p->next;
    }
    if (p!=NULL)                                           //ɾ��p���
    {
        front->next = p->next;
        delete(p);
    }
}

//�����ǵ�2��ϰ��
//��ϰ2.4������������ֵ��

//������ĵ�����
template <class T>
Node<T>* SinglyList<T>::first()                            //���ص������һ������ַ��O(1)
{
    return this->head->next;
}

template <class T>
Node<T>* SinglyList<T>::next(Node<T> *p)                   //����p���ĺ�̽���ַ��O(1)
{
    return p==NULL ? NULL : p->next;
}

template <class T>
Node<T>* SinglyList<T>::previous(Node<T> *p)               //����p����ǰ������ַ��O(n)
{
    if (p==NULL || p==this->head)
        return NULL;
    Node<T> *front=head->next;
    while (front!=NULL && front->next!=p)
        front=front->next;
    return front;
}

template <class T>
Node<T>* SinglyList<T>::last()                             //���ص��������һ������ַ��O(n)
{
    Node<T> *p=head->next;
    while (p!=NULL && p->next!=NULL)
        p=p->next;
    return p;
}

//��ϰ2.5����ת������
template <class T>
void SinglyList<T>::reverse()                              //����ǰ��������ת���㷨����ͼ��ϰ����ͼ2.8
{
    Node<T> *p=this->head->next, *front=NULL;              //front��Ϊp����ǰ�����
    while (p!=NULL)
    {
        Node<T> *succ = p->next;                           //����succ��p�ĺ�̽��
        p->next = front;                                   //ʹp->nextָ��p����ǰ�����
        front = p;
        p = succ;                                          //p�����̽��
    }
    this->head->next = front;                              //�ı䵥����ͷ����ָ����
}


//���ڲ��ҵ�ɾ�����滻
template <class T>
void SinglyList<T>::replaceFirst(T x, T y)               //���״γ��ֵ�Ԫ��x�滻ΪԪ��y��T��������!=�����
{
    Node<T>* p=this->search(x);
    if (p!=NULL)
        p->data = y;
}

template <class T>
void SinglyList<T>::replaceAll(T x, T y)                 //������ֵΪxԪ���滻ΪԪ��y��T��������==�����
{
    for (Node<T>* p=this->head->next;  p!=NULL;  p=p->next)
        if (p->data==x)
            p->data = y;
}

template <class T>
void SinglyList<T>::removeAll(T x)                       //ɾ��������������Ԫ��ֵΪx�Ľ�㣬T��������!=�����
{
    Node<T> *front=this->head, *p=front->next;
    while (p!=NULL)
        if (p->data!=x)                                    //���ң�T��������!=�����
        {
            front = p;
            p = p->next;
        }
        else
        {
            front->next = p->next;                         //ɾ��p���
            delete p;
            p = front->next;                               //pָ��front��̽�㣬�ٴβ���
        }
}

template <class T>
bool SinglyList<T>::isSorted()                             //�жϵ������Ƿ����������򣩣�T��������>�����
{
    Node<T> *front=this->head->next, *p;
    while (front!=NULL)
    {
        p=front->next;
        if (p!=NULL && front->data > p->data)              //T��������>�����
            return false;
        front = p;
    }
    return true;
}

/*
//4.4 �ݹ��㷨����ȷ
template <class T>
SinglyList<T>::SinglyList(T values[], int n)               //���쵥������values�����ṩԪ��
{
    this->head = new Node<T>();                            //����ͷ���
    this->head->next = create(values,n,0);
}

//���쵥�����ݹ��㷨����values����ĵ�i��Ԫ�ع��쵱ǰ��㣬β����
template <class T>
Node<T>* SinglyList<T>::create(T values[], int n, int i)
{
    Node<T> *p=NULL;
    if (i<n)
    {
        p = new Node<T>(values[i]);
        p->next = create(values, n, i+1);                   //�ݹ����
    }
    return p;
}

template <class T>
int SinglyList<T>::count()                                 //���ص������ȣ��ݹ��㷨
{
    return count(this->head->next);
}
template <class T>
int SinglyList<T>::count(Node<T>*p)                        //���ش�p��㿪ʼ�ĵ������ȣ��ݹ��㷨
{
    if (p==NULL)
        return 0;
    return 1+count(p->next);                               //�ݹ����
}

//ʵ��4
//����������ݹ��㷨����ʽΪ��(,)����T��������<<
template <class T>
ostream& operator<<<>(ostream& out, SinglyList<T> &list)
{
    out<<"(";
    list.print(list.head->next);
    out<<")\n";
    return out;
}

template <class T>
void SinglyList<T>::print(Node<T>*p)                       //�����p��㿪ʼ�ĵ������ݹ��㷨��˽�к���
{
    if (p!=NULL)
    {
        cout<<p->data;
        if (p->next!=NULL)
            cout<<", ";
        print(p->next);                                    //�ݹ����
    }
}

template <class T>
bool SinglyList<T>::operator==(SinglyList<T> &list)        //�Ƚ������������Ƿ����
{
    return equals(this->head->next, list.head->next);
}
template <class T>
bool SinglyList<T>::equals(Node<T> *p, Node<T> *q)         //�Ƚ������������Ƿ���ȣ��ݹ��㷨��˽�к���
{
    return p==NULL && q==NULL || p!=NULL && q!=NULL && p->data==q->data && equals(p->next, q->next);
}

template <class T>
SinglyList<T>::SinglyList(SinglyList<T> &list)             //������Ŀ������캯��
{
    this->head = new Node<T>();                            //����ͷ���
    this->head->next = copy(list.head->next);
}
template <class T>
Node<T>* SinglyList<T>::copy(Node<T> *p)                   //���Ƶ������ݹ��㷨��˽�к���
{
    Node<T> *q=NULL;
    if (p!=NULL)
    {
        q = new Node<T>(p->data);
        q->next = copy(p->next);                           //�ݹ����
    }
    return q;
}

//˳������״γ��ֵĹؼ���ΪkeyԪ�أ����ؽ���ַ����δ�ҵ�������NULL��
template <class T>
Node<T>* SinglyList<T>::search(T key)
{
    return search(key, this->head->next);
}

template <class T>
Node<T>* SinglyList<T>::search(T key, Node<T>* p)          //�ӵ�����p��㿪ʼ˳�����Ԫ��key
{
    if (p!=NULL && p->data!=key)                           //T��������!=
        return search(key, p->next);
    return p;
}

template <class T>
void SinglyList<T>::replaceAll(T key, T y)                   //������ֵΪkeyԪ���滻ΪԪ��x
{
     replaceAll(head->next, key, x);
}

template <class T>
void SinglyList<T>::replaceAll(Node<T> *p, T key, T x)     //������ֵΪkeyԪ���滻ΪԪ��x���ݹ��㷨��˽�к���
{
    if (p!=NULL)
    {
        if (p->data==key)
            p->data = x;
        replaceAll(p->next, key, x);
    }
}*/

