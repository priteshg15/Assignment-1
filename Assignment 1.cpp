#include<iostream> //17U207 221029 A2 batch
using namespace std;

class TreeNode {
public:
	char data;// store operand or operator
	TreeNode* rchild;//pointer to right child
        TreeNode *lchild;
	friend class Node;
	friend class Stack;
	TreeNode() {    //constructor used to set leftchild and rightchild to NULL and data to *
	data = '*';
	lchild = NULL;
	rchild = NULL;
	}
};


class Node {
public:
TreeNode* treenode; //node of TreeNode 
Node* next;//pointer to next node
	Node() { //constructor to set next to NULL
	next = NULL;
	}
friend class Stack;
};

class Stack { //Stack class to implement stack and its function
public:
Node* top;


	Stack() {
	top = NULL;}
void push(TreeNode* n); // push fucntion of stack to add an element in stack
TreeNode* pop(); //pop function
void postorder(TreeNode* root); 
void inorder(TreeNode* root);
void preorder(TreeNode* root);
};

void Stack::push(TreeNode* n) //push function defination
{
	Node* temp = top;
	Node* a = new Node;
	a->treenode = n;

	top = a;
	top -> next = temp;
}

TreeNode* Stack::pop() { //pop function defination
Node* temp = top;
top = top ->next;
temp -> next = NULL;
return (temp->treenode);

}

void Stack::postorder(TreeNode* root) //postorder fucntion defination
{
if(root)
{
postorder(root->lchild); //recurrsive call by passing left child node of root
postorder(root->rchild);//recurrsive call by passing right child node of root
cout<<root->data<<" "; //printing the data

}
}
void Stack::inorder (TreeNode *root )
	{
			if (root)
			{
				inorder(root ->lchild); //recurrsive call by passing left child node of root
				cout<<root->data<<" ";
				inorder(root->rchild); //recurrsive call by passing right child node of root
			}
	}
void Stack::preorder (TreeNode *root )
	{
				if (root)
				{
					cout<<root->data<<" ";
					preorder(root->lchild); //recurrsive call by passing right child node of root
					preorder(root->rchild); //recurrsive call by passing right child node of root
				}
	}




int main()
{
char exp[50];
cout<<"Enter postfix expression\n";
cin>>exp; //accept the expression 
int i = 0;
Stack st; //object of class Stack for creation of tree
while(exp[i] != '\0') { //traverse the string till end
if(  (exp[i] >= 65 &&exp[i] <= 90) || (exp[i] >= 97 && exp[i] <= 122)) { //if character is an operand
	TreeNode* n = new TreeNode; //create a node and put character into the treenode
	n->data = exp[i];
	st.push(n);//push the node onto the stack
}

	if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
	TreeNode* a = new TreeNode;
	a->data = exp[i]; // create treenode and put its data as the operator
	a->rchild = st.pop();//first pop = rchild
	a->lchild = st.pop();//second pop = lchild
	st.push(a); // push result onto stack

	}
i++;

}

TreeNode* root = (st.top) ->treenode;
cout<<"Post order: ";
st.postorder(root);
cout<<"\n";
cout<<"Inorder : ";
st.inorder(root);
cout<<"\n";
cout<<"Preorder : ";
st.preorder(root);
return 0;
}
/*
OUTPUT
Enter postfix expression
abc*d+/
Post order: a b c * d + /
Inorder : a / b * c + d
Preorder : / a + * b c d

*/








