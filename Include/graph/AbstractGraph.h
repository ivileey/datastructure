//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//7.3   ͼ�ı���
//����ͨͼ������������������͹��������������
//7.4   ��С������
//7.5   ���·��

//#include "SeqList.h"                                       //˳����ࣨ��2.2.2�ڣ�
#include "SeqQueue.h"                                      //˳��ѭ��������
#include "Matrix.h"                                        //�����ࣨ����5.1��

template <class T>
class AbstractGraph                                        //����ͼ�� 
{
  protected:
    const static int MAX_WEIGHT = 9999;//0x7fffffff;              //���Ȩֵ����ʾ�����ޣ�
    virtual int vertexCount()=0;                           //���ض����������麯����������ʵ��
    virtual T& getVertex(int i)=0;                         //���ض���viԪ������
    virtual int weight(int i, int j)=0;                    //����<vi,vj>�ߵ�Ȩֵ
    virtual int next(int i, int j=-1)=0;                   //���ض���v��w�����һ���ڽӶ�����ţ�j=-1�����ص�0���ڽӶ������

  public:
    void DFSTraverse(int i);                               //����ͨͼ��������������������Ӷ���vi����
    void BFSTraverse(int i);                               //����ͨͼ�Ĺ�����������������Ӷ���vi����

    void minSpanTree();                                    //Prim�㷨�������Ȩ����ͼ����С������ 
    void shortestPath(int i);                              //Dijkstra�㷨�����Ȩͼ����vi�ĵ�Դ���·��
    void shortestPath();                                   //Floyd�㷨�����Ȩͼÿ�Զ���֮������·��

  private:
    void depthfs(int i, SeqList<bool> &visited);           //�Ӷ���vi�������������������һ����ͨ����
    void breadthfs(int i, SeqList<bool> &visited);         //�Ӷ���vi�������������������һ����ͨ����

    //ʵ��7
  public:
    int pathLength(int i, int j);                          //���شӶ���vi��vj��·�����ȣ���vi=vjʱ������0����vi��vj����ͨʱ������-1
    void printPathAll(int i, int j);                       //�������֮�������·������·������
    void printPathAll(int i);                              //����Ӷ���vi���������б���·�������û��ݷ�
    bool stronglyConnected();                              //�ж�һ���ޣ��У���ͼ�Ƿ�Ϊ��ǿ����ͨͼ
    bool isTree();                                         //�ж�һ������ͼ�Ƿ�Ϊһ����
    bool isCyclePath(int vertexs[]);                       //�ж��ɶ������б�ʾ��һ��·���Ƿ�Ϊ��·
};
//���У�����i��jָ��ͼ�Ķ�����ţ�0��i��j<��������i��j����i��jָ��������ų�����Χ�����׳����Խ���쳣��


template <class T>
void AbstractGraph<T>::DFSTraverse(int i)                  //����ͨͼ��������������������Ӷ���vi����
{
    int n=this->vertexCount();                             //������    
    if (i>=0 && i<n)
    {    
/*        bool *visited = new bool[n];                       //���ʱ������
        for (int j=0; j<n; j++)                            //���ñ��
            visited[j]=false;*/
        SeqList<bool> visited(n,false);                     //���ʱ��˳���n��Ԫ�أ���ֵΪfalse��δ���ʣ�
        int j=i;
        do
        {   if (!visited[j])                               //������vjδ������
            {   cout<<"{ ";
                depthfs(j, visited);                       //��vj�������������������һ����ͨ����
                cout<<"} ";
            }
            j = (j+1) % n;                                 //��������ͨ������Ѱ��δ�����ʶ���
        } while (j!=i);
        cout<<endl;
//        delete[] visited;
    }
    else  throw out_of_range("������Ŵ��󣬲��ܱ���ͼ��");
}

//�Ӷ���vi�������������������һ����ͨ�������ݹ��㷨
template <class T>
void AbstractGraph<T>::depthfs(int i, SeqList<bool> &visited)
{ 
    cout<<this->getVertex(i)<<" ";                         //���ʶ���vi
    visited[i] = true;                                     //���ѷ��ʱ��
    for (int j=next(i); j!=-1;  j=next(i,j))               //j���λ��vi�������ڽӶ���
        if (!visited[j])                                   //���ڽӶ���vjδ������
            depthfs(j, visited);                           //��vj������������������������ݹ����
}

