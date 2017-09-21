#include "Link.h"
#include <List>
#include <assert.h>
template <typename E> class LList: public Link<E>{
private:
	Link<E>* head;
	Link<E>* tail;
	Link<E>* curr;
	int cnt;

	void init() {
		curr = tail = head = new Link<E>;
	}

	void removeall() {
		while (head != NULL)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public:
	LList(int size=100) {init();}
	~LList() {removeall();}
	void print() const;
	void clear() {removeall();init();}

	void insert(const E& it){
		curr->next = new Link<E>(it,curr->next); 
		if(tail == curr) tail = curr->next;
		cnt++;
	}

	void append(const E& it){
		tail->next = new Link<E>(it);
		if(tail->next != NULL)
		tail = tail->next;
		cnt++;
	}

	E remove(){
		//Assert(curr->next != NULL, "No element");
		E it = curr->next->element;
		if(tail == curr->next)
			tail = curr;
		Link<E>* item = curr->next;
		curr->next = curr->next->next;
		cnt--;
		delete item;
		return it;
	}

	void move2start(){
		curr = head;}

	void move2end(){
		curr = end;}

	void prev(){
		if (curr == head)
			return;
		Link<E> item = item();
		item = head;
		while(item->next != curr)
		{
			item = item->next; 
		}
		curr = item;
	}

	void next(){
		if (curr != tail)
		curr = curr->next
		else
		//Assert("It is already the last element");
	}

	int currPos() const{
		Link<E> *item = head;
		int i = 0;
		for(i;item != curr;i++)
		{
			item = item->next;
		}
		return i;
	}

	void move2pos(int pos){
		//Assert(((pos>0)&&(pos<=cnt)),"OUT OF RANGE");
		curr = head;
		for(int i = 0;i != pos;i++)
		{
			curr = curr->next ;
		}
	}

	const E& getvalue() const
	{
		//Assert(curr->next!=NULL,"NO VALUE");
		return curr->next->element;	
	}

	void print() 
	{
		Link<E> *temp = head;
		while(temp!= tail)
		{
			cout << temp->next->element <<"|";
			temp = temp->next;
		}
	}
};