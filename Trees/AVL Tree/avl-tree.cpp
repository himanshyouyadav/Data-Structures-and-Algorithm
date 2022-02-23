


#include<iostream>

using namespace std;

struct Node
{
    struct Node *lchild, *rchild;
    int data;
    int height;
} *root = NULL;


int NodeHeight(struct Node *p)
{
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height:0;
    hr = p && p->rchild ? p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}


int BalanceFactor(struct Node *p)
{
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height:0;
    hr = p && p->rchild ? p->rchild->height:0;

    return hl-hr;
}

Node * LLRotation(Node * p)
{
    cout<<"Peforming LL Rotation On "<<p->data<<endl;
    Node * pl  = p->lchild;
    Node * plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
    {
        root = pl;
    }

    return pl;
}

Node * LRRotation( Node * p)
{
    cout<<"Peforming LR Rotation On "<<p->data<<endl;

    Node * pl = p->lchild;
    Node * plr = pl->rchild;
    
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->rchild = p;
    plr->lchild = pl;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(root == p)
    {
        root = plr;
    }

    return plr;
   
}

Node * RRRotation(Node * p)
{
    cout<<"Peforming RR Rotation On "<<p->data<<endl;
    Node * pr = p->rchild;
    Node * prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    pr->height = NodeHeight(pr);
    p -> height = NodeHeight(p);

    if(p==root)
    {
        root = pr;
    }

    return pr;
}

Node * RLRotation(Node * p)
{
    cout<<"Peforming RL Rotation On "<<p->data<<endl;
    Node * pr = p->rchild;
    Node * prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    if(root == p)
    {
        root = prl;
    }

    return prl;
   
}

Node * RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;

    if(p == NULL)
    {
        t = new Node();
        t -> data = key;
        t -> height = 1;
        t -> lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data)
    {
        p->lchild = RInsert(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild = RInsert(p->rchild,key);
     }

    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        cout<<"Key = "<<key<<" makes imbalance"<<endl;
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        cout<<"Key = "<<key<<" makes imbalance"<<endl;        
        return LRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        cout<<"Key = "<<key<<" makes imbalance"<<endl;        
        return RRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        cout<<"Key = "<<key<<" makes imbalance"<<endl;        
        return RLRotation(p);
    }
    return p;
}

void dataRcLc(Node * p)
{
    cout<<"\n";
    cout<<">Data:"<<p->data<<endl;
    if(p->rchild)
        cout<<"Right Child:"<<p->rchild->data<<endl;
    if(p->lchild)
        cout<<"Left Child:"<<p->lchild->data<<endl;
    cout<<endl;
}

void inorder(Node * root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->lchild);
    dataRcLc(root);
    inorder(root->rchild);
}



int main()
{
    cout<<endl;

    root = RInsert(root,30);
    RInsert(root,20);
    RInsert(root,50);
    RInsert(root,60);
    RInsert(root,52);
    RInsert(root,55);


    inorder(root);
    cout<<"Root :"<<root->data<<endl;

    return 0;
}