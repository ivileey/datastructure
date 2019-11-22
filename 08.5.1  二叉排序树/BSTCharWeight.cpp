//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//8.5.1   ����������
//ͳ��text�и��ַ�������ִ���

//#include "MyString.h"                                      //�ַ����ࣨ��3�£�
#include "BinarySortTree.h"                                //������������

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
    void add()                    	   //���ִ�����1
    {
        this->count ++;
    }
    int hashCode()                                         //����ɢ���룬�����ַ�����������ɢ�б��е�λ��
    {
        return (int)this->character; 
    }
    bool operator==(CharCount &cc)                     //Լ����������ȹ����ַ���ͬ
    {
        return this->character==cc.character;
    }
    bool operator!=(CharCount &cc) 
    {
        return this->character!=cc.character;
    }
    bool operator<(CharCount &cc) 
    {
        return this->character<cc.character;
    }
};

void BSTCharWeight(MyString text)                    	   //ͳ��text�и��ַ�������ִ���
{
    BinarySortTree<CharCount> set;                         //����ն���������
    for (int i=0; i<text.count(); i++)                     //����ַ����Ҽ���
    {
        CharCount key(text[i],1);
        CharCount *find = set.search(key);                 //���ң�element���ò��ҵ���Ԫ��
        if (find==NULL) 
            set.insert(key);                               //����
        else  
            find->add();                                   //��Ӧ�ַ�������1
    }   
    cout<<"\""<<text<<"\"�ַ�������ִ�����\n"<<set;
    set.inOrder();
}

int main()
{
    BSTCharWeight("class BinarySortTree");
//    BSTCharWeight("public class");
//    BSTCharWeight("AAAABBBCDDBBAAA");

    system("pause");
    return 0;
}

/*
�������н�����£�
class BinarySortTree�ַ�������ִ�����
�ȸ��������������:  (c,1) (a,2) ( ,1) ��(B,1) ��(S,1) ��(T,1) �ġġ�(l,1) (i,1) (e,2) �ġġ�(s,2) (n,1) ��(r,3) (o,1) �ġġ�(y,1) (t,1) �ġġ�
�и��������������:  ( ,1) (B,1) (S,1) (T,1) (a,2) (c,1) (e,2) (i,1) (l,1) (n,1) (o,1) (r,3) (s,2) (t,1) (y,1) 
����������: (T,1) (S,1) (B,1) ( ,1) (a,2) (e,2) (i,1) (o,1) (r,3) (n,1) (t,1) (y,1) (s,2) (l,1) (c,1) 

public class�ַ�������ִ�����
�ȸ��������������:  (p,1) (b,1) ( ,1) ��(a,1) �ġ�(l,2) (i,1) (c,2) �ġġġ�(u,1) (s,2) �ġġ�
�и��������������:  ( ,1) (a,1) (b,1) (c,2) (i,1) (l,2) (p,1) (s,2) (u,1) 
����������: (a,1) ( ,1) (c,2) (i,1) (l,2) (b,1) (s,2) (u,1) (p,1) 

*/
