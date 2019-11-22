//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����5.5�� ϡ��������Ԫ���еĵ�����
//��˳�����Ϊ��ָ�����飬SeqList��get(i)����T& ?? δ����

#include "Triple.h"                                        //������Ԫ����
#include "SeqList.h"                                       //˳����ࣨ��2�£�
#include "SortedSinglyList.h"                              //���������ࣨ��2�£�

class LinkedMatrix                                         //��Ԫ���еĵ�����洢�ľ����� 
{
  private:
    int rows, columns;                                     //��������������

    void init(int rows, int columns);                      //���������ָ������������

  public:
    SeqList<SortedSinglyList<Triple>*> rowlist;            //��ָ��˳���Ԫ����ָ��������������ָ��

    LinkedMatrix(int rows=0);                              //���������ָ����������������ͬ
    LinkedMatrix(int rows, int columns);                   //���������ָ������������
    LinkedMatrix(int rows, int columns, Triple elem[], int n);  //����Ԫ������ָ����ֵ
    ~LinkedMatrix();                                       //��������

    friend ostream& operator<<<>(ostream& out, LinkedMatrix&);//�������
    int get(int i, int j);                                 //���ص�i��j��Ԫ��ֵ
    void set(int i, int j, int x);                         //���õ�i��j��Ԫ��ֵΪx
    void set(Triple e);                                    //����Ԫ������Ԫ��
    void setRowsColumns(int rows, int columns);            //���þ���������

    //����ʵ��5��δ���
    LinkedMatrix(LinkedMatrix &mat);                       //�������캯�������
    LinkedMatrix& operator=(LinkedMatrix &mat);            //����=��ֵ��������Զ�����
    bool operator==(LinkedMatrix &mat);                    //�Ƚ�����ͬ�׾����Ƿ����
    void operator+=(LinkedMatrix &mat);                    //��ǰ������mat�������
    LinkedMatrix operator+(LinkedMatrix &mat);             //���ص�ǰ������mat��Ӻ�ľ���
    void operator*=(LinkedMatrix &mat);                    //��ǰ������mat������ˣ�δʵ��
    LinkedMatrix operator*(LinkedMatrix &mat);             //���ص�ǰ������mat��˺�ľ���
    LinkedMatrix transpose();                              //���ص�ǰ�����ת�þ���
    bool isUpTriangular();                                 //�жϵ�ǰ�����Ƿ�Ϊ�����Ǿ���
    bool isSymmetric();                                    //�жϵ�ǰ�����Ƿ�Ϊ�Գƾ���
};

//��1������������
void LinkedMatrix::init(int rows, int columns)             //��ʼ��
{
    if (rows>=0 && columns>=0)
    {
        this->rows = rows;
        this->columns = columns;
        for (int i=0; i<rows; i++)
            this->rowlist.insert(new SortedSinglyList<Triple>(true)); //˳���β���룬Ԫ��Ϊָ��������������򣩵�ָ��
    }
    else throw invalid_argument("�����л�����Ϊ�����쳣"); //�׳���Ч�����쳣
}

LinkedMatrix::LinkedMatrix(int rows)                       //���������ָ����������������ͬ
{                                      //�˴��Զ�ִ�й��캯��SeqList<T>()��SeqList.n=0��Ԫ��δ��ʼ��
    this->init(rows, rows);
}

LinkedMatrix::LinkedMatrix(int rows, int columns)          //���������ָ������������
{                                      //�˴��Զ�ִ�й��캯��SeqList<T>()��SeqList.n=0��Ԫ��δ��ʼ��
    this->init(rows, columns);
}

//����Ԫ�����й�����󣬲����ֱ�ָ���������������������Ԫ�����С���Ԫ�����г���
LinkedMatrix::LinkedMatrix(int rows, int columns, Triple elem[], int n)
{                                                //�˴��Զ�ִ�й��캯��SeqList<T>()��SeqList.n=0
    this->init(rows, columns);
    for (int i=0; i<n; i++)
        this->set(elem[i]);
}

LinkedMatrix::~LinkedMatrix()                              //��������
{
    for (int i=0; i<this->rows; i++)
        this->rowlist[i]->~SortedSinglyList<Triple>();     //������������Ĭ��ִ�л���~SinglyList<Triple>()
}                            //�˴�ִ��~SeqList<T>()�ͷ�˳���ռ�õ�һά����

//��2�� ���
ostream& operator<<(ostream& out, LinkedMatrix &mat)       //���ϡ�����
{
    for (int i=0; i<mat.rows; i++)
        out<<i<<" -> "<<(*mat.rowlist[i]);                 //�����i����������
    return out;
}

//��3�� ��ȡԪ��
//���ؾ����i��j��Ԫ��ֵ����i��jָ�������Ч���׳��쳣��
//�㷨�ڵ�i������������˳�������Ԫ�����(i,j,0)����Triple
//��==Լ����ȹ��򣨽��Ƚ�i��j���������ҵ�����Ԫ��ֵ�����򷵻�0��
int LinkedMatrix::get(int i, int j)
{
    if (i>=0 && i<this->rows && j>=0 && j<this->columns) 
    {
        Node<Triple>* find = (*this->rowlist[i]).search(Triple(i,j,0));    //��������˳�����
        return find==NULL ? 0 : find->data.value;
    }
    throw out_of_range("����Ԫ�ص��л������Խ���쳣");
}

//���õ�i��j��Ԫ��ֵΪx����i��jָ�������Ч���׳��쳣��
//��x==0����ɾ��(i,j,?)��㣨����У�����x!=0�����ڵ�i������������˳�������Ԫ��(i,j,x)��
//���ҵ����޸Ľ��Ԫ�أ����������
void LinkedMatrix::set(int i, int j, int x) 
{
    if (i>=0 && i<this->rows && j>=0 && j<this->columns) 
    {
        SortedSinglyList<Triple> *list = this->rowlist[i]; //��õ�i����������
        if (x==0) 
            list->removeFirst(Triple(i,j,x));              //��������ɾ��(i,j,?)��㣨����У���˳�����
        else
        {
            Node<Triple>* find = list->search(Triple(i,j,x));//˳������״γ���Ԫ�أ�ִ��Triple��==
            if (find!=NULL)
                find->data.value = x;                      //���ҵ������޸ĸý��Ԫ��
            else list->insert(Triple(i,j,x));  
                //��δ�ҵ��������������������Triple��>Լ������λ�ã���i��j����
        }
    }
    else throw out_of_range("����Ԫ�ص��л������Խ���쳣");
}

void LinkedMatrix::set(Triple e)                           //����Ԫ�����þ���Ԫ��
{
    this->set(e.row, e.column, e.value);
}

//��4�� �������������ԣ��ı�����С
//���þ�������������rows����ָ���������ϴ��򽫾������ݣ�������ԭ����Ԫ�ء�����7.2.2��ͼ���ڽӱ�
void LinkedMatrix::setRowsColumns(int rows, int columns)
{
    if (rows > this->rows)                                 //����ָ���������ϴ�ʱ����������
        for (int i=this->rows; i<rows; i++)
            this->rowlist.insert(new SortedSinglyList<Triple>()); //˳���β���룬Ԫ�ظ�����1���Զ�����
    this->rows = rows;
    this->columns = columns;
}

//ʵ��5