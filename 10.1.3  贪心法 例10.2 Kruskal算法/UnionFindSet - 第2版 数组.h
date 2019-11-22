//10.1.3   ̰�ķ�
//����10.3��ʹ����С�ѺͲ��鼯ʵ��Kruskal�㷨��
//���鼯

//#include <iostream>
//using namespace std;
class UnionFindSet                                         //���鼯��
{
  private:
    int *parent;                                           //��ָ������
    int len;                                               //��С��Ԫ�ظ�����������������

  public:
    //������n��Ԫ�صĲ��鼯���󣬼��ϳ�ʼ״̬�ǰ���n������ɭ�֣��丸ָ������Ԫ��ֵΪ-1����ʾÿ����ֻ��һ�����
    UnionFindSet::UnionFindSet(int n)                        
    {
        this->len = n;
        this->parent = new int[n];
        for (int i=0; i<n; i++)
            this->parent[i]=-1;
    }
    ~UnionFindSet()                                        //��������
    {
        delete this->parent;
    }
    int find(int x);                                       //���Ҳ�����Ԫ��x�������ĸ��±�
    bool combine(int x, int y);                            //���ϲ�����
    friend ostream& operator<<(ostream& out, UnionFindSet &ufs)//������鼯����Ԫ�أ���ʽΪ��(,)��
    {
        out<<"(";
        if (ufs.len>0)
            out<<ufs.parent[0];
        for (int i=1; i<ufs.len; i++)
            out<<", "<<ufs.parent[i];
        out<<") "<<endl;
        return out;
    }
    int collapsingFind(int x);                             //���Ҳ�����Ԫ��x�������ĸ��±꣬ͬʱ�����۵�����ѹ��·��
};


int UnionFindSet::find(int x)                              //���Ҳ�����Ԫ��x�������ĸ��±ꡣ�㷨���Ÿ�ָ������Ѱ��ֱ����
{
    while (this->parent[x]>=0)                             //��x���Ǹ�
        x=this->parent[x];                              //�ҵ�������±�
    return x;                                          //���ظ�����±�
}
    //���Ҳ�����Ԫ��x�������ĸ��±꣬ͬʱ�����۵�����ѹ��·��
    //�㷨���Ÿ�ָ������Ѱ��ֱ����������x����·���ϵ����н�㶼�ĳɸ��ĺ���
int UnionFindSet::collapsingFind(int x)
{
    int root=x;
    while (this->parent[root]>=0)                       //��x���Ǹ�
        root=this->parent[root];                        //�ҵ�������±�
    while (root!=x && parent[x]!=root)                 //��x���Ǹ���x���Ǹ��ĺ���ʱ
    {
        int pa = parent[x];
        parent[x]=root;                                //��x��Ϊroot�ĺ��ӽ��
        x=pa;                                          //���ϵ�x�ĸ����
    }
    return root;                                       //���ظ�����±�
}
    
    //���ϲ����㣬��x��y����ͬһ�����У���ϲ����x��y���ڵ�������������true�����򷵻�false
    //�㷨���Ȳ��Ҳ��ֱ𷵻ؽ��x��y�������ĸ������������϶��һ������Ϊ��һ�����ĺ��ӽ��
bool UnionFindSet::combine(int x, int y)
{
//  int rootx=find(x), rooty=find(y);                  //rootx��rooty�ֱ��ý��x��y�������ĸ�
    int rootx=collapsingFind(x), rooty=collapsingFind(y);                  //rootx��rooty�ֱ��ý��x��y�������ĸ�
    if (rootx!=rooty)                                  //x��y����ͬһ������
        if (parent[rootx]<=parent[rooty])              //rootx���������������϶�
        {
            this->parent[rootx]+=this->parent[rooty];    //���������
            this->parent[rooty]=rootx;                  //��rooty��Ϊrootx�ĺ��ӽ�㣬����Ԫ��ֵָ�򸸽���±�
        }
        else
        {
            this->parent[rooty]+=this->parent[rootx];
            this->parent[rootx]=rooty;                  //��rootx��Ϊrooty�ĺ��ӽ��
        }
    return rootx!=rooty;                               //���غϲ����״̬
}
 /*   
int main()
{
        //������p263ͼ6.4
    UnionFindSet ufset(10);          //���鼯
    ufset.combine(0,6);
    ufset.combine(0,7);
    ufset.combine(0,8);
    ufset.combine(1,4);
    ufset.combine(1,9);        
    cout<<"���鼯��"<<ufset;
    ufset.combine(0,1);
    cout<<"���鼯��"<<ufset;

    system("pause");
    return 0;
}   
/*
�������н�����£�
���鼯��(-4, -3, -1, -1, 1, -1, 0, 0, 0, 1) 
���鼯��(-7, 0, -1, -1, 1, -1, 0, 0, 0, 1) 
*/

