//10.1.3   ̰�ķ�
//����10.3��ʹ����С�ѺͲ��鼯ʵ��Kruskal�㷨��

#include "MinHeap.h"                                       //��С����
#include "TripleComparator.h"                             //Triple����Ƚ�����
#include "UnionFindSet.h"                                  //���鼯��

class MinSpanTree                 //��С�������࣬��һ����Ȩ����ͼ��С�������ı߼��ϼ���С����
{
  public:
    //��Kruskal�㷨�����Ȩ����ͼ����С������������ۣ�ʹ����С�ѺͲ��鼯
    //����vertexCountָ��ͼ�Ķ�������edges����ָ��ͼ�����бߣ�ÿ��ֻ��ʾһ�Σ���edgeCountָ��ͼ�ı���
    //MinSpanTree::MinSpanTree(AbstractGraphint<T> &graph)
    MinSpanTree::MinSpanTree(int vertexCount, Triple edges[], int edgeCount)
    {
        SeqList<Triple> mst(vertexCount-1);                //mst�洢��С�������ı߼��ϣ�����Ϊ������-1
        int cost=0;                                        //��С����������
        Comparator<Triple> *comp = new TripleComparator();//�����Ƚ�������ָ�룬����Ĭ�Ϲ��캯��
        MinHeap<Triple> minheap(edges, edgeCount, comp);  //ʹ����С�Ѵ洢һ��ͼ�����бߣ�����*comp�Ƚ��������ṩ��Ȩֵ�Ƚϱߴ�С�ĺ���

        UnionFindSet ufset(vertexCount);                   //���鼯����
        cout<<"���鼯��"<<ufset<<"��С�ѣ�"<<minheap;
        for (int j=0; j<vertexCount; j++)                  //��ѡ����������-1������
        {
            Triple minedge = minheap.removeMin();         //ɾ����С�ѵĸ�������Ȩֵ��С�ı�
            cout<<"��С��"<<minedge<<"��";
            if (ufset.combine(minedge.row, minedge.column))//����СȨֵ�ߵ������յ����ڵ��������Ϻϲ�
            {
                mst.insert(minedge);                       //�ñ߼�����С������
                cost += minedge.value;                     //������С�������Ĵ���
                cout<<"�����"<<minedge<<"�����鼯��"<<ufset;
            }
        }
        cout<<"��С�������ı߼��ϣ�"<<mst<<"����С����Ϊ"<<cost<<endl;
    }
};

