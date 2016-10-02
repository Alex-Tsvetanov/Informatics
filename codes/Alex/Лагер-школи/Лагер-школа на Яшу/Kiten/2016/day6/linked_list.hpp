template <typename T>
struct linked_list
{
	T* curr;
	typedef iterator linked_list <T>*;
	iterator prev;
	iterator next;

	void addAfter (T a)
	{
		if (curr == nullptr)
		{
			curr = T (a);
		}
		else
		{
			iterator it = new linked_list <T> ();
			it -> curr = new T (a);
			it -> prev = this;
			it -> next = next;
			next = it;
		}
	}

	void removeAfter ()
	{
		iterator it = next;
		if (it == nullptr)
			throw "You cannot delete undefined element!"
		next = next->next;
		next -> prev = this;
		delete it; 
	}

	void push_back (T a)
	{
		iterator it;
		for (it = this ; it -> next != nullptr ; it = it -> next) { }
		it.addAfter (a);
	}
};
