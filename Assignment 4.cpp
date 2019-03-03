#include<iostream>
using namespace std;

class node
{
    friend class bst;
    public:
	    int data;
	    node *left;
	    node *right;
	    node()
	    {
       	      data=0;
	      left=NULL;
	      right=NULL;
	    }
};

class bst
{
    friend class node;                  
    public:
     node *root;
	            bst()
	            {
	              root=NULL;
	            }

    void insert(int item)
    {
        node *temp=new node;
        temp->data=item;
        if(root==NULL)
        root=temp;
        else 
           {
              node *parent;
              node *child;
              child =root;
              while(child != NULL)
                  {
                   if(child->data>item)
                {
                  parent=child;
                  child=child->left;
                }
            else
                {
                  parent=child;
                  child=child->right;
                }
                 }
            if(parent->data>item)
              parent->left=temp;
            else
              parent->right=temp;
            }
     }

    void tree(int value)
    {
    int a;
cout<<"Enter the data\n";
    for(int i=0;i<value;i++)
        {
          
          cin>>a;
          insert(a);
        }
    }

    node *current;

    void display(node *current)
    {
        if(current)
        {
           display(current->left);
           cout<<current->data<<" ";
           display(current->right);
        }
    }
   
  

node * mirror(node *root) //function for mirroring
{
node *current;
current=root;
if(current==NULL)
return 0;
else
{ 
node* temp;
temp=current->left;
current->left=current->right;
current->right=temp;
mirror(current->left); //recurrsive call to the function
mirror(current->right);

}
return (current);
}
}
;
int main()
{
  int num,n;
  bst b;
  cout<<"Enter the number of elements to be inserted\n";
  cin>>n;
  b.tree(n);
cout<<"Before mirroring\n";
b.display(b.root); 

 cout<<"Mirror image\n";
  b.mirror(b.root);
cout<<"\n";
  b.display(b.root);
return 0;
}
         
/* OUTPUT
Enter the number of elements to be inserted
8
Enter the data
4 1 2 3  6 7 9 5
Before mirroring
1 2 3 4 5 6 7 9
 Mirror image
9 7 6 5 4 3 2 1 

*/



