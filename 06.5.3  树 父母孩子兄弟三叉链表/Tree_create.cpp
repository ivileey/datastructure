//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.5.3   ���ĸ�ĸ�����ֵ�����ʵ��
//����6.4��  �Ժ������ʾ����һ�ó�������

#include "Tree.h"                                          //���ĺ����ֵ�����ʵ�ֵ�����

int main()
{
    MyString prelist[]={"A","\tB","\t\tE","\t\tF","\tC","\tD","\t\tG"};  //ͼ6.40
    Tree<MyString> tree1(prelist, 7); 
    cout<<tree1;

    //��6.6
    MyString china[]={"�й�","\t����","\t�Ϻ�","\t����","\t\t�Ͼ�","\t\t\t����","\t\t����","\t\t����"};
                                                            //MyString��char*���͵Ĺ��캯��
    Tree<MyString> tree(china, 8);                         //�����ĺ������ʾ����������ɭ�֣�
    cout<<tree;                                            //������ĺ������ʾ�ַ���


/*    //ϰ��6
    char* zhejian[]={"�㽭","\t����","\t����","\t����","�㶫","\t����"};
    Tree<MyString> zjtree;
    create(zjtree, zhejian, 6);  
    cout<<zjtree;                                            //������ĺ������ʾ�ַ���
// ����   tree.insertChild(tree.root, zjtree, 0);                 //�������һ������

/*
    char* korea[]={"����","\t�׶�","\t��ɽ","\t����"};
    char* usa[]={"����","\t��ʢ��","\tŦԼ��","\t\tŦԼ"};
    Tree<MyString> koreatree, usatree;
    create(koreatree, korea, 4);
    create(usatree, usa, 4);

    TreeNode<MyString> *California  = usatree.insertLastChild(usatree.root,"����������");
    usatree.insertChild(California, "��ɼ�", 2);
    TreeNode<MyString> *Nevada = tree.insertLastSibling(California,"�ڻ���");
    usatree.insertChild(Nevada, "��˹ά��˹",3);

    tree.insertChild(tree.getLastSibling(tree.root), koreatree, 1); //��������
    tree.insertSibling(tree.root, usatree, 3);
*/

//    cout<<tree;                                            //������ĺ������ʾ�ַ���
    cout<<"��"<<tree.count()<<"����㣬�߶�Ϊ"<<tree.height()<<endl;
    cout<<"\""<<tree.root->data<<"\"��"<<tree.childCount(tree.root)<<"�����ӽ��\n";
    tree.printGenList(); 


    system("pause");
    return 0;
}
/*
�������н�����£�
�й�
	����
	�Ϻ�
	����
		�Ͼ�
			����
		����
		����
			��ɽ
	�㽭
		����
		����
		����
	�㶫
		����
����
	�׶�
�ձ�
	����
��19����㣬�߶�Ϊ4
�й���5�����ӽ��



�й�
	����
	�Ϻ�
	����
		�Ͼ�
			����
		����
		����
			��ɽ
	�㽭
		����
		����
		����
	�㶫
		����
����
	�׶�
�ձ�
	����
��19����㣬�߶�Ϊ4
�й���5�����ӽ��
������: ���� ��ɽ ���� ���� �Ͼ� ���� ���� ���� ���� �㶫 �㽭 ���� �Ϻ� ���� �׶� ���� �ձ� ���� �й� 

*/
/*
        if (tree.root->sibling==NULL)                      //�����û���ֵ�ʱ
            insert(tree, tree.root, prelist[i]);           //��prelist[i]���뵽tree����tree.rootΪ����������
        else                                               //���뵽�����һ���ֵܵ�������
            insert(tree, tree.getLastSibling(tree.root), prelist[i]);
}

void insert(Tree<char*> &tree, TreeNode<char*> *p, char *str)
{ 
    if (*str!='\t')                                        //strû��\tǰ׺ʱ
        tree.insertLastSibling(p, str);                    //����str��Ϊp�����һ���ֵ�
    else                                                   //str��\tǰ׺ʱ������str��p�����һ��������
    {
        str++;                                             //ȥ��str����һ��ǰ׺'\t'
        if (p->child==NULL)                   	           //pû�к���ʱ
            p->child = new TreeNode<char*>(str);           //����str��Ϊp�ĵ�һ������
        else
            insert(tree, tree.getLastChild(p), str);       //����str��p�����һ�������У��ݹ����
    }
}*/

/*
//��treeɭ�����һ�����в�����str�������ʾ��һ����㣬���ֵȥ����str����\tǰ׺���ǵݹ��㷨
void insert(Tree<char*> &tree, char *str)
{ 
    if (tree.root==NULL) 
        tree.root = new TreeNode<char*>(str);
    else
    {
        TreeNode<char*> *p=tree.getLastSibling(tree.root); //p������������һ���ֵ�
        if (p==NULL)
            p = tree.root;                   	           //pû���ֵ�ʱָ�����ѡ��ɭ�������һ����
        if (*str!='\t')
            p->sibling = new TreeNode<char*>(str);         //û��\tǰ׺ʱ������str��Ϊp�����һ���ֵ�
        else                               	               //��\tǰ׺ʱ������str��p�����һ��������
        {
            str++;                                         //ȥ��str����һ��ǰ׺'\t'
            while (*str=='\t')                             //�ַ�����\t��ͷ
            {
                TreeNode<String> lastChild=tree.getLastChild(p);    	//���p�����һ������
                if (lastChild!=null)
                    p = lastChild;
                str = str.substring(1);                      	//ȥ��str����һ��ǰ׺'\t'
                
				q = tree.getLastChild(p);        //q����p�������һ������
                if (q!=NULL)
                p = q;
                str++;
            }
            tree.insertLastChild(p, str);          //����str��Ϊp�������һ������
        }
        else
    }
}
    public static void insert(Tree<String> tree, String str)
    {
=       {   str = str.substring(1);                            	//
            while (str.charAt(0)=='\t')                       	//�ַ�����\t��ͷ
           }
            tree.insertLastChild(p, str);                        //����str��Ϊp�����һ������
        }
    }*/


