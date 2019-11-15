#include "set.hpp"

// Default constructor
Set::Set()
{
	head = new Node(0, nullptr); //dummy node
}

// Constructor for creating a set from an int
Set::Set(int v)
{
	head = new Node(0, nullptr);
	insert(head, v);
}

// Constructor creating a set
// a non-sorted array of n intgers
Set::Set(const int a[], int n)
{
	head = new Node(0, nullptr);

	for (int i = 0; i < n; i++) {
		Node* p = head; //rätt pekare?

		while ((p->next != nullptr) && (a[i] > (p->next->value))) { //lägg till villkor att a[i]>p->next value

			p = p->next; //p hoppar fram ett steg

		}
		insert(p, a[i]); //sätt in ny node efter p
	}
}

// copy constructor
Set::Set(const Set& source)
{
	head = new Node(0, nullptr);
	Node* p1 = source.head->next;
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

	while (p->next != nullptr) {
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
	while ((p != nullptr) && p->value != x) {
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
	//Set R{ s };
	//return R;  // to be deleted

	/*head = new Node(0, nullptr);
	Node* p1 = s.head->next;
	Node* p2 = head;

	while (p1 != nullptr) {
		insert(p2, p1->value);
		p1 = p1->next;
		p2 = p2->next;
	}*/

	Set R(s);
	std::swap(head, R.head);
	return *this;
	
}

bool Set::operator<=(const Set& b) const
{
	// Add code
	return false;  // to be deleted
}

bool Set::operator==(const Set& b) const
{
	// Add code
	return false;  // to be deleted
}

bool Set::operator!=(const Set& b) const
{
	// Add code
	return false;  // to be deleted
}

bool Set::operator<(const Set& b) const
{
	// Add code
	return false;  // to be deleted
}

// Set union
// Repeated values are not allowed
Set Set::operator+(const Set& b) const
{
	//Set T{}; //skapar empty set

	//Node* pr = this->head;
	//Node* ps = b.head;
	//Node* pt = T.head;

	//while (pr != nullptr && ps != nullptr) {
	//	if (pr->value < ps->value) {
	//		T.insert(pt, pr->value);
	//		pt = pt->next;
	//		pr = pr->next;
	//	}
	//	else if (pr->value == ps->value) {
	//		T.insert(pt, pr->value);
	//		pt = pt->next;
	//		pr = pr->next;
	//		ps = ps->next;
	//	}
	//	else {
	//		T.insert(pt, ps->value);
	//		pt = pt->next;
	//		ps = ps->next;
	//	}
	//}

	//if (pr == nullptr) {
	//	while (ps != nullptr) {
	//		T.insert(pt, ps->value);
	//		pt = pt->next;
	//		ps = ps->next;
	//	}
	//}
	//else {
	//	while (ps != nullptr) {
	//		T.insert(pt, pr->value);
	//		pt = pt->next;
	//		pr = pr->next;
	//	}
	//}

	Set T{ b };

	Node* pt = T.head;
	Node* p = this->head->next; 

	while (p != nullptr) {

		while ((pt->next != nullptr) && (p->value > pt->next->value)) {
			pt = pt->next;
		}

		if (T.member(p->value)) { //om värdena lika
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
	// Add code
	return *this;  // to be deleted
}

// Set difference
Set Set::operator-(const Set& b) const
{
	// Add code
	return *this;  // to be deleted
}

// Set union with set {x}
Set Set::operator+(int x) const
{
	// Add code
	return *this;  // to be deleted
}

// Set difference with set {x}
Set Set::operator-(int x) const
{
	// Add code
	return *this;  // to be deleted
}

// Insert a new node after node pointed by p
	// the new node should store value
void Set::insert(Node* p, int value) const {
	Node* newNode = new Node(value, p->next);
	p->next = newNode;
}

// Remove the node pointed by p
void Set::remove(Node* p) {
	/*Node* p2 = head;

	while (p2->next != p) {
		p2 = p2->next;
	}

	p2->next = p->next;
	delete p;*/

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
