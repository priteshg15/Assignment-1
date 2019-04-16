//221029 17U207 A2 Breadth First Search
#include<iostream>
using namespace std;


class GNode // to store the vertices in adjacency list
{
private:
	int data;
	GNode* next;
public:
	GNode()
	{
		next = NULL;
	}

	friend class breadth;
};

class q_node //to enqueue and dequeue for breadth first search traversal
{
private:
        int num;
        q_node* next_int;
public:
	q_node()
	{
		next_int = NULL;
	}
        friend class breadth;
};

class breadth
{
private:
	GNode* heads[10]; //array of head pointers which will store head of each linked list
	int vertices; //number of vertices
        q_node* front; //front of queue
        q_node* rear; //rear of queue
	int visited[15]; //visited array to store whether vertex is visited or not
	int edges;

public:
	void enter(); //accepts graph and prepares it's adjacency list
	GNode* create(int); //creates a GNode and returns it's pointer
	void append(int node, int edge);
	void display();

        breadth()
        {
                front = NULL;
                rear = NULL;
		for(int i = 0; i<15; i++)
			visited[i] = 0;
	}

        void enq(int); //enqueue
        int deq(); //dequeue
        q_node* create_qnode(int); //create a node of the q and return it's pointer
	bool qempty(); //check if q is empty
	void enq_adjacent(int); //enq all adjacent vertices of passed vertex
	void bfs(); //bfs traversal

};

	void breadth::bfs() //traverse using bfs traversal
	{
		cout<<"\nBreadth First Traversal:-  ";
		int v;
		enq(0);
		while(!qempty())
		{
			v = deq(); //dequeue
			if(visited[v] == 0) // if vertex is not visited, then
			{
				cout<<" "<< v; // print it
				visited[v] = 1; // mark it as visited
				enq_adjacent(v); // and enque all it's adjacent vertices
			}
		}
		cout<<endl;
	}

	void breadth::enq_adjacent(int n) //enqueue all the adjacent vertices of accepted vertex
	{
		GNode* temp = heads[n];
		temp = temp->next;
		while(temp)
		{
			enq(temp->data);
			temp = temp->next;
		}
	}

	bool breadth::qempty() //return true if q empty else return false
	{
		if(front == NULL && rear == NULL)
			return true;
		else
			return false;
	}

        void breadth::enq(int n) //code for enqueue
        {
                if(front == NULL && rear == NULL)
                {
			q_node* to_insert=create_qnode(n);
			front = to_insert;
			rear = to_insert;
                }

		else
		{
			rear->next_int = create_qnode(n);
			rear = rear->next_int;
		}
        }

        q_node* breadth::create_qnode(int n)
	{
		q_node* temp = new q_node;
		temp->num = n;
		return temp;
	}


        int breadth::deq() //code for dequeue
        {
		int to_pop;
		if(front != rear)
		{
			q_node* temp = front;
			front = front->next_int;
			to_pop = temp->num;
			temp->next_int = NULL;
			delete temp;
			return to_pop;
		}
		else if(front == rear)
		{
		 	to_pop = front->num;
			front = NULL;
			rear = NULL;
			return to_pop;
		}

        }

	void breadth::display() //displays all the edges present in the graph
	{
		GNode* temp;
		for(int i = 0; i<vertices; i++)
		{
			cout<<endl;
			temp = heads[i]; // temp kept at head of the list, and as we traverse the list, the adjacent vertices are printed
			temp = temp->next;
			while(temp) // till we reach the end of the list. then we go to the next list using loop, till we print adjacent vertices of all heads
			{
				cout<<i<<"-"<<temp->data<<", ";
				temp = temp->next;
			}
		}
	}
	void breadth::enter() // accepts graphs and prepares adjacency lists
	{
		int num,edge;
		cout<<"Enter the number of vertices";
		cin>>vertices; // accept number of vertices
		cout<<"\nEnter the number of edges ";
		cin>>edges;
		for(int i = 0; i<vertices; i++)
		{
			heads[i] = create(i); // head nodes created.
		}
		cout<<"\nEnter the edges\n";
		for(int i = 0; i<edges; i++)
		{
			int v1, v2;
			cin>>v1>>v2;
			append(v1,v2);
			append(v2,v1);
		}

	}

	void breadth::append(int node, int edge)
	{
		GNode* temp = heads[node];

		while(temp->next != NULL)
			temp = temp->next;
		temp->next = create(edge);

	}

	GNode* breadth::create(int n) //create GNode and return it's pointer
	{
		GNode* temp = new GNode;
		temp->data = n;
		return temp;
	}

int main()
{
breadth b;
b.enter(); //accept graph and prepare adjacency lists
b.bfs(); //traverse using bfs
return 0;
}

/* OUTPUT
Enter the number of vertices
4

Enter the number of edges
4

Enter the edges
0 1
0 3
1 2
2 3

Breadth First Traversal:-   0 1 3 2

*/






















