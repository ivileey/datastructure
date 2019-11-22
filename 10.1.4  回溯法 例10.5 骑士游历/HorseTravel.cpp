//10.1.4   ���ݷ�
//����10.5��  Ԥ���㷨����ʿ�������⡣

#include "Matrix.h"                                        //�����ࣨ����5.1��

class Point                                                //����һ������
{
  public: 
    int x,y;                                               //�С�������

    Point(int x, int y)                                    //���캯��
    {
        this->x=x;
        this->y=y;
    }
    friend ostream& operator<<(ostream &out, Point &p)     //���
    {
        out<<"("<<p.x<<","<<p.y<<")";
        return out;
    } 
}; 


class HorseTravel                                          //Ԥ���㷨����ʿ��������
{
  private:
    int n;                                                 //���̴�С
    Matrix chessboard;                                     //�þ����ʾ���̲����������һ����

    int select(Point p);                                   //ѡ��p�񵽴���һ��ķ���
    Point go(Point p, int direction);                      //����p��direction�������һ��
    bool isValid(Point p);                                 //�ж�p�Ƿ�����������δ��ռ���

  public:
    HorseTravel(int n, int x, int y);
};

HorseTravel::HorseTravel(int n, int x, int y)              //���캯����nָ�����̴�С��x��yָ����ʼλ��
    : chessboard(n,n,0)                                    //����ִ��Matrix(int rows, int columns, int x)
{
    if (n<5 || n>8)                                        //�������̴�СΪ5��8
        throw out_of_range("����nָ�����̴�С����5��8��Χ");
    this->n = n;
    Point p(x,y);                                          //��ǰ���(x,y)��ʼ����
    int count=1, direction=1;                              //count��¼������diretion��ʾ8������
    while (count<=n*n && direction!=0)
    {
        chessboard.set(p.x, p.y, count);                   //����p���ֵΪcount
        cout<<"��"<<count<<"��  ";
        direction = select(p);                             //Ԥ����ѡ��һ������
        if (direction==0 && count<n*n)
            cout<<"��"<<count<<"����·��ͨ!\n";
        else
        {   count++;                                       //������1
            p = go(p, direction);                          //ǰ��һ�� 
        }
    }
}

//Ԥ����Ϊpλ����̽��һ��8������λ�õĿ�ͨ·����������һ����ͨ·����Сֵ�ķ���
int HorseTravel::select(Point p)
{
    cout<<"��ǰλ��: "<<p<<endl<<this->chessboard;         //�����������Ԫ��
    cout<<"����   ��һλ��   ��ͨ����     ��ͨ·��"<<endl;
    int direction=0, minroad=8;
    for (int i=1; i<=8; i++)                               //��̽p(x,y)��8������λ��
    {
        int road=0;
        Point next1 = go(p,i);                             //next1��p��i�������һλ��
        if (isValid(next1))                                //next1����������δ�����ʹ�
        {
            cout<<"  "<<i<<"\t"<<next1<<"\t";
            for (int j=1; j<=8; j++)                       //ͳ��next1(x,y)�Ŀ�ͨ·��road
            {
                Point next2 = go(next1,j);                 //next2��next1��j�������һλ��
                if (isValid(next2))                        //next2����������δ�����ʹ�
                {
                    road++;
                    cout<<j<<",";
                }
            }    
            if (road<minroad)
            {
                minroad=road;                              //minroad����road����Сֵ
                direction=i;                               //direction����road��Сֵ�ķ���
            }
            cout<<"\t"<<road<<endl;
        }
    }
    cout<<"ѡ����һ������  direction="<<direction<<"\r\n\n";
    return direction;                                      //������һ����ͨ·����Сֵ�ķ���
}

bool HorseTravel::isValid(Point p)                         //�ж�p�Ƿ�����������δ�����ʹ�
{
    return (p.x>=0 && p.x<n && p.y>=0 && p.y<n && chessboard.get(p.x, p.y)==0);
}

Point HorseTravel::go(Point p, int direction)              //����p��direction�������һλ�ã����ı�p
{
    Point q(p);                                            //ִ��Point���Ĭ�Ͽ������캯��
    switch (direction)
    {
        case 1:  q.x-=2;  q.y++;   break; 
        case 2:  q.x--;   q.y+=2;  break; 
        case 3:  q.x++;   q.y+=2;  break; 
        case 4:  q.x+=2;  q.y++;   break; 
        case 5:  q.x+=2;  q.y--;   break; 
        case 6:  q.x++;   q.y-=2;  break; 
        case 7:  q.x--;   q.y-=2;  break; 
        case 8:  q.x-=2;  q.y--;   break; 
    }
    return q;
} 

int main()
{
//    HorseTravel horse(5,0,1);                         //��ͨ
//    HorseTravel horse(8,0,0);                       //��(0,0)λ�ÿ�ʼ��������ʾ�м���
//    HorseTravel horse(8,4,3);

    int n=8, x=0, y=0;
//    cout<<"�������̴�Сn����ʼλ��(x,y)��";
//    cin>>n>>x>>y;
    HorseTravel horse(n,x,y);

    system("pause");
    return 0;
}

/*
�������н�����£�
    HorseTravel horse(8,0,0);
   1  16  27  22   3  18  47  56
  26  23   2  17  46  57   4  19
  15  28  25  62  21  48  55  58
  24  35  30  45  60  63  20   5
  29  14  61  34  49  44  59  54
  36  31  38  41  64  53   6   9
  13  40  33  50  11   8  43  52
  32  37  12  39  42  51  10   7


    HorseTravel horse(5,0,1);                  //��ͨ
��24����·��ͨ!
  18   1  14   7  16
  11   6  17   2  13
  22  19  12  15   8
   5  10  23  20   3
   0  21   4   9  24


    HorseTravel horse(8,4,3);
��64��  ��ǰλ��: (4,2)
  12  25  14  31  10  27  36  61
  15  32  11  26  35  62   9  28
  24  13  34  63  30  47  60  37
  33  16  23  56  59  38  29   8
  22  55  64   1  46  57  48  39
  17  52  19  58  49  42   7   4
  54  21  50  45   2   5  40  43
  51  18  53  20  41  44   3   6

 */  
