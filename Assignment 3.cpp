#include<iostream> //17u207 A2 assignment 3
using namespace std;

class node //class for node
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

class bst   //class for binary search tree
{
    friend class node;                  
    public:
     node *root;
	            bst()
	            {
	              root=NULL;
	            }

    void insert(int item) //function defination for insert
    {
        node *temp=new node;
        temp->data=item;
        if(root==NULL) //checking if tree empty
        root=temp;
        else 
           {
              node *parent;
              node *child;
              child =root;
              while(child != NULL)
                  {
                   if(child->data>item) //comparing item to be isnerted
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

    void tree(int value) //function for accepting data
    {
    int a;
    for(int i=0;i<value;i++)
        {
          cout<<"Enter the data\n";
          cin>>a;
          insert(a);
        }
    }

    node *current;

    void display(node *current) //function for displaying data
    {
        if(current)
        {
           display(current->left);
           cout<<current->data<<"->";
           display(current->right);
        }
    }
   
   void minimum()  //funcction for finding minimum element
   {
     node *current=root;
     int min;
     while(current->left != NULL)
     current=current->left; //traversing to the leftmost element since it is the minimum in a bst
     cout<<current->data; 
   }

   int maximum(node *curr) //function to find height of a tree
   {
      int lheight;
      int rheight;
     if(curr==NULL)
     return -1;
    else { 
	      lheight=maximum(curr->left)+1;
	      rheight=maximum(curr->right)+1;
	 }
       if (lheight<= rheight) 
       return rheight;
       else
        return lheight;
   }
};
	      


int main()
{
  int num,n;
  bst b; // creation of object of class bst type
  cout<<"Enter the number of elements to be inserted\n";
  cin>>n;
  b.tree(n);
  cout<<"The inorder of binary search tree is\n";
  b.display(b.root);
  cout<<"\nThe minimum value of the binary search tree is ";
  b.minimum();
  cout<<"\n";
  int max=b.maximum(b.root);
  cout<<"The maximum height of the tree is "<<max<<"\n";
  cout<<"The maximum number of nodes is "<<++max<<"\n";
  return 0;
}
/* OUTPUT
Enter the number of elements to be inserted
8
Enter the data
 7 6 2 4 5 3 1 9
The inorder of binary search tree is
1->2->3->4->5->6->7->9->
The minimum value of the binary search tree is 1
The maximum height of the tree is 4
The maximum number of nodes is 5
*/