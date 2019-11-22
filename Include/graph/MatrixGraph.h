//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//7.2.1   ͼ���ڽӾ����ʾ��ʵ��
//ʹ�þ�����Matrix������Ϊ��Ա����

#include "SeqList.h"                                       //˳����ࣨ2.2.2�ڣ�
//#include "Matrix.h"                                      //�����ࣨ��5.1��
#include "Triple.h"                                        //�������Ԫ���࣬��ʾ�ߣ�5.2.2�ڣ�
#include "AbstractGraph.h"                                 //����ͼ�ࣨ7.3�ڣ�

template <class T>
class MatrixGraph : public AbstractGraph<T>                //�ڽӾ����ʾ�Ĵ�Ȩͼ�࣬�̳г���ͼ�� 
{
  private:
    int n;                                                 //������
    SeqList<T> verlist;                                    //˳�����󣬴洢ͼ�Ķ��㼯�ϣ�����Ϊn
    Matrix mat;                                            //������󣬴洢ͼ���ڽӾ���

  public:
    MatrixGraph();                                         //�����ͼ��������Ϊ0
    MatrixGraph(T vertices[], int vertexCount, Triple edges[], int edgeCount);//�Զ��㼯�Ϻͱ߼��Ϲ���ͼ
    ~MatrixGraph(){}                                       //����������Ĭ�ϣ���ʡ�ԣ���ִ��~Matrix()��~SeqList<T>()

    int vertexCount();                                     //���ض�����
    T& getVertex(int i);                                   //���ص�i������Ԫ��
    void setVertex(int i, T x);                            //���õ�i������Ԫ��Ϊx
    int weight(int i, int j);                              //����<vi,vj>�ߵ�Ȩֵ
    int next(int i, int j=-1);                             //����vi��vj�����һ���ڽӶ������
    friend ostream& operator<<<>(ostream& out, MatrixGraph<T> &);    //���ͼ�Ķ��㼯�Ϻ��ڽӾ���
    int insertVertex(T x);                                 //����Ԫ��ֵΪx�Ķ��㣬���ض������
    void insertEdge(int i, int j, int weight);             //����һ��ȨֵΪweight�ıߡ�vi,vj��
    void insertEdge(Triple edge);                          //����һ����
    void removeVertex(int i);                              //ɾ������vi��������ı�
    void removeEdge(int i, int j);                         //ɾ���ߡ�vi,vj��
    void removeEdge(Triple edge);                          //ɾ��һ����

//    void shortestPath();                                   //Floyd�㷨�����Ȩͼÿ�Զ���֮������·��

    //ʵ��7
    bool directed;                                         //��Ա������ȡֵΪtrue��ʾ����ͼ��false����ͼ
    int degree(int i);                                     //���ض���vi�Ķ�
    int indegree(int i);                                   //���ض���vi�����
    int outdegree(int i);                                  //���ض���vi�ĳ���
    int edgeCount();                                       //����ͼ�ı���
    int cost();                                            //���ش�Ȩͼ�Ĵ��� 
    int minWeight();                                       //���رߵ���СȨֵ
    Triple minWeightEgde();                                //������СȨֵ�ı�
    bool isComplete();                                     //�ж��Ƿ���ȫͼ
    MatrixGraph createComplete(T vertices[], int vertexCount); //�Զ��㼯�Ϲ���һ����ȫͼ

    MatrixGraph(MatrixGraph<T> &graph);                    //�������캯��
    MatrixGraph<T>& operator=(MatrixGraph<T> &graph);      //����=��ֵ����������
    bool operator==(MatrixGraph<T> &graph);                //�Ƚ����
    bool isSubgraph(MatrixGraph<T> &graph);                //�ж��Ƿ���ͼ
    bool isSpanSubgraph(MatrixGraph<T> &graph);            //�ж��Ƿ�������ͼ
};
//���У���������i��jָ��ͼ�Ķ����ڶ���˳����е���ţ�0��i��j<��������i��j����i��jָ��������ų�����Χ�����׳����Խ���쳣��

//��2�����������
template <class T>
MatrixGraph<T>::MatrixGraph()                              //�����ͼ��������Ϊ0
{                                                          //�˴�ִ��SeqList<T>()��Matrix()
    this->n = 0;
}

//�Զ��㼯�ͱ߼�����һ��ͼ�������ֱ�ָ�����㼯�����������߼���������
//��vertices==NULL��vertexCount��0�����ͼ��û�ж��㣻��edges==NULL��edgeCount��0����û�б�
template <class T>
MatrixGraph<T>::MatrixGraph(T vertices[], int vertexCount, Triple edges[], int edgeCount)
    : verlist(vertices, vertexCount),              	       //����ִ��SeqList<T>(T value[], int n) 
      mat(vertexCount*2)                    	           //����ִ��Matrix(int rows)���캯��
{ 
    this->n = vertexCount;                                 //������
    for (int i=0; i<n; i++)                                //��ʼ���ڽӾ������Խ���Ԫ��Ϊ0������Ϊ���Ȩֵ
        for (int j=0; j<n; j++)
            this->mat.set(i, j, (i==j ? 0 : MAX_WEIGHT));

    if (vertices!=NULL && vertexCount>0 && edges!=NULL)
        for (int j=0; j<edgeCount; j++)                    //����edges�������е����б�
            this->insertEdge(edges[j]);
}

