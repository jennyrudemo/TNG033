#include "set.hpp"

// Default constructor
Set::Set(): head{new Node(0, nullptr)} //creates empty set with dummy node
{
    
}

// Constructor for creating a set from an int
Set::Set(int v): head{ new Node(0, nullptr)}
{
	insert(head, v);
}

// Constructor creating a set
// a non-sorted array of n intgers
Set::Set(const int a[], int n): head{new Node(0, nullptr)}
{
	for (int i = 0; i < n; i++) {
        
		Node* p = head; //p pekar pŒ dummy node
        
		while ((p->next != nullptr) && (a[i] > (p->next->value))) {
			p = p->next; //p hoppar fram ett steg
		}
        
		insert(p, a[i]); //sŠtt in ny node efter p
	}
}

// copy constructor
Set::Set(const Set& source): head{new Node(0, nullptr)}
{
	Node* p1 = source.head->next; // node to copy
	Node* p2 = head;

	while (p1 != nullptr) {
		insert(p2, p1->value);
		p1 = p1->next;
		p2 = p2->next;
	}
}

// Destructor: deallocate all nodes
Set::~Set()
{
	Node* p = head;

	while (p != nullptr) {
		head = p->next;
		delete p;
		p = head;
	}
}

// Test if set is empty
bool Set::empty() const
{
	if (head->next == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

// Return number of elements in the set
int Set::cardinality() const
{
	int howMany = 0;

	Node* p = head->next;

	while (p != nullptr) {
		howMany++;
		p = p->next;
	}

	return howMany;
}

// Test if x is an element of the set
bool Set::member(int x) const
{
	Node* p = head->next;

	while ((p != nullptr) && (p->value != x)) {
		p = p->next;
	}

	if (p == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

// Assignment operator
Set& Set::operator=(Set s)
{
	//Set R(s);
	std::swap(head, s.head);
	return *this;
	
}

bool Set::operator<=(const Set& b) const
{
    Node* p = head->next;
    
    while(p != nullptr) {
        if(!(b.member(p->value))) {
            return false;
        }
        p = p->next;
    }
    
	return true; 
}

bool Set::operator==(const Set& b) const
{
    //Testa om this är en delmängd av b
	if(*this<=b){
        if(b<=*this) return true; //Testa om b är delmängd av this
    }
    return false;
}

bool Set::operator!=(const Set& b) const
{
    if(*this==b) return false; //Testa om this och b är samma mängd
	return true;
}

bool Set::operator<(const Set& b) const
{
    if(*this<=(b)){
        if(!(b<=*this)) return true; //Testa om b är delmängd av b (kan också testa om b==*this)
    }
	return false;
}

// Set union
// Repeated values are not allowed
Set Set::operator+(const Set& b) const
{
	Set T{ b };

	Node* pt = T.head;
	Node* p = this->head->next; 

	while (p != nullptr) {

		while ((pt->next != nullptr) && (p->value > pt->next->value)) {
			pt = pt->next;
		}

		if (T.member(p->value)) { //om vŠrdena lika
			p = p->next;
		}
		else { //om p->value < pt->next->value
			T.insert(pt, p->value);
		}
	}
	return T;
}

// Set intersection
Set Set::operator*(const Set& b) const
{
    Set T{};

    Node* pt = T.head; //pt pekar pŒ dummy node
    Node* p = head->next; //pekar pŒ noden efter dummy node

    while (p != nullptr){
        if(b.member(p->value)) {
            T.insert(pt, p->value);
            pt = pt->next; //pt pekar nu pŒ det tillagd objektet
        }
        p = p->next; //p gŒr fram ett steg
    }
	return T;
}

// Set difference
Set Set::operator-(const Set& b) const
{
	Set T{};

    Node* pt = T.head; //pt pekar pŒ dummy node
    Node* p = head->next; //pekar pŒ noden efter dummy node

    while (p != nullptr){
        if(!(b.member(p->value))) { //testar ifall p->value inte finns i b
            T.insert(pt, p->value);
            pt = pt->next; //pt pekar nu pŒ det tillagd objektet
        }
        p = p->next; //p gŒr fram ett steg
    }
    return T;
}

// Set union with set {x}
Set Set::operator+(int x) const
{
    Set R (x); //Skapa nytt set av x
    Set T = *this+R;
    
    return T;
}

// Set difference with set {x}
Set Set::operator-(int x) const
{
    Set R (x); //Skapa ett nytt set av x
    Set T = this->operator-(R); //dra ifrŒn det nya setet frŒn det nuvarande
	return T;
}

// Insert a new node after node pointed by p
	// the new node should store value
void Set::insert(Node* p, int value) const {
	Node* newNode = new Node(value, p->next);
	p->next = newNode;
}

// Remove the node pointed by p
void Set::remove(Node* p) {
	delete p;
	p = nullptr;
}



std::ostream& operator<<(std::ostream& os, const Set& theSet)
{
	if (theSet.empty())
	{
		os << "Set is empty!";
	}
	else
	{
		Set::Node* temp = theSet.head->next;
		os << "{ ";

		while (temp)
		{
			os << temp->value << " ";
			temp = temp->next;
		}
		os << "}";
	}

	return os;
}
