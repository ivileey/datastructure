//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//7.2.2   ͼ���ڽӱ��ʾ��ʵ��
//ʹ�þ����еĵ����������Ϊ��Ա����

#include "LinkedMatrix.h"                                  //�еĵ�����洢�ľ����ࣨ��5.2.2�ڣ�������SeqList.h��Triple.h
#include "AbstractGraph.h"                                 //����ͼ�ࣨ��7.3�ڣ�

template <class T>
class AdjListGraph : public AbstractGraph<T>               //�ڽӱ��ʾ�Ĵ�Ȩͼ�࣬�̳г���ͼ�� 
{
  private:
    int n;                                                 //������
    SeqList<T> verlist;                                    //˳�����󣬴洢ͼ�Ķ��㼯�ϣ�����Ϊn
    LinkedMatrix adjlist;                                  //�еĵ�����洢�ľ������ͼ���ڽӱ�

  public:
    AdjListGraph();                                        //�����ͼ��������Ϊ0
    AdjListGraph(T vertices[], int vertexCount, Triple edges[], int edgeCount);//�Զ��㼯�ͱ߼�����һ��ͼ
    ~AdjListGraph(){}                                      //����������Ĭ�ϣ���ʡ�ԣ���ִ��~LinkedMatrix()��~SeqList<T>()

    int vertexCount();                                     //���ض�����
    T& getVertex(int i);                                   //���ص�i������Ԫ��
    void setVertex(int i, T x);                            //���õ�i������Ԫ��Ϊx
    int weight(int i, int j);                              //����<vi,vj>�ߵ�Ȩֵ
    int next(int i, int j=-1);                             //����vi��vj�����һ���ڽӶ������
    friend ostream& operator<<<>(ostream& out, AdjListGraph<T>&);    //���ͼ�Ķ��㼯�Ϻ��ڽӱ�
    int insertVertex(T x);                                 //����Ԫ��ֵΪx�Ķ��㣬���ض������
    void insertEdge(int i, int j, int weight);        	   //����һ��ȨֵΪweight�ıߡ�vi,vj��
    void insertEdge(Triple edge);                          //����һ����
    void removeVertex(int i);                   	       //ɾ������vi��������ı�
    void removeEdge(int i, int j);               	       //ɾ���ߡ�vi,vj��
    void removeEdge(Triple edge);                          //ɾ����
}; 

//��1�� ͼ�Ĺ��캯��
template <class T>
AdjListGraph<T>::AdjListGraph()                            //�����ͼ��������Ϊ0
{                                                          //�˴�ִ��SeqList<T>()��LinkedMatrix()
    this->n = 0;
}

//�Զ��㼯�ͱ߼�����һ��ͼ�������ֱ�ָ�����㼯�����������߼�������
template <class T>
AdjListGraph<T>::AdjListGraph(T vertices[], int vertexCount, Triple edges[], int edgeCount)
    : verlist(vertices, vertexCount),                      //����ִ��SeqList<T>(T value[], int n)
      adjlist(vertexCount,vertexCount,edges,edgeCount)     //����ִ��LinkedMatrix(int rows, int columns, Triple elem[], int n)
{
    this->n = vertexCount;
}

//��ȡԪ�غ����ԣ�����3����������ͬͼ���ڽӾ���
template <class T>
int AdjListGraph<T>::vertexCount()                         //����ͼ�Ķ�������ͬ˳�����
{
    return this->n;                                        //ͬthis->verlist.count()
}

template <class T>
T& AdjListGraph<T>::getVertex(int i)                       //���ص�i������Ԫ��
{
    return this->verlist[i];                               //����˳����i��Ԫ�أ���iָ�������Ч���׳��쳣
}

template <class T>
void AdjListGraph<T>::setVertex(int i, T x)                //���õ�i������Ԫ��Ϊx
{
    this->verlist[i] = x;                                  //����˳����i��Ԫ��Ϊx����iָ�������Ч���׳��쳣
}

//��2�����
template <class T>
ostream& operator<<(ostream& out, AdjListGraph<T> &graph)   //���ͼ�Ķ��㼯�Ϻ��ڽӱ�
{
    out<<"���㼯�ϣ�"<<graph.verlist<<"�ڽӱ�\n"<<graph.adjlist;
    return out;
}

