#include<iostream> //17U207 221029 A2 batch
using namespace std;

class TreeNode {
public:
	char data;
	TreeNode* lchild;// store operand or operator
	TreeNode* rchild;//pointer to right child

	friend class Node;
	friend class Stack;
	TreeNode() {//constructor used to set leftchild and rightchild to NULL and data to *
	data = '#';
	lchild = NULL;
	rchild = NULL;
	}
};


class Node {
public:
TreeNode* treenode;//node of TreeNode 
Node* next;//pointer to next node
	Node() {//constructor to set next to NULL
	treenode=NULL;
	next = NULL;
	}
friend class Stack;
};

class Stack {//Stack class to implement stack and its function
public:
Node* top;


	Stack() 
	{
	top = NULL;
	}
void push(TreeNode* n);// push fucntion of stack to add an element in stack
TreeNode* pop();//pop function
//void postorder(TreeNode* root);
void inorder(TreeNode* root);
void preorder(TreeNode* root);

};

void Stack::push(TreeNode* n) //push function defination
{
	Node* temp = this->top;
	Node* a = new Node;
	a->treenode = n;

	top = a;
	top -> next = temp;
}


TreeNode* Stack::pop() {//pop function defination
Node* temp = top;
top = top ->next;
temp -> next = NULL;
return (temp->treenode);
delete (temp);

}

/*void Stack::postorder(TreeNode* root)
{
if(root)
{
postorder(root->lchild);
postorder(root->rchild);
cout<<root->data<<" ";

}
}*/
void Stack::inorder (TreeNode *root )
	{
	top=NULL; 
TreeNode *current; //intilizing current node of type TreeNode
current=root;
	while(1) //Entering loop breaking or returning condition is inside the loop
	{
		while(current) //traverse till left child becomes NULL
		{      	
		       push(current);
			current=current->lchild;
		}
		if((top==NULL)&&(current==NULL)) //if this condtion satisifes break from loop
		return;
		current=pop(); //if stack is not empty, then current = pop, print it's data, and go to it's right
		cout<<current->data<<" ";
		current=current->rchild;		
		
	}		
cout<<"\n";			
	}

void Stack::preorder(TreeNode* current)
{

        push(current); //push root onto stack
        while(1) //enter the loop, breaking condition is inside the loop
        {
                        
                while(current) // keep printing the node, pushing it onto stack and going to left till you reach NULL
                {
                        cout<<current->data<<" "; 
                        push(current);
                
                        current = current->lchild;
                }
                
                current = pop(); //after we reach NULL, put current = pop node from stack
                current = current -> rchild; // and go to it's right
                if(top == NULL ) // if stack is empty, our prefix expression is printed, so return
                return;

                
        }       
        

}


int main()
{
char exp[50];
cout<<"Enter postfix expression\n";
cin>>exp;
int i = 0;
Stack st;
while(exp[i] != '\0') {//creation of tree
if(  (exp[i] >= 65 &&exp[i] <= 90) || (exp[i] >= 97 && exp[i] <= 122)) {
	TreeNode* n = new TreeNode;
	n->data = exp[i];
	st.push(n);
}

	if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
	TreeNode* a = new TreeNode;
	a->data = exp[i];
	a->rchild = st.pop();
	a->lchild = st.pop();
	st.push(a);

	}
i++;

}

TreeNode* root = (st.top) ->treenode;
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








