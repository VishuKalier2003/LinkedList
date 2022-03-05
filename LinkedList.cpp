// Linked List Data type full Implementation...
#include <iostream>
#include <cmath>
using namespace std;
class Node                // Node class for defining Node data type 
{
    public:
    int data;         // Integer data member
    Node* next;       // next node pointer thus, type of the pointer is the type of node it is            //
    public:           // connecting. Thus it is connecting Node to Node thus data type Node
    Node(int val) 
    {
        data = val;next = NULL;         // Parametrized Constructor
    }
};
class LinkedList      // Linked List class for defining opeartions on List
{
    public:
    void InsertAtTail(Node* &head, int val)
    {
        Node* n = new Node(val);    // New Node created with the given Value
        if (head == NULL)         // If the list is empty and head is pointing to Null then no need
        {                         // to traverse simply add the new node to head
            head = n;     // head becomes the new Node
            return;
        }
        Node* temp = head;          // Temporary node for Traversing
        while( temp -> next != NULL )
        {
            temp = temp -> next;        // Pointer becomes the next pointer
        }
        temp ->next = n;   // Update the value to which temp of next is pointing to
    }
    public:
    void InsertAtHead(Node* &head, int val)
    {
        Node* n = new Node(val);
        n -> next = head;                     // New Node next is pointing head
        head = n;
    }
    public:
    void Display(Node* &head)
    {
        Node* temp = head;          // Temporary pointer created pointing as head
        while (temp != NULL)        // While temp reaches the end of the list
        {
            cout << temp -> data << " -> ";
            temp = temp -> next;               // Pointer is moved towards the next
        }
        cout << "Null" << endl;
    }
    public:
    void FindNodeInList(Node* head, int key)          // Searching an element in a List
    {
        Node* temp = head;              // Temporary pointer created pointing as head
        int c = 0;int iter = 0;         // Iterator and checking variables
        while(temp != NULL)
        {
            iter = iter + 1;            // Updating iterator variable
            if(key == temp -> data)     // Checking Node data
            {
                c = c + 1;
                cout << "Search Successful !!" << endl;
                cout << "The element is present at " << iter << " position !!" << endl;
            }
            temp = temp -> next;        // Moving pointer to next
        }
        if( c != 1 )
        {
            cout << "Search Unsuccessful !!" << endl;
        }
    }
    void DeleteNodeAtHead(Node* &head)
    {
        Node* todelete = head;    // Temporary delete Node copied
        head = head -> next;      // Head shifted to next Node pointer
        cout << "The Node " << todelete -> data << " is deleted !" << endl;
        delete todelete;
    }
    void DeleteNode(Node* &head, int val)
    {
        if ( head == NULL )  // If the List is Empty
        { return; }
        if ( head -> next == NULL)  // If there is only one Node
        {
            DeleteNodeAtHead(head);  // Function of delete head called
            return;
        }
        Node* temp = head;
        while(temp -> next -> data != val)   // while n-1 Node successor data is matched
        {
            temp = temp -> next;        // Updating the pointer to the next Node
        }
        Node* todelete = temp -> next;    // Creating a Copy of the Node to be deleted
        cout << "The Node " << todelete -> data << " is deleted !" << endl;
        temp -> next = temp -> next -> next;  // Setting n-1 pointer to n+1 pointer
        delete todelete;  // Node is deleted from the Memory
    }
    Node* ReverseListByIteration(Node* &head)
    {
        if ( head == NULL || head -> next == NULL)
            return head;
        Node* previous = NULL;
        Node* current = head;
        Node* successor;
        while(current != NULL)
        {
            successor = current -> next;
            current -> next = previous;
            previous = current;
            current =  successor;
        }
        return previous;
    }
};                // Linked List class ends
int main()
{
    Node* head = NULL;  // Head in the beginning specified to Null
    LinkedList object;  // Object creation of Linked List
    int x, a;
    cout << "Enter number of nodes in the Singly Linked List : ";
    cin >> x;
    for(int i = 1; i <= x; i++)
    {
        cout << "Enter value for the Node : ";
        cin >> a;
        object.InsertAtTail(head, a);
        cout << endl;
    }
    object.Display(head);
    cout << "Enter any element to be Searched : ";
    cin >> x;
    object.FindNodeInList(head, x);
    cout << "Enter any element to delete : ";
    cin >> x;
    object.DeleteNode(head, x);
    object.Display(head);
    Node* newhead = object.ReverseListByIteration(head);
    cout << "The Reversed List by Iteration is provided below : " << endl;
    object.Display(newhead);
}