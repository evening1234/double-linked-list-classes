#include <iostream>
#include <time.h>
using namespace std;


class Node {
private:
    int data;
    char sign;
    Node *next;
    Node *prev;
    public:
    Node(int v, char d,Node *next = nullptr, Node *prev = nullptr) {
        this->data = v;
        this->sign = d;
        this->next = next;
        this->prev = prev;
    }
    int getData(){return this->data;}
    void setData(int x){this->data = x;}
    int getSign(){return this->sign;}
    void setSign(char x){this->sign = x;}
    Node *getNext(){return this->next;}
    Node *getPrev(){return this->prev;}
    void setNext(Node *n){this->next = n;}
    void setPrev(Node *p){this->prev = p;}

};

class List {
    private:
    Node *head;
    Node *tail;
    int size;
    public:
    List() {this->head = nullptr; this->tail = nullptr; size = 0;};
    ~List() {}
    Node *getHead(){return this->head;}
    Node *getTail(){return this->tail;}
    int getSize(){return size;}
    void setSize(int s){this->size = s;}
    //pushFront()
    void pushFront(int value, char d) {
        if (this->head == nullptr) {
            this->head = new Node(value, d,nullptr,nullptr);
            this->tail = this->head;
        } else {
            Node *newNode = new Node(value, d,this -> head, nullptr);
            this->head->setPrev(newNode);
            this->head = newNode;

        }
        setSize(size = size + 1);
    }
    //pushBack()
    void pushBack(int value, char d) {
        if (this->tail == nullptr) {
            this->tail = new Node(value, d, nullptr,nullptr);
            this->head = this->tail;
        } else {
            Node *newNode = new Node(value, d, nullptr, this -> tail);
            this->tail->setNext(newNode);
            this->tail = newNode;
        }
        setSize(size = size + 1);
    }
    void popFront() {
        if (this->head == nullptr) {
            cout << "The list is empty" << endl;
        } else {
            Node *tmp;
            tmp = this -> head;
            head = this -> head->getNext();
            head->setPrev(nullptr);
          //  delete tmp;
        }
        setSize(size = size - 1);
    }
    void popBack() {
        if (this->head == nullptr) {
            cout << "The list is empty" << endl;
        } else {
            Node *tmp;
            tmp = this -> tail;
            tail = this -> tail->getPrev();
            tail->setNext(nullptr);
          //  delete tmp;
        }
        setSize(size = size - 1);
    }
    void add(int x) {
        cout<<"start list"<<endl;
        for (int i = 0; i < x; i++) {
            pushFront(i,'t');
        }
    }
    void printAll() {
        Node *tmp = this->head;
        while (tmp != nullptr) {
            cout << tmp->getData()<<" "<< tmp->getSign() <<endl;
            tmp = tmp -> getNext();
        }
        cout << "size: " << getSize() << endl;
      //  delete tmp;
    }
    void findNode() {
        int x;
        cout<<"Enter the data to find: ";
        cin>>x;
        Node *tmp;
        tmp = this->head;
        while (tmp != nullptr){
            if(x == tmp->getData()) {
                cout <<"your Node: " <<tmp->getData() <<endl;
                break;
            }
            tmp = tmp -> getNext();
        }
        if(tmp == nullptr) {
            cout<<"No data found"<<endl;
        }
        //delete tmp;
    }
    void setNode() {
        int x;
        int y;
        cout<<"Enter the data to change: ";
        cin>>x;
        cout<<"Enter new data: ";
        cin>>y;
        Node *tmp;
        tmp = this->head;
        while (tmp != nullptr){
            if(x == tmp->getData()) {
                tmp->setData(y);
                cout <<"your new Node: " <<tmp->getData() <<endl;
                break;
            }
            tmp = tmp -> getNext();
        }
        if(tmp == nullptr) {
            cout<<"No data found"<<endl;
        }
        //delete tmp;
    }
    void removeNode() {
        int x;
        cout<<"Enter the data to remove: ";
        cin>>x;
        Node *tmp;
        tmp = this->head;
        while (tmp != nullptr){
            if(x == tmp->getData()) {
                Node *killer;
                killer = killer -> getNext();
                killer->setPrev(tmp->getPrev());
                killer = tmp;
                killer = killer -> getPrev();
                killer -> setNext(tmp->getNext());
                tmp->setNext(nullptr);
                tmp->setPrev(nullptr);
                delete tmp;
                cout <<"Node removed: "<<endl;
                setSize(size = size - 1);
                break;
            }
            tmp = tmp -> getNext();
        }
        if(tmp == nullptr) {
            cout<<"No data found"<<endl;
        }
    }
    void removeAll(List *list) {
        if(list->head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }
        for(Node *tmp = list->head->getNext(); tmp != nullptr; tmp = tmp -> getNext()){
           head -> setNext(nullptr);
            head = tmp;
            delete (tmp -> getPrev());
            tmp ->setPrev(nullptr);
            setSize(size = size - 1);
        }
        delete list->head;
        list->head = nullptr;
        list->tail = nullptr;
        setSize(size = size - 1);
        cout<<"The list is empty"<<endl;
    }
    };






int main()
{
    //TODO clear memory

    List *list = new List();
    clock_t t1 = clock();//start
    list->add(100);
    list->printAll();
    list->removeAll(list);
    list->printAll();
    clock_t t2 = clock();
    double time_spent = (double)((t2 - t1)*100)/CLOCKS_PER_SEC;
    cout<<"Time spent for 100 node: "<<time_spent<<endl;

    List *list2 = new List();
    clock_t t3 = clock();//start
    list2->add(1000);
    list2->printAll();
    list2->removeAll(list2);
    list2->printAll();
    clock_t t4 = clock();
    double time_spent2 = (double)((t4 - t3)*100)/CLOCKS_PER_SEC;
    cout<<"Time spent for 1000 node: "<<time_spent2<<endl;

    List *list3 = new List();
    clock_t t5 = clock();//start
    list3->add(10000);
    list3->printAll();
    list3->removeAll(list3);
    list3->printAll();
    clock_t t6 = clock();
    double time_spent3 = (double)((t6 - t5)*100)/CLOCKS_PER_SEC;
    cout<<"Time spent for 10000 node: "<<time_spent3<<endl;

    //TODO List list; vs List *list = new list();
    List list6;

    // List *list = new List();
    // list->add(100);
    // list->printAll();
    // list->removeAll(list);
    // list->printAll();
    return 0;
}
