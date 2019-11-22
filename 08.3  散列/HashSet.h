//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//8.4   ɢ��
//����ͼ8.11��ʾ�ṹ����ַ����ɢ�б��࣬�������롢ɾ�������ҡ������Ȳ�����

#include "SinglyList.h"                                    //��������

template <class T>
class HashSet                                              //��������ַ����ɢ�б��࣬T����֧��hashCode()����ɢ����
{
  private:
    SinglyList<T> *table;                                  //ɢ�б�����飬����Ԫ���ǵ��������
    int length;                                            //ɢ�б����������
    int hash(T key);                                       //ɢ�к���
     
  public:
    HashSet(int length=32);                                //����ָ��������ɢ�б�
    ~HashSet();                                            //��������

    void insert(T key);                                    //����Ԫ��key
    void remove(T key);                                    //ɾ���ؼ���ΪkeyԪ��
    T* search(T key);                                      //���ҹؼ���ΪkeyԪ��
    friend ostream& operator<<<>(ostream& out, HashSet<T> &); //���ɢ�б�������Ԫ��
};

template <class T>
HashSet<T>::HashSet(int length)                            //��������Ϊlength��ɢ�б�
{
    this->length = length;
    this->table = new SinglyList<T>[length];               //Ĭ��ִ��SinglyList<T>()����յ�����
}

template <class T>
HashSet<T>::~HashSet()                                     //��������
{
    delete[] this->table;                                  //���ִ��~SinglyList()��������������
}

//ɢ�к���������ؼ���ΪkeyԪ�ص�ɢ�е�ַ��������������������ɢ�б���
//��T����ʱ��T��������hashCode()���ض����ɢ���룬Լ������int��һ��һӳ��
template <class T>
int HashSet<T>::hash(T key)
{    
    return key.hashCode() % this->length;                  //ʹ��key�����ɢ�������
//    return key % this->length;                           //��T�ǻ�������ʱ
}
  
template <class T>
void HashSet<T>::insert(T key)                             //����Ԫ��key
{
    int i = hash(key);                                     //ɢ�е�ַ
    this->table[i].insertUnrepeatable(key);                //ͬ��ʵ�����β����ؼ��ֲ��ظ�Ԫ��
} 

template <class T>
void HashSet<T>::remove(T key)                             //ɾ���ؼ���ΪkeyԪ�أ���δ�ҵ�Ԫ�أ���ɾ��
{
    this->table[hash(key)].removeFirst(key);               //��ͬ��ʵ�������ɾ���ؼ���Ϊkey���
}

//���ҹؼ���ΪkeyԪ�أ������ҳɹ�����Ԫ�ص�ַ�����򷵻�NULL
template <class T>
T* HashSet<T>::search(T key)
{
    Node<T> *find = this->table[hash(key)].search(key);    //�ڵ������в��ң����ؽ��
    return (find==NULL) ? NULL : &find->data;
}

template <class T>
ostream& operator<<<>(ostream& out, HashSet<T> &ht)        //���ɢ�б�ĸ�ͬ��ʵ�������Ԫ��
{
    for(int i=0; i<ht.length; i++)
        out<<"table["<<i<<"]= "<<ht.table[i];              //�������������Ԫ��ֵ
    return out;
}

/*
�����������󣬲���ָ���洢��˳����ָ��λ�á��洢λ�ÿ��� > ����
    SeqList<SinglyList<int>> hashtable;                    //ɢ�б�Ԫ���ǵ������˳���
��ˣ�ֻ�������顣����������˳���Ĳ��

*/