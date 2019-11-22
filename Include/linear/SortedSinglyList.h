//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.3.2   ������
//6.  ��������

#include "SinglyList.h"                                    //��ͷ���ĵ�������

//���������࣬�̳е������࣬T��������==��!=��>��>=��<��<=��ϵ�����
template <class T>
class SortedSinglyList : public SinglyList<T>
{
  private:
    bool asc;                                              //�������Լ����ȡֵΪtrue�����򣩡�false������

  public:
    SortedSinglyList(bool asc=true);                       //�������������Ĭ������
    SortedSinglyList(T values[], int n, bool asc=true);     //��������������values�����ṩԪ�� 

//    SortedSinglyList(SortedSinglyList<T> &list):SinglyList<T>(list){}   //Ĭ�Ͽ������캯������ʡ��
//    ~SortedSinglyList(){}                             //Ĭ�������������Զ�ִ��~SinglyList<T>()����ʡ��

    void set(int i, T x);                                  //��֧�ָò������׳��쳣������
    Node<T>* insert(T x);                                  //���룬����xԪ�ش�Сȷ������λ�ã�����
    Node<T>* search(T key);                                //˳������״γ��ֵĹؼ���ΪkeyԪ�أ�����
//    void insertUnrepeatable(T x);                          //���벻�ظ�Ԫ�أ����ز������ַ������
    void removeFirst(T key);                               //ɾ���״γ��ֵĹؼ���ΪkeyԪ�صĽ�㣻����

    //��9������
    SortedSinglyList(SinglyList<T> &list, bool asc=true);  //���ؿ������캯�����ɵ���������������
    void operator+=(SortedSinglyList<T> &list);            //�鲢����������������
};


//�������������ascָ������true������false����Ĭ������
template <class T>
SortedSinglyList<T>::SortedSinglyList(bool asc) 
{                                                          //�˴��Զ�ִ��SinglyList<T>()������ͷ���
    this->asc = asc;
//    cout<<"SortedSinglyList(bool asc)"<<endl;
}

//��������������values�����ṩԪ�أ�nָ��values���鳤�ȣ�
//ascָ������true������false����Ĭ������ֱ�Ӳ��������㷨
template <class T>
SortedSinglyList<T>::SortedSinglyList(T values[], int n, bool asc)
{                                                          //�˴��Զ�ִ��SinglyList<T>()
    this->asc = asc;
    for (int i=0; i<n; i++)  
        this->insert(values[i]);                            //�����������
}

template <class T>
void SortedSinglyList<T>::set(int i, T x)                  //��֧�ָò������׳��쳣������ʱ����
{
    throw logic_error("��֧��set(int i, T x)����");        //�׳�C++ STL�߼������쳣
}

//�����㣬����xԪ�ش�Сȷ������λ�ã����ز������ַ��T��������>=��<=�������
//���ǻ���insert(int i, T x)��insert(T x)��Ա����������ʱ���ǻ���insert(T x)�麯����
//����˳������㷨ȷ������λ�ã����ҳɹ�������ͬԪ�ء�
template <class T>
Node<T>* SortedSinglyList<T>::insert(T x)
{
    Node<T> *front=head, *p=head->next;                    //front��p��ǰ�����
    //����ѭ����Ѱ��x�Ĳ���λ�ã�����x�ڵ�ֵ���֮������ʱ�Ƚ�>=������ʱ�Ƚ�<=
    while (p!=NULL && (asc ? x>=p->data : x<=p->data))
    {   front = p;                                         //��סp��ǰ��front 
        p = p->next;
    }
    Node<T> *q = new Node<T>(x, p);
    front->next = q;                                       //������front���֮��
    return q;
}

//5.2.2 ϡ��������Ԫ���еĵ����� �ã�
//��7������ ͼ���ڽӱ� 

//˳������״γ��ֵĹؼ�����key��ȵ�Ԫ�أ�����Ԫ�ؽ�㣻���Ҳ��ɹ�����NULL��
//T��������==��<=��>=���㣬==Լ�����ҹ����бȽ�����Ԫ����ȵĹ���<=��>=����Լ���������
//���ǻ���SinglyList<T>��search(T key)����
//���������˳������㷨��ֻ�Ƚϲ��ֵ�������ȷ�����Ҳ��ɹ�������Ҫ����������
template <class T>
Node<T>* SortedSinglyList<T>::search(T key)
{
    Node<T>* p=this->head->next; 
    while (p!=NULL && (asc ? p->data<=key : p->data>=key)) //T��������<=��>=����
    {
        if (p->data==key)                                  //T��������==����
            return p;
        p=p->next
    }
    return NULL;
}

