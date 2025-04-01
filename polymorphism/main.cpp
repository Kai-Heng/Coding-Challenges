#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
    public:
     LRUCache(int capacity){
        cp = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
     }
     
     void set(int a, int b) override{
        if(mp.count(a) == 0){
            Node *n = new Node(head, head->next, a,b);
            head->next->prev = n;
            head->next = n;
            
            mp.insert(pair<int, Node*>(a, n));
        }
        else{
            Node *existing_node = mp[a];
            existing_node->value = b;
            existing_node->prev->next = existing_node->next;
            existing_node->next->prev = existing_node->prev;
            
            existing_node->next = head->next;
            existing_node->prev = head;
            head->next->prev = existing_node;
            head->next = existing_node;
            
            mp[a] = existing_node;
        }
        
        if(mp.size() > cp){
            Node *least_node = tail->prev;
            tail->prev = least_node->prev;
            least_node->prev->next = tail;
            
            mp.erase(least_node->key);
        }
     }
     
     int get(int a) override{
        if(mp.count(a) != 0){
            return mp[a]->value;
        }
        return -1;
     }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
