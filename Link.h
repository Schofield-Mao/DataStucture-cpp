template <typename E> class Link{
public:
	E element;
	Link *next;

	Link(const E& eleval, Link* nextval =NULL)
	{
		element = eleval; 
		next = nextval;
	}
	Link(Link* nextval =NULL)
	{
		next = nextval;
	}
};