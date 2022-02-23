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
           cout<<"\nInserting ..."<<item->value<<" as root.";
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

void inorder(Node * locate)
{
    if(locate == NULL)
        return;
    inorder(locate -> lc);
    cout<<locate -> value<<" ";
    inorder(locate -> rc);
}

void deleteNode(int num,Node*locate,Node*parent)
{
    if(locate == NULL)
        return;  
    if(num == root -> value)
    {
        Node * parent = NULL;
        Node * newRoot = NULL;

        if(root -> lc)
        {
            newRoot = root->lc;
        }
        else
        {
            root = root -> rc;
            return;
        }

        if((newRoot -> lc == NULL) && (newRoot ->rc == NULL))
        {
            newRoot -> rc = root -> rc;
            root = newRoot;
            cout<<"\nRoot Updated !";
            cout<<"\nRoot:"<<root->value<<" lc:"<<root->lc->value<<" rc"<<root->rc->value;
            return;
        }
        else if(newRoot -> rc == NULL)
        {
            newRoot -> rc = root -> rc;
            root = newRoot;
            cout<<"\n\nRoot Updated !";
            cout<<"\nRoot:"<<root->value<<" lc:"<<root->lc->value<<" rc"<<root->rc->value;
            return;
        }

        while(newRoot ->rc)
        {
            parent = newRoot;
            newRoot = newRoot ->rc;
        }
        if((newRoot -> lc == NULL) && (newRoot -> rc == NULL))
        {
            //Select Deepest Right Node and replace that with it
            parent -> rc = NULL;
            newRoot -> lc = root -> lc;
            newRoot -> rc = root -> rc;
            root = newRoot;
            cout<<"\n\nRoot Updated !";
            cout<<"\nRoot:"<<root->value<<" lc:"<<root->lc->value<<" rc"<<root->rc->value;
            return;
        }
        else if(newRoot -> lc == NULL)
        {
            parent = newRoot;
            newRoot = newRoot -> rc;
            //Delete rc and replace it with root
            parent -> rc = NULL;
            newRoot -> lc = root -> lc;
            newRoot -> rc = root -> rc;
            root = newRoot;
            cout<<"\n\nRoot Updated !";
            cout<<"\nRoot:"<<root->value<<" lc:"<<root->lc->value<<" rc"<<root->rc->value;
            return;
        }
        else if(newRoot -> rc == NULL)
        {
            parent = newRoot;
            newRoot = newRoot -> lc;
            //Delete lc and replace it with root
            parent -> lc = NULL;
            newRoot -> lc = root -> lc;
            newRoot -> rc = root -> rc;
            root = newRoot;
            cout<<"\n\nRoot Updated !";
            cout<<"\nRoot:"<<root->value<<" lc:"<<root->lc->value<<" rc"<<root->rc->value;
            return;
        }

    }
        
    deleteNode(num,locate -> lc,locate);

    if(locate -> value == num)
    {
        if(locate -> lc == NULL || locate -> rc == NULL)
        {
           Node * joint = new Node();
           if(locate -> lc)
           {
               joint = locate -> lc;
           }
           else if(locate -> rc)
           {
               joint = locate -> rc;
           }
           else
           {
               joint = NULL;
           }
           
           if(parent -> lc -> value == locate -> value)
           {
               cout<<"\n\nDeleting the... "<<parent -> lc -> value;
               parent -> lc  = joint;
               return;
           }
           else
           {
               cout<<"\n\nDeleting the... "<<parent -> rc -> value;
               parent -> rc = joint;
               return;
               
           }
        }

        else if(locate ->lc && locate -> rc)
        {
            Node * joint1 = new Node();
            joint1->lc = NULL;
            joint1->rc = NULL;

            Node * joint2 = new Node();
            joint2->rc = NULL;
            joint2->lc = NULL;

            if(locate -> lc -> value < locate -> rc -> value)
            {
                joint1 = locate->lc;
                joint2 = locate->rc;
            }
            else
            {
                joint1 = locate->rc;
                joint2 = locate->lc;
            }


            if((parent -> lc -> value) == (locate -> value))
            {
                cout<<"\n\nDeleting the... "<<parent -> lc -> value;
                parent -> lc  = joint2;
                parent -> lc  ->lc = joint1;
            }
            else
            {
                cout<<"\n\nDeleting the... "<<parent -> rc -> value;
                parent -> rc = joint1;
                parent -> rc ->rc = joint2;
            }
        }

        else
        {
            cout<<"\n Something went wrong deleting the element !";
        }

    }

    deleteNode(num,locate -> rc,locate);
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
    insertElement(18,root);
    insertElement(35,root);
    cout<<"\n\nINORDER TRAVERSAL \n";
    inorder(root);

    deleteNode(20,root,root);
    cout<<"\n\nINORDER TRAVERSAL \n";
    inorder(root);

    deleteNode(45,root,root);
    cout<<"\n\nINORDER TRAVERSAL \n";
    inorder(root);

    deleteNode(79,root,root);
    cout<<"\n\nINORDER TRAVERSAL \n";
    inorder(root);

    return 0;
}
