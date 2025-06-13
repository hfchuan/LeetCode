#include <iostream>
#include <list>
#include <unordered_map>

struct DListNode{
    int key;
    int value;
    DListNode* prev;
    DListNode* next;
    DListNode(int k,int v) : key(k),value(v),prev(nullptr),next(nullptr){}


};

class LRUCache{
    private:
        int capacity;
        std::unordered_map<int,DListNode*> cache;
        DListNode* head;
        DListNode* tail;

        void moveToHead(DListNode* node){
            removeNode(node);
            addNode(node);
        }

        void addNode(DListNode* node){
            node->prev = head;
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
        }

        void removeNode(DListNode* node){
            DListNode* prevNode = node->prev;
            DListNode* nextNode = node->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }

        DListNode* popTail(){
            DListNode* res = tail->prev;
            removeNode(res);
            return res;
        }

    public:
        LRUCache(int capacity) : capacity(capacity){
            head = new DListNode(0,0);
            tail = new DListNode(0,0);
            head->next = tail;
            tail->prev = head;
        }

        int get(int key){
            if(cache.find(key) != cache.end()){
                DListNode* node = cache[key];
                moveToHead(node);
                return node->value;
            }
            return -1;
        }

        void put(int key,int value){
            if(cache.find(key) != cache.end()){
                DListNode* node = cache[key];
                node->value = value;
                moveToHead(node);
            }
            else{
                DListNode* newNode = new DListNode(key,value);
                cache[key] = newNode;
                addNode(newNode);
                if(cache.size() > capacity){
                    DListNode* tailNode = popTail();
                    cache.erase(tailNode->key);
                    delete tailNode;
                }
            }
        }

        ~LRUCache(){
            DListNode* current = head->next;
            while(current != nullptr){
                DListNode* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
};

int main(){

    return 0;
}