//��3�� ��ö��������Ժʹ�ȡԪ��
template <class T>
int MatrixGraph<T>::vertexCount()                          //����ͼ�Ķ�������ͬ˳�����
{
    return this->n;                                        //ͬthis->verlist.count()
}

template <class T>
T& MatrixGraph<T>::getVertex(int i)                        //���ص�i������Ԫ��
{
    return this->verlist[i];                               //����˳����i��Ԫ�أ���i��ʾ�����Ч���׳��쳣
}

template <class T>
void MatrixGraph<T>::setVertex(int i, T x)                 //���õ�i������Ԫ��Ϊx
{
    this->verlist[i] = x;                                  //����˳����i��Ԫ��Ϊx����i��ʾ�����Ч���׳��쳣
}

template <class T>
int MatrixGraph<T>::weight(int i, int j)                   //����<vi,vj>�ߵ�Ȩֵ������ͼ����С�����������·�����㷨
{
    return this->mat.get(i,j);                             //���ؾ���(i,j)Ԫ��ֵ����i��j��ʾ�����Ч���׳��쳣
}

//��4�����
template <class T>
ostream& operator<<(ostream& out, MatrixGraph<T> &graph)   //���ͼ�Ķ��㼯�Ϻ��ڽӾ���
{
    out<<"���㼯�ϣ�"<<graph.verlist<<"�ڽӾ���\n";
    for (int i=0; i<graph.n; i++)
    {
        int w;
        for(int j=0; j<graph.n; j++)
            if ((w=graph.weight(i,j))==MatrixGraph<T>::MAX_WEIGHT) 
                out<<setw(6)<<"��";
            else out<<setw(6)<<w;
        out<<"\n";
    }
    return out;
}

//��5�����롢ɾ����
template <class T>
void MatrixGraph<T>::insertEdge(int i, int j, int weight)  //����һ��ȨֵΪweight�ıߡ�vi,vj��
{
    if (i!=j)
    {
        if (weight<=0 || weight>MAX_WEIGHT)                //�ߵ�Ȩֵ�ݴ�
            weight=MAX_WEIGHT;
        this->mat.set(i,j,weight);                         //��i��jָ�������Ч���׳��쳣
    }
    else  throw invalid_argument("�ߵ�������յ������ͬ��ͼ���ܲ���������");
}
template <class T>
void MatrixGraph<T>::insertEdge(Triple edge)               //����һ����
{
    this->insertEdge(edge.row, edge.column, edge.value);
}

template <class T>
void MatrixGraph<T>::removeEdge(int i, int j)              //ɾ���ߡ�vi,vj������i==j���򲻲���
{ 
    if (i!=j)
        this->mat.set(i, j, MAX_WEIGHT);                   //���øñߵ�ȨֵΪ�ޡ���i��jָ�������Ч���׳��쳣
}
template <class T>
void MatrixGraph<T>::removeEdge(Triple edge)               //ɾ����
{ 
    this->removeEdge(edge.row, edge.column);
}

//��6�����붥��
//����Ԫ��ֵΪx�Ķ��㣬���ض�����š����ڽӾ����������㣬����������2��������ԭ����Ԫ�أ����䲿�ֳ�ֵΪ���Ȩֵ�����Խ���ֵΪ0
template <class T>
int MatrixGraph<T>::insertVertex(T x)
{
    this->verlist.insert(x);                               //�ڶ���˳���������һ��Ԫ�أ�˳����Զ�����
    this->n++;                                             //��������1
    if (n > mat.getRows())                                 //���ڽӾ�������������
        this->mat.setRowsColumns(n*2, n*2);                //���������2��������ԭ����Ԫ��
    
    for (int i=0; i<n-1; i++)                              //��ʼ�����ӵ�һ��һ��ֵ�����Խ���ֵΪ0������Ϊ���Ȩֵ
        this->mat.set(i, n-1, MAX_WEIGHT);
    for (int j=0; j<n-1; j++) 
        this->mat.set(n-1, j, MAX_WEIGHT);
    this->mat.set(n-1, n-1, 0);
    return n-1;                                            //���ز��붥�����
}

