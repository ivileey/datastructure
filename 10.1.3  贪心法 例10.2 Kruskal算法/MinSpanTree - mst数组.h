//10.1.3   ̰�ķ�
//����10.3��ʹ����С�ѺͲ��鼯ʵ��Kruskal�㷨��

#include "MinHeap.h"                                       //��С����
#include "ElementComparator.h"                             //Element����Ƚ�����
#include "UnionFindSet.h"                                  //���鼯��

//��С�������࣬�洢һ����Ȩ����ͼ��С�������ı߼��ϣ��Լ���С����
class MinSpanTree 
{
  private: 
    Element *mst;                                          //�洢��С�������ı߼���
    int vertexCount;                                       //������
    int cost;                                              //��С����������

  public:
    MinSpanTree(int vertexCount, Element edges[], int edgeCount);//�����Ȩͼ����С������
    ~MinSpanTree()                                        //��������
    {   
        delete this->mst;
    }
    friend ostream& operator<<(ostream& out, MinSpanTree &mstree); //�����С�������ı߼��Ϻʹ���
};

    //��Kruskal�㷨�����Ȩ����ͼ����С������������ۣ�ʹ����С�ѺͲ��鼯
    //����vertexCountָ����������edges����ָ��ͼ�����бߣ�ÿ��ֻ��ʾһ�Σ���edgeCountָ������
//MinSpanTree::MinSpanTree(AbstractGraphint<T> &graph)
MinSpanTree::MinSpanTree(int vertexCount, Element edges[], int edgeCount)
{
    this->vertexCount = vertexCount;
    this->cost=0;
    Comparator<Element> *comp = new ElementComparator();   //�����Ƚ�������ָ�룬����Ĭ�Ϲ��캯��
    MinHeap<Element> minheap(edges, edgeCount, comp);      //ʹ����С�Ѵ洢һ��ͼ�����бߣ�����*comp�Ƚ��������ṩ��Ȩֵ�Ƚϱߴ�С�ĺ���

    mst = new Element[vertexCount-1];                      //mst�洢��С�������ı߼��ϣ�����Ϊ������-1
    UnionFindSet ufset(vertexCount);                       //���鼯����
    cout<<"���鼯��"<<ufset<<"��С�ѣ�"<<minheap;
    int i=0;                                               //��С�������е�ǰ�ߵ����
    for (int j=0; j<vertexCount; j++)                      //��ѡ����������-1������
    {
        Element minedge = minheap.removeMin();             //ɾ����С�ѵĸ�������Ȩֵ��С�ı�
        cout<<"��С��"<<minedge<<"��";
        if (ufset.combine(minedge.row, minedge.column))    //����СȨֵ�ߵ������յ����ڵ��������Ϻϲ�
        {
            this->mst[i++]=minedge;                        //�ñ߼�����С������
            this->cost+=minedge.value;                     //������С�������Ĵ���
            cout<<"�����"<<minedge<<"�����鼯��"<<ufset;
        }
    }
}

ostream& operator<<(ostream& out, MinSpanTree &mstree)     //�����С�������ı߼��Ϻʹ���
{
    out<<"��С�������ı߼��ϣ�";
    for (int i=0; i<mstree.vertexCount-1; i++)
        out<<mstree.mst[i]<<" ";
    out<<"����С����Ϊ"<<mstree.cost<<endl;
    return out;
}

