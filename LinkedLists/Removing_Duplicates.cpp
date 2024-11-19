#include<iostream>
#include<unordered_set>
using namespace std;

class Node{
    public:
      int val;
      Node* next;
    Node(int val){
        this->val =  val;
        next = NULL;
    };
};

class LinkedList{
    private:
      Node* head;
      
    public:
      void NewElement(int data){
          Node* newNode = new Node(data);
          if(!head){
              head = newNode;
              return;
          }
          Node* temp = head;
          while(temp->next != nullptr){
              temp = temp->next;
          }
          temp->next = newNode;
      }
      
      void printList(){
          Node* temp = head;
          while(temp != NULL){
              
              cout<<temp->val<<"->";
              if(temp->next == NULL)
                 cout<<"NULL"<<endl;
              temp = temp->next;
          }
      }
      
      void Deleteduplicates(){
          Node* temp = head;
          while(temp != NULL){
              Node* pointer = temp;
              while(pointer->next != NULL){
                  if(pointer->next->val == temp->val){
                      // logic to delete the node;
                      Node* duplicate = pointer->next;
                      pointer->next  = duplicate->next;
                      delete duplicate;
                  }
                  else
                    pointer = pointer->next;
              }
              temp = temp->next;
          }
      }
      
      void Delete_Hash(){
          unordered_set<int>Track;
          Node* prev = NULL;
          Node* curr = head;
          
          while(curr!= NULL){
              if(Track.find(curr->val) != Track.end()){
                  // dup found
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                
              }
              else{
                  Track.insert(curr->val);
                  prev = curr;
                  curr = curr->next;
              }
          }
      }
};
int main(){
    LinkedList l1;
    l1.NewElement(5);
    l1.NewElement(2);
    l1.NewElement(3);
    l1.NewElement(5);
    l1.NewElement(1);
    l1.NewElement(1);
    
    l1.printList();
    l1.Delete_Hash();
    l1.printList();
    return 0;
}

    
    