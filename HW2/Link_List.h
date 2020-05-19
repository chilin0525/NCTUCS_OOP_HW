#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

template <typename T>
struct Int_Node
{
	T value;
	Int_Node<T> *pre, *next;
	Int_Node() : pre(0), next(0){};
	Int_Node(T inputnumber) : value(inputnumber), pre(0), next(0){};
};

template <typename T>
class Link_List
{
	template <typename U>
	friend ostream &operator<<(ostream &, const Link_List<U> &);  	// print all integers in the list
	template <typename U>
	friend istream &operator>>(istream &, Link_List<U> &);			// input a value at the back of the list, like insert_node(val);

public:
	Link_List();										// default constructor
	Link_List(const Link_List &);						// copy constructor
	~Link_List();
	int getSize() const;

	const Link_List &operator=(const Link_List &);		// assignment operator
	bool operator==(const Link_List &) const;			// equality operator
	bool operator!=(const Link_List &right) const		// inequality operator
	{
		return !(*this == right);
	}

	T &operator[](int index);							// subscript operator for non-const objects
	T operator[](int index) const;						// subscript operator for const objects

	bool insert_node(T value);							// insert an integer at the back of link list
	bool delete_node();									// delete the last node
	bool insert_node(int index, T value);				// insert an integer after the i_th position
	bool delete_node(int index);						// delete the i_th node

private:
	int size;
	Int_Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};

template <typename U>
ostream &operator<<(ostream &ouput, const Link_List<U> &temp){
    Int_Node<U> *current = temp.head;
    while(current!=NULL){
        ouput << current->value << " ";
        current = current->next;
    }
    return ouput;
}

template <typename T>
istream &operator>>(istream &input, Link_List<T> &temp){
    T aa;
    input >> aa;
    Int_Node<T> *newnode = new Int_Node<T>(aa);

    if(temp.head==NULL&&temp.tail==NULL){
        temp.head = newnode;
        temp.tail = newnode;
        temp.size = 1;
        return input;
    }
   
        Int_Node<T> *current = temp.head;
        while(current->next!=0){
            current = current->next;
        }
        newnode->pre = current;
        current->next = newnode;
        temp.tail = newnode;
        temp.size++;
        return input;
    
}

//constructors,destructors...
template <typename T>
Link_List<T>::Link_List() : head(0),tail(0),size(0){};

template <typename T>
Link_List<T>::~Link_List() {};

template <typename T>
Link_List<T>::Link_List(const Link_List &temp){
    *this = temp;
}

template <typename T>
int Link_List<T>::getSize() const{
    return this->size;
}

//operatot overloading 
template <typename T>
const Link_List<T> &Link_List<T>::operator=(const Link_List &temp){

	 Int_Node<T> *current=temp.head;
	this->head=0;
	this->tail=0;
    int num = temp.size;


    for (int i = 0; i < num;i++){
        this->insert_node(current->value);
        current=current->next;
    }
    
    return *this;
}

template<typename T>
bool Link_List<T>::operator==(const Link_List &temp) const{
	int rec=1;
    if(this->size!=temp.size){
        return false;
    }
    for (int i = 0; i < this->size; i++){
        if((*this)[i]!=temp[i]){
            rec=0;
        }
    }
    if(rec){
    	return true;
	 }
	 else{
	 	return false;
	 }
}


template<typename T>
T &Link_List<T>::operator[](int index){
    Int_Node<T> *current = head;
    for (int i = 0; i < index;i++){
        current = current->next;
    }
    return current->value;
}		

template<typename T>
T Link_List<T>::operator[](int index)const {
    Int_Node<T> *current = head;
    for (int i = 0; i < index;i++){
        current = current->next;
    }
    return current->value;
}		

//insert from back!!!
template <typename T>
bool Link_List<T>::insert_node(T value){
    Int_Node<T> *newnode= new Int_Node<T>(value);
    
    if(head==NULL&&tail==NULL){
        head = newnode;
        tail = newnode;
        size = 1;
        return true;
    }

    Int_Node<T> *current = head;
    while(current->next!=0){
        current = current->next;
    }
    newnode->pre = current;
    current->next = newnode;
    tail = newnode;
    size++;
    return true;
    
}

//delete from back!!
template <typename T>
bool Link_List<T>::delete_node(){
    if(head==NULL && tail==NULL){
        return false;
    }

    else if(head==tail){    //?€æ·?¯åŠ?å??å? 
		  delete head;
        size--;
        head = NULL;  //?å?0?¿å??ºé¯
        tail = NULL;
		  return true;
    }
    else{
        Int_Node<T> *current = tail;
        tail = tail->pre;
        delete current;
        tail->next=0;
        current=NULL;
        size--;
        return true;
    }
}

template <typename T>
bool Link_List<T>::insert_node(int index, T value){
    Int_Node<T> *newnode = new Int_Node<T>(value);
    Int_Node<T> *current = head;

    while(--index){
        current = current->next;
    }

    newnode->pre = current;
    newnode->next = current->next;
    current->next->pre = newnode;
    current->next = newnode;
    size++;
    return true;
}

template <typename T>
bool Link_List<T>::delete_node(int index){
    Int_Node<T> *current = head;
    while(--index){
        current = current->next;
    }
    current->pre->next = current->next;
    current->next->pre = current->pre;
    delete current;
    current = NULL;
    size--;
    return true;
}


#endif // LINK_LIST
