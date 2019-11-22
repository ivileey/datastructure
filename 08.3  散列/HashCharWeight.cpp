//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//8.4   ɢ��
//����8.2��ͳ���ı��и��ַ��ĳ��ִ�����Ϊ����Huffman����׼����

#include "MyString.h"                                      //�ַ����ࣨ��3�£�
#include "HashSet.h"                                       //��������ַ����ɢ�б���

class CharCount                                            //�ַ�������ִ���
{
  private:
    char character;                                        //�ַ�
    int count;                                             //���ִ���

  public:
    CharCount(char character=' ', int count=0)
    {
        this->character = character;
        this->count = count;
    }
    friend ostream& operator<<(ostream& out, CharCount &cc) //���Ԫ�أ���ʽΪ��(�ַ�,���ִ���)��
    {
        out<<"("<<cc.character<<","<<cc.count<<")";
        return out;
    }
    void add()                                             //���ִ�����1
    {
        this->count ++;
    }
    int hashCode()                                         //����ɢ���룬���ַ�characterֵת����int
    {
        return (int)this->character; 
    }
    bool operator==(CharCount &cc)                         //Լ��Ԫ����ȹ����ַ���ͬ
    {
        return this->character==cc.character;
    }
    bool operator!=(CharCount &cc) 
    {
        return this->character!=cc.character;
    }
};

//ʹ��ɢ�б���Ϊ�洢�ṹ��ͳ��text�и��ַ�������ִ���
void HashCharWeight(MyString text)
{
    HashSet<CharCount> set(text.count());                  //������ɢ�б�ָ��ɢ�б���������
    for (int i=0; i<text.count(); i++)                     //����ַ����Ҽ���
    {
        CharCount key(text[i],1);
        CharCount *find = set.search(key);                 //����
        if (find==NULL) 
            set.insert(key);                               //����
        else  
            find->add();                                   //��Ӧ�ַ�������1
    }   
    cout<<"\""<<text<<"\"�ַ�������ִ�����\n"<<set;
}

int main()
{
    HashCharWeight("class HashSet");
//    HashCharWeight("public class");   
//    HashCharWeight("AAAABBBCDDBBAAA");

    system("pause");
    return 0;
}

/*
�������н�����£�
"class HashSet"�ַ�������ִ�����
table[0]= ()
table[1]= ((e,1))
table[2]= (( ,1), (H,1))
table[3]= ((S,1))
table[4]= ((h,1))
table[5]= ((s,3))
table[6]= ((t,1))
table[7]= ((a,2))
table[8]= ((l,1))
table[9]= ((c,1))

"class HashSet"�ַ�������ִ�����
table[0]= ((h,1))
table[1]= ()
table[2]= ()
table[3]= ()
table[4]= ((l,1))
table[5]= ((S,1))
table[6]= ((a,2), ( ,1))
table[7]= ((H,1))
table[8]= ((c,1))
table[9]= ()
table[10]= ((e,1))
table[11]= ((s,3))
table[12]= ((t,1))


"public class"�ַ�������ִ�����
table[0]= ()
table[1]= ()
table[2]= ((p,1), ( ,1))
table[3]= ()
table[4]= ()
table[5]= ((i,1), (s,2))
table[6]= ()
table[7]= ((u,1), (a,1))
table[8]= ((b,1), (l,2))
table[9]= ((c,2))


*/