//ɾ���״γ��ֵĹؼ���ΪkeyԪ�صĽ�㡣���ǻ���removeFirst(T key)��Ա������
//����˳������㷨ȷ������λ�ã����ҳɹ�ɾ��������ɾ����T��������==��>��<�����
template <class T>
void SortedSinglyList<T>::removeFirst(T key)
{
    Node<T> *front=head, *p=head->next;                    //front��p��ǰ�����
    while (p!=NULL && (asc ?  key>p->data : key<p->data))  //T��������>��<
    {   front = p;
        p = p->next;
    }
    if (p!=NULL && key==p->data)                           //T��������==������ʶ�����
    {   front->next = p->next;                             //ɾ��p���
        delete p;
    }
}

//����2.3��

/*
//���벻�ظ�Ԫ��x������Ԫ�ش�С�����ں���λ�ã����ز������ַ��T��������==��>=����
template <class T>
//����Node<T>* ����?����?
void SortedSinglyList<T>::insertUnrepeatable(T x)
{
    Node<T> *front=this->head, *p=front->next;   //front��p��ǰ�����
    while (p!=NULL && x >= p->data)              //Ѱ�Ҳ���λ�ã��������ظ�Ԫ�أ�T��������>=����
    {
        if (x == p->data)                        //T��������==����
            return NULL;
        front = p;
        p = p->next;
    }
    front->next = new Node<T>(x, p);             //��front���֮��p֮ǰ����ֵΪx���
    return front->next;                          //���ز������ַ
}



/*��ȷ����ʡ��
template <class T>
SortedSinglyList<T>::~SortedSinglyList()     //Ĭ���������������ܼ̳л��������������Զ�ִ�л�����������
{
//    cout<<"����~SortedSinglyList "<<*this;
}                                                //�˴��Զ�ִ�л�����������~SinglyList<T>()

//�������
template <class T>
SortedSinglyList<T>::SortedSinglyList(SortedSinglyList<T> &list)//Ĭ�Ͽ������캯��
{                                                //�˴�Ĭ�ϵ���SinglyLinkedList()
 //   this->head = list.head;   //�����ǳ����
}

//Ĭ�ϸ�ֵ�����̳л����=������
template <class T>
SortedSinglyList<T>& SortedSinglyList<T>::operator=(SortedSinglyList<T> &list)//�˴���������ʽ�������û���=
{
    SinglyLinkedList<T>::operator=(list);         	 //���û��ำֵ��������Ϊ���
    return *this;
}*/

//��9������
//9.6   ��/˫����������㷨
//1.  �ɵ���������������ֱ�Ӳ�������

//���ؿ������캯�����ɵ����������������������ascָ������true������false����Ĭ������
template <class T>
SortedSinglyList<T>::SortedSinglyList(SinglyList<T> &list, bool asc)
{                                                          //�˴�Ĭ��ִ��SinglyList<T>()
    this->asc = asc;
    for (Node<T> *p=list.head->next;  p!=NULL;  p=p->next) 
        this->insert(p->data);                             //����������룬һ��ֱ�Ӳ�������
}
//2.  �ɵ���������������ֱ��ѡ������


//3.  �鲢������������
//�鲢���������������ǻ���ͬ����������������������������ͬ�������׳��쳣
template <class T>
void SortedSinglyList<T>::operator+=(SortedSinglyList<T> &list)
{
    if (this->asc == list.asc)                            //������������Ĵ�����ͬ
    {
        Node<T> *front=head, *p=head->next;               //p����this������front��p��ǰ��
        Node<T> *q=list.head->next;                       //q����list������
        while (p!=NULL && q!=NULL)
            if (this->asc ? p->data < q->data : p->data > q->data)
            {                //�Ƚ�����������ǰ���ֵ������ʱ�Ƚ�<������ʱ�Ƚ�>
                front = p;
                p = p->next;
            }
            else
            {                                              //��q�����뵽front���֮��
                front->next = q;
                q = q->next;
                front = front->next;
                front->next = p;
            }
        
        if (q!=NULL)                                       //��list������ʣ���㲢�뵱ǰ����β
            front->next=q;
        list.head->next = NULL;                            //����list����Ϊ�յ�����
    }
    else throw invalid_argument("���������������ͬ�����ܹ鲢"); //�׳�C++ STL��Ч�����쳣
}
