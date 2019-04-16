//221029 17U207 A2 Depth first search

#include<iostream>
using namespace std;

class node // to push and pop for iterative dfs
{
private:
	int num;
	node* next;
public:
	node()
	{
		next = NULL;

	}
friend class stack;
friend class depth;


};

class stack // to push and pop for iterative dfs
{
private:
	node* top;
public:
	stack()
	{
		top = NULL;
	}

	void push(int);
	int pop();
	friend class depth;

};

void stack::push(int n)
{
	node* temp = new node;
	temp->num = n;

	if(top == NULL)
		top = temp;
	else
	{
	node* tempy = top;
	top = temp;
	top->next = tempy;
	}
}

int stack::pop()
{
	node* temp = top;
	if(top->next == NULL)
		top = NULL;
	else
	{
	top = top -> next;
	}
	temp->next = NULL;
	return temp->num;
}

class depth
{
private:
	int visited[20]; //to store if vertex is visited or not
	int adjacency[20][20]; // to store the adjacency matrix
	int vertices; // number of vertices
	int edges; // number of edges

public:
	depth() // to initialize the visited array and adjacency matrix
	{
		for(int i = 0; i<20; i++)
			visited[i] = 0;
		for(int i = 0; i<20; i++)
			for(int j = 0; j<20; j++)
				adjacency[i][j] = 0;
	}

	void enter(); // to accept data and prepare adjacency matrix
	void recursive_traversal(int a);
	void nonrecursive();
	};

void depth::enter()
	{
	cout<<"\nEnter the number of vertices ";
	cin>>vertices;
	cout<<"\nEnter the number of edges ";
	cin>>edges;
	cout<<"\nEnter the edges "<<endl;
	for(int i = 0; i < edges; i++)
		{

			int v1,v2;
			cin>> v1>>v2;
			adjacency[v1][v2] = 1;
			adjacency[v2][v1] = 1; // marking the undirected edge in adjacency matrix





		}
	}

void depth::recursive_traversal(int a)
	{
		cout<<a<<" "; // printing the vertex, and marking it as visited
		visited[a] = 1;
		for(int j= 0; j< vertices; j++)
			if(adjacency[a][j] == 1 && visited[j] == 0) // calling function with vertex if it is not visited and current vertex has edge with it
				recursive_traversal(j);
	}

void depth::nonrecursive()
	{
	for(int i = 0; i<vertices; i++) // initializing visited array, as we have traversed recursively before
		visited[i] = 0;

	stack s;
	s.push(0); // push 0 onto stack
	while(s.top != NULL) // while stack is not empty
		{
			int v = s.pop(); // pop vertex, print it, mark it as visited
			if(visited[v]==0)
			cout<<" "<<v;
			visited[v] = 1;
			for(int i = 0; i<vertices; i++) // push all adjacent vertices that are unvisited
				if(adjacency[v][i] !=0 && visited [i] == 0)
					s.push(i);
		}
		cout<<"\n";
	}
int main()

{
depth d;

d.enter();
cout<<"Depth first traversal using recurrsion ";
d.recursive_traversal(0);
cout<<"\n";
cout<<"Depth first traversal using iteration";
d.nonrecursive();
return 0;
}

/* OUTPUT
Enter the number of vertices 4

Enter the number of edges 4

Enter the edges
0 1
0 3
1 2
2 3
Depth first traversal using recurrsion 0 1 2 3
Depth first traversal using iteration 0 3 2 1
*/















