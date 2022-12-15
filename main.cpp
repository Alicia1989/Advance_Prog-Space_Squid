#include <iostream> //cin,cout
#include <conio.h> //getch()
#include <windows.h> //set screen size + disable cursor
using namespace std;

class list{
private:
    struct node{    //linklist node
        char data;  //data of node
        node *next; //pointer to next node
    };
    node *head; //start node of linklist
public:
    list(){ //default constructor
        head=NULL;  //initially no node in list     
    }
    void push_front(int new_data){ 
        if(head==NULL){ //if no node in list
            node *new_node = new node;  //create new node
            new_node->data = new_data;  //fill data
            new_node->next = NULL;  // no next node because this is supposed to be last node
            head = new_node;    //add firest node to list
        }else{
            node *last_node = head; //otherwise find last node nad attach new node after this last node
            while(last_node->next!=NULL)
            {
                last_node = last_node->next;
            }
            node *new_node = new node;
            new_node->data = new_data;
            new_node->next = NULL;
            last_node->next = new_node;
        }
    }

    void push_back(int new_data){
        if(head==NULL){
            node *new_node = new node;
            new_node->data = new_data;
            new_node->next = NULL;
            head = new_node;
        }else{  //this is supposed to be first node so attach is before head
            node *new_node = new node;
            new_node->data = new_data;
            new_node->next = head; //and then make it head of list
            head = new_node;
        }
    }

    char pop_front()//[d|n]->[d|n]->[d|N]
    {
         node *last_node = head;   //start looking for last node
         node *sec_last_node = head;
        while(last_node->next!=NULL)
        {
            sec_last_node = last_node;
            last_node = last_node->next;
        }
        char this_data = last_node->data;   //copy data of last node
        sec_last_node->next=NULL;   //delete last node
        return this_data;   //retun data of last node
    }

    char pop_back()//[d|n]->[d|n]->[d|N]
    {
        char this_data = head->data;    //copy data of head and then delete head
        head=head->next;
        return this_data;
    }

    void print_list(){
        node *current_node = head; //start from head and print all nodoes
        while(current_node!=NULL)
        {
            cout<<current_node->data;
            current_node = current_node->next;
        }
        cout<<endl;
    }
};

int main()
{
    list squid_list;
    squid_list.push_back('a');
    squid_list.push_back('b');
    squid_list.push_back('c');
    squid_list.push_back('d');
    squid_list.print_list();
    return 0;
}