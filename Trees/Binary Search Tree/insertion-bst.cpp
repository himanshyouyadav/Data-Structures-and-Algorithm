#include<iostream>

using namespace std;

struct Node
{
    Node *lc;
    Node *rc;
    int value;
};

Node * root = NULL;
void insertElement(int num, Node * locate)
{
      if(root == NULL)
      {
           Node * item = new Node();
           item -> rc = NULL;
           item -> lc = NULL;
           item -> value = num;
           root = item;
           cout<<"\nInserting ... "<<item->value<<" as root.";
           return;
      }   
        
      if((locate -> value) > num)
      {
          if((locate -> lc) == NULL)
          {
               Node * item = new Node();
               item -> rc = NULL;
               item -> lc = NULL;
               item -> value = num;
               locate -> lc = item;
               cout<<"\nInserting ..."<<num<<" as lc of "<<locate->value;
               return ;
          }
          else
          {
              insertElement(num,locate -> lc);
          }
      }
      else
      {
          if((locate -> rc) == NULL)
          {
               Node * item = new Node();
               item -> rc = NULL;
               item -> lc = NULL;
               item -> value = num;
               locate -> rc = item;
               cout<<"\nInserting ..."<<num<<" as rc of "<<locate->value;
               return ;
          }
          else
          {
              insertElement(num,locate -> rc);
          }
      }

}

void preorder(Node * locate)
{
    if(locate == NULL)
        return;
    cout<<locate -> value<<" ";
    preorder(locate -> lc);
    preorder(locate -> rc);
    
}

void postorder(Node * locate)
{
    if(locate == NULL)
        return;
    postorder(locate -> lc);
    postorder(locate -> rc);
    cout<<locate -> value<<" ";
}

void inorder(Node * locate)
{
    if(locate == NULL)
        return;
    inorder(locate -> lc);
    cout<<locate -> value<<" ";
    inorder(locate -> rc);
}


int main()
{

    insertElement(45,root);
    insertElement(15,root);
    insertElement(79,root);
    insertElement(90,root);
    insertElement(10,root);
    insertElement(55,root);
    insertElement(12,root);
    insertElement(20,root);
    insertElement(50,root);
    cout<<"\n\nPREORDER TRAVERSAL \n";
    preorder(root);
    cout<<"\n\nPOSTORDER TRAVERSAL \n";
    postorder(root);
    cout<<"\n\nINORDER TRAVERSAL \n";
    inorder(root);
    return 0;
}