template <class T>
void AbstractGraph<T>::BFSTraverse(int i)                  //����ͨͼ�Ĺ�����������������Ӷ���vi����
{
    int n=this->vertexCount();                             //������
    if (i>=0 && i<n)
    {    
        SeqList<bool> visited(n,false);                    //���ʱ��˳���n��Ԫ��ֵΪfalse��δ���ʣ�
        int j=i;
        do
        {   if (!visited[j])                               //������vjδ������
            {   cout<<"{ ";
                breadthfs(j, visited);                     //�Ӷ���vj�������������������һ����ͨ����
                cout<<"} ";
            }
            j = (j+1) % n;                                 //��������ͨ������Ѱ��δ�����ʶ���
        } while (j!=i);
        cout<<endl;
    }
    else  throw out_of_range("������Ŵ��󣬲��ܱ���ͼ��");
}
    
template <class T>
void AbstractGraph<T>::breadthfs(int i, SeqList<bool> &visited)    //�Ӷ���vi�������������������һ����ͨ����
{
    SeqQueue<int> que;                                     //�����ն���
    cout<<this->getVertex(i)<<" ";
    visited[i] = true;
    que.enqueue(i);                                        //���ʹ��Ķ���vi������
    while (!que.empty())                                 //�����в���ʱѭ��
    {
        i = que.dequeue();                                 //����
        for (int j=next(i,-1); j!=-1;  j=next(i,j))        //j���λ��vi�������ڽӶ���
            if (!visited[j])                               //������vjδ���ʹ�
            {
                cout<<this->getVertex(j)<<" ";             //���ʶ���
                visited[j] = true;
                que.enqueue(j);                            //���ʹ��Ķ���vj������
            }
    }
}

//7.4.2   ��С�������Ĺ����㷨Prim û����
int indexMinWeight(Triple egdes[], int start, int end)     //����СȨֵ�ı�λ��
{
    int min=start;                                         //min��ס��ǰ��Сֵλ��
    if (start>=0 && end>=0 && start<=end)
    {
        int minweight = egdes[start].value;                //����СȨֵ
        for (int i=start+1; i<end; i++)                    //Ѱ�ҵ�ǰ��СȨֵ�ıߵĶ���
            if (egdes[i].value < minweight)
            {
                minweight = egdes[i].value;                //������СȨֵ
                min = i;                                   //���浱ǰ��СȨֵ�ߵ��յ����
            }
    }
    return min;
}
//������ģ�壬��ΪT������<���������Ϊ�Ƚ����У����Ƚϱߵ�Ȩֵ����ʱ��Ҫ���ֱȽϹ���

//Prim�㷨�������Ȩ����ͼ����С�������������С�������ĸ��߼�����
template <class T>
void AbstractGraph<T>::minSpanTree()
{
    int n=this->vertexCount(), i=0;
    SeqList<Triple> mst(n-1);                              //mst�洢MST�ı߼��ϣ�����Ϊ������-1
    for (int j=i; j<n-1; j++)                              //��ʼ��mst����v0��������MST
        mst.insert(Triple(i, j+1, weight(i,j+1)));         //���涥��v0������������ı�

    for (i=0; i<n-1; i++)                                  //ѡ������MST��n-1����
    {
//        cout<<"mst���飺";
//        print(mst,n-1);                                    //��ʾmst����ı仯����
//       int min = indexMinWeight(mst,i,n-1);                  
        int  minweight=MAX_WEIGHT, min=i;                  //����СȨֵ�ıߣ���ס��СȨֵ���ߵ��±�
        for (int j=i; j<n-1; j++)
            if (mst[j].value < minweight)                  //�����ڸ�Сֵ���������Сֵ����               
            {
                minweight = mst[j].value;
                min = j; 
            }
        Triple temp = mst[i];                             //������СȨֵ�ıߣ���ʾ�ñ߼���TE����
        mst[i] = mst[min];
        mst[min] = temp;

        int tv = mst[i].column;                            //�ղ���TV�Ķ���
        for (int j=i+1; j<n-1; j++)                        //����mst[i+1]�����Ԫ��ΪȨֵ��С�ı�
        {
            int v = mst[j].column;                         //ԭ����V-TV�е��յ�
            if (weight(tv,v)<mst[j].value)                 //����Ȩֵ��С�ı�(tv,v)������(tv,v)���滻ԭ��
            {
                mst[j].value = weight(tv,v);
                mst[j].row = tv;
            }
        }
    }
    cout<<"��С�������ı߼��ϣ�";
    int mincost=0;
    for (i=0; i<n-1; i++)                                  //�����С�������ı߼��Ϻʹ��� 
    {
        cout<<mst[i]<<" ";
        mincost += mst[i].value;
    }
    cout<<"����С����Ϊ"<<mincost<<endl;
}

