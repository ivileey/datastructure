//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.4   Huffman��
//���������������ù���������
//���壬ʹ������

#include "MyString.h"                                      //�ַ����ࣨ����3�£�
#include "TriElement.h"

class HuffmanTree                                          //Huffman����
{
  private:
    int leafNum;                                           //Ҷ�ӽ�����
    TriElement *huftree;                                   //�������
    MyString *hufcodes;                                    //Huffman�������飬Ԫ�����ַ���

    void getHuffmanCode();                                 //���Huffman����

  public:
    HuffmanTree(int weight[], int n);                      //����ָ��Ȩֵ���ϵ�Huffman��
    ~HuffmanTree();
    void print();
};

//����Huffman����weight����ָ��Ȩֵ���ϣ�nָ��Ҷ�ӽ�����������鳤��
HuffmanTree::HuffmanTree(int weight[], int n)
{
    this->leafNum = n;
    this->huftree = new TriElement[2*n-1];                 //n��Ҷ�ӽ���Huffman������2n-1�����//TriElement�����࣬����TriElement()
    for (int i=0; i<n; i++)                                //��������ʼ����n��Ҷ�ӽ��
    {
        this->huftree[i].data = weight[i];
        huftree[i].parent = huftree[i].left = huftree[i].right = -1;
    }

    for (int i=0; i<n-1; i++)                              //����n-1��2�Ƚ�㣬ÿ��ѭ������1��2�Ƚ��
    {
        int min1, min2, x1, x2;
        min1 = min2 = 0x7fffffff;                          //ѡ����С�ʹ���СȨֵ����ֵΪ�������ֵ��16���ƣ�
        x1 = x2 = -1;                                      //��¼�����޸�ĸ����СȨֵ����±�
        for (int j=0; j<n+i; j++)                          //���������޸�ĸ����СȨֵ���
            if (huftree[j].data<min1 && huftree[j].parent==-1)
            {
                min2 = min1;
                x2 = x1;
                min1 = huftree[j].data;                    //min1������СȨֵ
                x1 = j;                                    //x1������СȨֵ�����±�
            }
            else if (huftree[j].data<min2 && huftree[j].parent==-1)
                 {
                     min2 = huftree[j].data;               //min2���´�СȨֵ
                     x2 = j;                               //x2���´�СȨֵ�����±�
                 }

        huftree[x1].parent = n+i;                          //���ҳ�������Ȩֵ��С�������ϲ�Ϊһ������
        huftree[x2].parent = n+i;
        huftree[n+i].data = huftree[x1].data+huftree[x2].data;
        huftree[n+i].parent = -1;
        huftree[n+i].left = x1;
        huftree[n+i].right = x2;
    }
    getHuffmanCode();                                      //Huffman�������飬Ԫ�����ַ���
}

//��huftree��������õ�ǰHuffman����Huffman���룬hufcodes������MyString�ַ�����ʽ����Huffman����
void HuffmanTree::getHuffmanCode()
{
    this->hufcodes = new MyString[this->leafNum];          //�������飬һ���ַ�����ʾһ�����룬ִ��leafNum��MyString()
    for (int i=0; i<this->leafNum; i++)                    //��leafNum��Ҷ�ӽ���Huffman����
    {
        int child=i, parent=this->huftree[child].parent;
        while (parent!=-1)                                 //��Ҷ�������ֱ�������ѭ��
        {
            this->hufcodes[i] += (huftree[parent].left==child) ? '0' : '1'; //���Һ��ӽ�����Ϊ0��1��+=��MyString�ַ�����������
            child = parent;
            parent = this->huftree[child].parent;        
        }
        this->hufcodes[i].reverse();                       //����ǰ����ת���õ������ַ���
    }
}

void HuffmanTree::print()
{
    cout<<"Huffman���Ľ�����飺\n";
    int i;
    for (i=0; i<this->leafNum*2-1; i++)
        cout<<"��"<<i<<"��  "<<huftree[i].data<<", "<<huftree[i].parent<<", "<<huftree[i].left<<", "<<huftree[i].right<<endl;

    cout<<"\nHuffman���룺\n";
    for (i=0; i<this->leafNum; i++)
        cout<<this->hufcodes[i]<<endl;
    cout<<endl;
}

HuffmanTree::~HuffmanTree()
{
    delete[] this->huftree;
    delete[] this->hufcodes;
}

/*??
//    byte* encode(char *str, char *letter, int &len);               //���룬����ѹ��
//    char* decode(char *letter, byte codes[], int n);             //���룬���ݽ�ѹ��
int indexOf(char *str, char ch)                   //�����ַ�ch���ַ���str�е����
{
    int i=0;
    while (letter[i]!='\0' && letter[i]!=ch)
        i++;
    if (letter[i]!='\0')
        return i;
    else
        return -1;
}

byte* HuffmanTree::encode(char *str, char *letter, int bitCount)  //���룬����ѹ��
{
    char *codes=new char[100];
    for (int i=0; str[i]!='\0'; i++)
    {
        int j=indexOf(letter, str[i]);           //��str[i]�ַ���letter�ַ����е����
        hufcodes[j]                              // str[i]�ַ�r    ����

    }
    int 
    codes[j]
}

char* HuffmanTree::decode(char *letter, char *codes)             //���룬���ݽ�ѹ��
{
}

  */