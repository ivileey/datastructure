//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.4   Huffman��
//���������������ù���������
//ʹ��˳���洢

#include "SeqList.h"                                       //˳����ࣨ��2�£�
#include "MyString.h"                                      //�ַ����ࣨ��3�£�
#include "TriElement.h"

class HuffmanTree                                          //Huffman����
{
  private:
    MyString charset;                                      //�ַ��� 
    SeqList<TriElement> huftree;                           //���˳���

    MyString encode(int i);                                //����charset[i]�ַ��ı����ַ���

  public:
    HuffmanTree(int weight[], int n);                      //ָ��Ȩֵ���Ϲ���Huffman��
    void printCode();                                      //��������ַ��ı���
    MyString encode(MyString &text);                       //���룬����ѹ��
    MyString decode(MyString &codestr);                    //���룬���ݽ�ѹ��
};

//����Huffman����weight[]ָ��Ȩֵ���ϣ�nָ�����鳤�ȣ�Ҷ�ӽ������
HuffmanTree::HuffmanTree(int weight[], int n)
   : huftree(2*n-1)                    //����ִ��SeqList<T>(int length)��n��Ҷ�ӽ���Huffman������2n-1�����
{                                      //�˴���ִ��MyString(char *s, int length)����ִ��SeqList<T>(int length)
    for (int i=0; i<n; i++)                                //��ʼ��
    {   this->charset.insert(i,'A'+i);                     //Ĭ���ַ�����'A'��ʼ��n���ַ�
        this->huftree.insert(TriElement(weight[i],-1,-1,-1)); //��ʼ��n��Ҷ�ӽ��
    }
    cout<<"Huffman���Ľ��˳����ֵ��"<<this->huftree<<endl;

    for (int i=0; i<n-1; i++)                              //����n-1��2�Ƚ�㣬ÿ��ѭ������1��2�Ƚ��
    {
        int min1=0x7fffffff, min2=min1, x1=0, x2=0;        //��С�ʹ���СȨֵ�����±�
        for (int j=0; j<n+i; j++)                          //���������޸�ĸ����СȨֵ���
            if (huftree[j].parent==-1 && huftree[j].data<min1)
            {
                min2 = min1;
                x2 = x1;
                min1 = huftree[j].data;                    //min1����СȨֵ
                x1 = j;                                    //x1����СȨֵ����±�
            }
            else if (huftree[j].parent==-1 && huftree[j].data<min2)
                 {
                     min2 = huftree[j].data;               //min2�Ǵ���СȨֵ
                     x2 = j;                               //x2�Ǵ���СȨֵ�����±�
                 }

        huftree[x1].parent = n+i;                          //���ҳ�������Ȩֵ��С�������ϲ�Ϊһ������
        huftree[x2].parent = n+i;        
        huftree.insert(TriElement(huftree[x1].data+huftree[x2].data, -1, x1, x2));   //��ӵ�n+i�����
    }
    cout<<"Huffman���Ľ��˳���"<<this->huftree<<endl;
}

MyString HuffmanTree::encode(int i)                        //����charset[i]�ַ��ı����ַ���
{
    MyString str;                                          //��MyString�ַ�������Huffman����
    int child=i, parent=huftree[child].parent;
    while (parent!=-1)                                     //��Ҷ�������ֱ�������ѭ��
    {
        str += (huftree[parent].left==child) ? '0' : '1';  //���Һ��ӽ�����Ϊ0��1��+=���Ӵ�
        child = parent;
        parent = huftree[child].parent;        
    }
    str.reverse();                                         //��str����ת���õ������ַ���
    return str;
}

void HuffmanTree::printCode()                              //��������ַ��ı���
{
    cout<<"Huffman���룺";
    for (int i=0; i<this->charset.count(); i++)            //�������Ҷ�ӽ���Huffman����
        cout<<this->charset[i]<<" "<<encode(i)<<"��";
    cout<<endl; 
}

MyString HuffmanTree::encode(MyString &text)               //���룬����ѹ�������ؽ�text�������ַ�ѹ���ı����ַ���
{
    MyString codestr;
    for (int i=0; i<text.count(); i++) 
        codestr += encode(text[i]-'A');                    //Ĭ���ַ����Ǵ�A��ʼ��n���ַ�
    return codestr;
}

MyString HuffmanTree::decode(MyString &codestr)            //���룬���ݽ�ѹ�������ؽ����봮str��ѹ��������ַ���
{
    MyString text;
    int node=this->huftree.count()-1;                      //node����һ���Ӹ�����Ҷ�ӵ�·��
    for (int i=0; i<codestr.count(); i++) 
    {
        if (codestr[i]=='0')                               //����0/1�ֱ������Һ�����
            node = huftree[node].left;
        else node = huftree[node].right;
        if (huftree[node].isLeaf())                        //����Ҷ�ӽ��
        {
            text += this->charset[node];                   //���һ���ַ�
            node=this->huftree.count()-1;                  //node�ٴӸ���㿪ʼ
        }
    }
    return text;
}

//void min(T values[], int n, T &min1, T &min2)	//��values�������Сֵ�ʹ���Сֵ
//����<T>�����С���Ϊ����ɢ�б�ͳ���ַ����ִ�����CharCount������??����û��
//˼���⣺����
//�����ı������ң� 