template <class T>
void print(T table[], int n)                               //��������n��Ԫ��
{
    for (int i=0; i<n; i++)
        cout<<table[i]<<" ";
    cout<<endl;
}

template <class T>
void AbstractGraph<T>::shortestPath(int i)                 //Dijkstra�㷨�����Ȩͼ�ж���vi�ĵ�Դ���·��
{
    int n=this->vertexCount();                             //������
    if (i<0 || i>=n)
        return;

    SeqList<int> dist(n);                                  //���·������
    SeqList<int> path(n);                                  //���·�����յ��ǰһ������
    for (int j=0; j<n; j++)                                //��ʼ��dist��path˳���
    {
        dist.insert(weight(i,j));
        path.insert((j!=i && dist[j]<MAX_WEIGHT) ? i : -1);
    }
    SeqList<bool> s(n,false);                              //��������·���Ķ��㼯�ϣ�n��Ԫ��ֵΪfalse
    s[i] = true;                                           //Դ��vi�ڼ���S�еı��
    
    for (int j=(i+1)% n; j!=i; j=(j+1)% n)                 //Ѱ�Ҵ�vi������vj�����·����vj��V-S������
    {
//        cout<<"\ns����";   print(s, n);
//        cout<<"path����";  print(path, n);
//        cout<<"dist����";  print(dist, n);
        int mindist=MAX_WEIGHT, min=0;
        for (int k=0; k<n; k++)                            //��·��������Сֵ�����±�
            if (!s[k] && dist[k]<mindist)
            {
                mindist = dist[k];                         //��ǰ·��������Сֵ
                min = k;                                   //��ǰ·��������Сֵ�±�
            }
        if (mindist==MAX_WEIGHT)                           //��û���������·��������������Է���ͨͼ�Ǳ����
            break; 

        s[min] = true;                                     //ȷ��һ�����·��(vi,min)���յ�min���뼯��S
        for (int k=0; k<n; k++)                            //������vi��V-S��������������·��������
            if(!s[k] && weight(min,k)<MAX_WEIGHT && dist[min]+weight(min,k)<dist[k])
            {
                dist[k] = dist[min] + weight(min,k);       //�ø���·���滻
                path[k] = min;                             //���·������min����
            }    
    }

//        cout<<"path����";  print(path, n);
//        cout<<"dist����";  print(dist, n);
    SeqList<T> pathlist(n-1);                              //˳�����¼���·�������ĸ�����
    for (int j=0; j<n; j++)                                //����Ӷ���vi��������������·��
        if (j!=i)    
        {
            pathlist.removeAll();
            pathlist.insert(this->getVertex(j));           //˳���������·���յ�vj
            for (int k=path[j]; k!=-1 && k!=i; k=path[k])  //Ѱ�Ҵ�vi��vj�����·��
                pathlist.insert(this->getVertex(k));       //˳���β���뾭���Ķ���
            pathlist.insert(this->getVertex(i));           //���·�����vi
            pathlist.printPrevious();                      //˳��������
 
            if (dist[j]<MAX_WEIGHT)                        //·������
                cout<<" "<<dist[j]<<"\t";
            else cout<<" ��\t";
        }
    cout<<endl;
}

template <class T>
void AbstractGraph<T>::shortestPath()                      //Floyd�㷨�����Ȩͼÿ�Զ��������·��������
{
    int n=this->vertexCount();                             //������
    Matrix path(n),dist(n);                                //���·�������Ⱦ���
    for (int i=0; i<n; i++)                                //��ʼ��dist��path����
        for (int j=0; j<n; j++)
        {
            int w=this->weight(i,j);
            dist.set(i,j,w);                               //dist��ֵ��ͼ���ڽӾ���
            path.set(i,j, (i!=j && w<MAX_WEIGHT ? i : -1));
        }
    cout<<"dist"<<dist<<"path"<<path<<endl;

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
        cout<<"�ö���"<<this->getVertex(k)<<"��Ϊ����·���ľ������㣬"<<"dist"<<dist<<"path"<<path<<endl;
    }

    SeqList<T> pathlist(n-1);                              //˳�����¼���·�������ĸ�����
    for (int i=0; i<n; i++)                                //���ÿ�Զ��������·��
    {
        for (int j=0; j<n; j++)                            //Ѱ�Ҵ�vi��vj���·�������Ķ���
            if (i!=j)
            {
                 pathlist.removeAll();
                 pathlist.insert(this->getVertex(j));      //˳���������·���յ�vj
                 for (int k=path.get(i,j); k!=-1 && k!=i && k!=j; k=path.get(i,k))  
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

