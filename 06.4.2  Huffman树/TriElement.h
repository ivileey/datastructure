//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.4  Huffman��
//��2�� ���þ�̬��������洢Huffman��

class TriElement                                          //�������ľ�̬��������Ԫ��
{
  public:
    int data, parent, left, right;                        //������ĸ�������Һ��ӽ���±�

    TriElement(int data=0, int parent=-1, int left=-1, int right=-1)
    {
        this->data = data;
        this->parent = parent;
        this->left = left;
        this->right = right;
    }
    friend ostream& operator<<(ostream& out, TriElement &e) //���
    {
        out<<"("<<e.data<<","<<e.parent<<","<<e.left<<","<<e.right<<")";
        return out;
    }
    bool isLeaf()                                          //�ж��Ƿ�Ҷ�ӽ��
    {
        return this->left==-1 && this->right==-1;
    }
    bool operator==(TriElement &e)                         //����==��������Ƚ��Ƿ����
    {
        return this->data==e.data;
    }
};


/*δ�ã���
bool operator<(TriElement &e)                          //����<��������Ƚϴ�С
    {
        return this->data < e.data;
    }

    bool operator<(TriElement &e)                          //����<��������Ƚϴ�С
    {
        return this->parent==-1 && this->data < e.data;
    }

*/

