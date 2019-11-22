//10.1.3   ̰�ķ�
//����10.3��ʹ����С�ѺͲ��鼯ʵ��Kruskal�㷨��
//���鼯

class UnionFindSet                                         //���鼯��
{
  private:
    SeqList<int> parent;                                   //ʹ��˳����ʾ��ָ������

  public:
    //������n��Ԫ�صĲ��鼯���󣬼��ϳ�ʼ״̬�ǰ���n������ɭ�֣��丸ָ������Ԫ��ֵΪ-1��
    //��ʾÿ����ֻ��һ����㡣��������SeqList<int>(int length, T x)���캯��
    UnionFindSet(int n) : parent(n,-1){} 
    friend ostream& operator<<(ostream& out, UnionFindSet &ufs)//������鼯����Ԫ��
    {
        out<<ufs.parent;                                   //���˳�����ʽΪ��(,)��
        return out;
    }
    int findRoot(int x);                                   //���Ҳ�����Ԫ��x�������ĸ��±�
    bool combine(int x, int y);                            //���ϲ�����
    int collapsingFind(int x);                             //���Ҳ�����Ԫ��x�������ĸ��±꣬ͬʱ�����۵�����ѹ��·��
};

int UnionFindSet::findRoot(int i)                          //���Ҳ�����Ԫ��x�������ĸ��±ꡣ�㷨���Ÿ�ָ������Ѱ��ֱ����
{
    while (parent[i]>=0) 
        i = parent[i];
    return i; 
}

    //���Ҳ�����Ԫ��i�������ĸ��±꣬ͬʱ�����۵�����ѹ��·��
    //�㷨���Ÿ�ָ������Ѱ��ֱ����������i����·���ϵ����н�㶼�ĳɸ��ĺ���
int UnionFindSet::collapsingFind(int i)
{
    int root=i;
    while (parent[root]>=0)                                //�ҵ�i�������ĸ�����±�
        root = parent[root];

    while (root!=i && parent[i]!=root)                     //��i���Ǹ��Ҳ��Ǹ��ĺ���ʱ
    {
        int pa = parent[i];
        parent[i]=root;                                    //��i��Ϊroot�ĺ��ӽ��
        i=pa;                                              //���ϵ�i�ĸ����
    }
    return root;                                           //���ظ�����±�
}

    //���ϲ����㣬��i��j����ͬһ�����У���ϲ����i��j���ڵ�������������true�����򷵻�false
    //�㷨���Ȳ��ҷֱ��ý��i��j�������ĸ�����������϶��һ�����ĸ���Ϊ��һ�������ĺ��ӽ��
bool UnionFindSet::combine(int i, int j)
{
//    int rooti=findRoot(i), rootj=findRoot(j);              //rooti��rootj�ֱ���i��j�������ĸ�
    int rooti=collapsingFind(i), rootj=collapsingFind(j);  //rooti��rootj�ֱ���i��j�������ĸ�
    if (rooti!=rootj)                                      //��i��j����ͬһ�����У���ϲ�i��j���ڵ�������
        if (parent[rooti] <= parent[rootj])                //rooti��������������϶�
        {                                                  //��j���ڵ����ϲ���i���ڵ���
            parent[rooti] += parent[rootj];                //��������
            parent[rootj] = rooti;                         //��rootj��Ϊrooti�ĺ��ӣ�����Ԫ��Ϊ������±�
        }
        else                                               //��i���ڵ����ϲ���j���ڵ���
        {
            parent[rootj] += parent[rooti];
            parent[rooti] = rootj;
        }
    return rooti!=rootj;                                   //���غϲ������
}