//��2�����롢ɾ����
template <class T>
void AdjListGraph<T>::insertEdge(int i, int j, int weight) //����һ��ȨֵΪweight�ıߡ�vi,vj��
{
    if (i!=j)
    {
        if (weight<=0 || weight>=MAX_WEIGHT)      	       //�ߵ�Ȩֵ�ݴ�
            weight=0;
        this->adjlist.set(i,j,weight);                     //���õ�i���ߵ�������<vi,vj>�ߵ�Ȩֵ
                      //��i��j��Чʱ����0<weight<�ޣ�����߻��滻�ߵ�Ȩֵ����weight==0��ɾ���ñ�
    }
    else  throw invalid_argument("�ߵ�������յ������ͬ��ͼ���ܲ���������");   //�׳���Ч�����쳣
}
template <class T>
void AdjListGraph<T>::insertEdge(Triple edge)              //����һ���ߡ�ͬͼ���ڽӾ���
{
    this->insertEdge(edge.row, edge.column, edge.value);
}

template <class T>
void AdjListGraph<T>::removeEdge(int i, int j)             //ɾ���ߡ�vi,vj������i==j���򲻲���
{ 
    if (i!=j)
        this->adjlist.set(i,j,0);                          //���þ���Ԫ��Ϊ0����������������ɾ����vi,vj����㡣��i��jָ��������Ŵ������׳��쳣��
}
template <class T>
void AdjListGraph<T>::removeEdge(Triple edge)              //ɾ���ߡ�ͬͼ���ڽӾ���
{ 
    this->removeEdge(edge.row, edge.column);
}

//��4�����붥��
template <class T>
int AdjListGraph<T>::insertVertex(T x)                     //����Ԫ��ֵΪx�Ķ��㣬���ض������
{
    this->verlist.insert(x);                               //����˳���β����x�����ȼ�1���Զ�����
    this->n++;                                             //��������1
    this->adjlist.setRowsColumns(n, n);                    //�����ڽӱ��һ�У�������ָ��˳����Զ�����
    return this->n-1;                                      //���ز��붥�����
}

//��5��ɾ������
template <class T>
void AdjListGraph<T>::removeVertex(int v)                  //ɾ����v�����㼰������ı�
{
    if (v>=0 && v<this->n)
    {
        this->verlist.remove(v);                           //ɾ������˳����v��Ԫ�أ����ȼ�1
        //�����ڵ�v������ĵ�������ɾ����vΪ�յ�����б�
        SortedSinglyList<Triple> *list = this->adjlist.rowlist[v];  //��õ�v����������
        for (Node<Triple>* p=list->head->next;  p!=NULL; p=p->next) //������v���ߵ�����
            this->removeEdge(p->data.symmetry());          //ɾ����p���ԳƵıߣ���ɾ����vΪ�յ�ı�

        this->n--;                                         //��������1
        this->adjlist.rowlist.remove(v);                   //ɾ����ָ������ĵ�v��������
        list->~SortedSinglyList<Triple>();                 //������v����������
        this->adjlist.setRowsColumns(n, n);                //���þ�������������һ��

        for (int i=0; i<n; i++)                            //����ÿ���ߵ�������>v�Ķ�����ż�1
        {
            list = this->adjlist.rowlist[i]; 
            for (Node<Triple>* p=list->head->next; p!=NULL; p=p->next)
            {
                if (p->data.row > v)
                    p->data.row--; 
                if (p->data.column > v)
                    p->data.column--;
            }
        }
    }
    else  throw out_of_range("������Ŵ��󣬲���ɾ�����㡣");
}
 
//��5�� �����һ���ڽӶ���ͱߵ�Ȩֵ����
//����vi��vj�����һ���ڽӶ�����ţ���j=-1�����ض���vi�ĵ�һ���ڽӶ������ţ�
//����������һ���ڽӶ��㣬�򷵻�-1������ͼ�ı����㷨
template <class T>
int AdjListGraph<T>::next(int i, int j)
{
    if (i>=0 && i<n && j>=-1 && j<n && i!=j)
    {                                                      //�����ڵ�i�������������в����յ����>j�ı�
        SortedSinglyList<Triple> *list = this->adjlist.rowlist[i];
        for (Node<Triple> *p = list->head->next;  p!=NULL;  p = p->next)
            if (p->data.column > j)
                return p->data.column;                     //������һ���ڽӶ�������
    }
    return -1;                                             //û����һ���ڽӶ���
}

template <class T>
int AdjListGraph<T>::weight(int i, int j)                  //����<vi,vj>�ߵ�Ȩֵ������ͼ����С�����������·�����㷨
{
    if (i==j)
        return 0;
    int w = this->adjlist.get(i,j);                        //���ؾ���(i,j)Ԫ��ֵ����i��jָ�������Ч���׳��쳣
    return w!=0 ? w : MAX_WEIGHT;                          //������0��ʾû�бߣ���ߵ�Ȩֵ���ء�
}
/*
δʵ��
     public boolean removeVertex(E vertex)             //ɾ������vertex��������ı�
    {
        return this.verlist.remove(vertex);        //ɾ��˳�����ֵΪvertex��Ԫ��
    }
    
*/

