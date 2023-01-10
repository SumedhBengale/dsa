// Probably has bugs

#include<iostream>

using namespace std;


    struct Node {
        int data;
        Node* next;
    };

    Node* head = NULL;


    void insertAtHead(){
        int x;
        cout << "Enter the Data" << endl;
        cin >> x;
        Node* temp = (Node*)malloc(sizeof(Node));
        temp -> data = x;
        temp -> next = head;
        head = temp; 

    };

    void insertAtBeginning(){
        if(head == NULL){
            int x;
            cout << "Enter the Data" << endl;
            cin >> x;
            Node* temp = (Node*)malloc(sizeof(Node));
            temp -> data = x;
            temp -> next = head;
            head = temp;
        }else{
            int x;
            cout << "Enter the Data" << endl;
            cin >> x;
            Node* ptr = head;
            while(ptr -> next != NULL){
                ptr = ptr -> next;
            }

            Node* temp = (Node*)malloc(sizeof(Node));
            temp -> data = x;
            temp -> next = NULL;
            ptr -> next = temp;

        }

    };

    void insertAtPosition(){
        //Assuming head position as 0
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        int x, position;
        cout << "Enter the Data and the Position from the Head" << endl;
        cin >> x, position;
        Node* ptr = head;
        for(int i = 0; i < position-1; i++){
            if(ptr -> next == NULL){
                cout << "Invalid Position" << endl;
                return;
            }
            ptr = ptr -> next;
        }

        Node* temp = (Node*)malloc(sizeof(Node));
        temp -> data = x;
        ptr -> next = temp;
        ptr = ptr -> next;
        temp -> next = ptr;

    };

    void deleteFromHead(){
        if(head == NULL){
            cout << "Cannot Delete From Head" << endl;
            return;
        }

        int x;
        cout << "Enter the Data" << endl;
        cin >> x;
        Node* temp = head;
        head = head -> next;
        free(temp);

    };

    void deleteFromBeginning(){

        if(head == NULL){
            cout << "Cannot delete from an Empty List" << endl;
            return;
        }

        Node* temp = head;
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }

        free(temp -> next);
        temp -> next = NULL;
    };

    void deleteFromPosition(){

        if(head == NULL){
            cout << "Cannot delete from an Empty List" << endl;
            return;
        }

        int x, distance;
        cout << "Enter the Data and the distance from the Head" << endl;
        cin >> x, distance;

        Node* temp = head;
        for(int i = 0; i < distance-1; i++){
            if(temp -> next == NULL){
                cout << "Invalid Position" << endl;
                return;
            }
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        free(temp -> next);

    };

    void viewAtPosition(){
        if(head == NULL){
            cout << "The list is Empty" << endl;
            return;
        }
        int distance;
        cout << "Enter the Position" << endl;
        cin >> distance;

        Node* temp = head;
        for(int i = 0; i < distance; i++){
            if(temp)
            temp = temp-> next;
        }
        cout << "The value at position " << distance << " is " << temp -> data << endl;

    };

    void viewCompleteList(){

        if(head == NULL){
            cout << "The List is Empty" << endl;
            return;
        }

        Node* temp = head;
        while(temp -> next != NULL){
            cout << temp-> data << " ";
            temp = temp -> next;
        }

    };


int main(){

    int choice  = 0;

    while (choice != -1){
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete from Head" << endl;
        cout << "5. Delete from Beginning" << endl;
        cout << "6. Delete from Position" << endl;
        cout << "7. View at Position" << endl;
        cout << "8. View Complete List" << endl;
        cout << "Enter your choice";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertAtHead();
            break;

        case 2:
            insertAtBeginning();
            break;
        
        case 3:
            insertAtPosition();
            break;
        
        case 4:
            deleteFromHead();
            break;
        
        case 5:
            deleteFromBeginning();
            break;
        
        case 6:
            deleteFromPosition();
            break;
        
        case 7:
            viewAtPosition();
            break;
        
        case 8:
            viewCompleteList();
            break;
        
        default:
            break;
        }
    }

}