//��7��ɾ������
template <class T>
void MatrixGraph<T>::removeVertex(int v)                   //ɾ����v�����㼰����������б�
{
    if (v<0 || v>n)                                        //��vָ��������Ŵ����򲻲���
        return;
    this->verlist.remove(v);                               //ɾ��˳����v��Ԫ�أ����ȼ�1
    for (int i=0; i<n; i++)                                //����һ�У�this->nΪԭ������
        for (int j=v+1; j<n; j++)
            this->mat.set(i, j-1, mat.get(i,j));
    for (int i=v+1; i<n; i++)                              //����һ��
        for (int j=0; j<n; j++)
            this->mat.set(i-1, j, mat.get(i,j));
    this->n--;                                             //��������1
}    
  
//��8�� �����һ���ڽӶ���
//����vi��vj�����һ���ڽӶ������ţ���j=-1�����ض���vi�ĵ�һ���ڽӶ������ţ�
//����������һ���ڽӶ��㣬�򷵻�-1������ͼ�ı����㷨
template <class T>
int MatrixGraph<T>::next(int i, int j)
{
    if (i>=0 && i<n && j>=-1 && j<n && i!=j)
        for (int k=j+1; k<n; k++)                    //j=-1ʱ��k��0��ʼѰ����һ���ڽӶ���
            if (weight(i,k)>0 && weight(i,k)<MAX_WEIGHT)
                return k;
    return -1;         
}

//7.5   ���·��
//7.5.2   ÿ�Զ��������·��
/*��ȷ
template <class T>
void MatrixGraph<T>::shortestPath()                      //Floyd�㷨�����Ȩͼÿ�Զ��������·��������
{
    int n=this->vertexCount();                             //������
    Matrix path(n),dist(this->mat);                        //���·�������Ⱦ���dist(mat)ִ��Matrix�������캯�������
    for (int i=0; i<n; i++)                                //��ʼ��dist��path����
        for (int j=0; j<n; j++)
        {
//            int w=this->weight(i,j);
//            dist.set(i,j,w);                               //dist��ֵ��ͼ���ڽӾ���
            path.set(i,j, (i!=j && weight(i,j)<MAX_WEIGHT ? i : -1));
        }
//    cout<<"dist"<<dist<<"path"<<path<<endl;

    for (int k=0; k<n; k++)                                //��vk��Ϊ����·�����м䶥�㣬����·�������Ƿ����
    {
        for (int i=0; i<n; i++)
            if (k!=i)
                for (int j=0; j<n; j++)
                    if (k!=j && i!=j && dist.get(i,j) > dist.get(i,k)+dist.get(k,j))
                    {
                        dist.set(i, j, dist.get(i,k)+dist.get(k,j));
                        path.set(i, j, path.get(k,j));
                    }
//        cout<<"�ö���"<<this->getVertex(k)<<"��Ϊ����·���ľ������㣬"<<"dist"<<dist<<"path"<<path<<endl;
    }

    SeqList<T> pathlist(n-1);                              //˳�����¼���·�������ĸ�����
    for (int i=0; i<n; i++)                                //���ÿ�Զ��������·��
    {
        for (int j=0; j<n; j++)
            if (i!=j)
            {
                 pathlist.removeAll();
                 pathlist.insert(this->getVertex(j));      //˳���������·���յ�vj
                 for (int k=path.get(i,j); k!=-1 && k!=i && k!=j; k=path.get(i,k))  //Ѱ�Ҵ�vi��vj�����·�������Ķ���
                      pathlist.insert(this->getVertex(k)); //˳���β���뾭���Ķ���
                 pathlist.insert(this->getVertex(i));      //���·�����vi
                 pathlist.printPrevious();                 //˳��������

                 if (dist.get(i,j)<MAX_WEIGHT)             //·������
                    cout<<dist.get(i,j)<<"\t";
                 else
                    cout<<"��\t";
            }
        cout<<endl;
    }
}

/*
δʵ��
     public boolean removeVertex(E vertex)             //ɾ������vertex��������ı�
    {
        return this.verlist.remove(vertex);        //ɾ��˳�����ֵΪvertex��Ԫ��
    }
    

����

//ϰ��7
template <class T>
int AdjMatrixGraph<T>::edgeCount()                         //���ر���
{
    int n=this->vertexlist.length();                       //������
    int count=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i!=j && this->adjmatrix[i][j]!=MAX_WEIGHT)
                count++;
    return count;
}

template <class T>
int AdjMatrixGraph<T>::indegree(int i)                     //���ض���vi�����
{
    int n=this->vertexlist.length();                       //������
    int degree=0;
    for (int j=0; j<n; j++)                                //��i���ϸ�Ԫ��֮���Ƕ���vi�����
        if (i!=j && this->adjmatrix[j][i]!=MAX_WEIGHT)
            degree++;
    return degree;
}

template <class T>
int AdjMatrixGraph<T>::outdegree(int i)                    //���ض���vi�ĳ���
{
    int n=this->vertexlist.length();                       //������
    int degree=0;
    for (int j=0; j<n; j++)                                //��i���ϸ�Ԫ��֮���Ƕ���vi�ĳ���
        if (i!=j && this->adjmatrix[i][j]!=MAX_WEIGHT)
            degree++;
    return degree;
}

*/