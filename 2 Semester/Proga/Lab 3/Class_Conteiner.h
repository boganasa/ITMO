#ifndef CLASS_CONTEINER_H 
#define CLASS_CONTEINER_H 
#include <iostream>

template <typename Type>
class Conteiner
{
public:
	class iterator;
	friend class iterator;

private:
	class Node;
	int length;
	friend class Node;

	class Node
	{
	public:
		friend class Conteiner<Type>;
		friend class iterator;

		Node(Type value) : val(value) {}
		Node() {}
		~Node() {}

		void print_val() { std::cout << val << " "; }

		Node* next; 
		Node* prev;
		Type val;

	};

public:
	class iterator
	{
		friend class Conteiner<Type >;

	public:
		iterator() :buf(0) {}
		iterator(Node* dn) : buf(dn) {}
		iterator(const iterator& it) : buf(it.buf) {}

		iterator& operator=(const iterator& it)
		{
			buf = it.buf;
			return *this;
		}

		bool operator == (const iterator& it) const
		{
			return (buf == it.buf);
		}


		bool operator!=(const iterator& it) const
		{
			return !(it == *this);
		}

		iterator& operator++()
		{
			buf = buf->next;
			return *this;
		}

		iterator& operator--()
		{
			buf = buf->prev;
			return *this;
		}

		iterator& operator--(int)
		{
			iterator tmp(*this);
			operator--();
			return tmp;
		}

		iterator& operator++(int)
		{
			iterator tmp(*this);
			operator++();
			return tmp;
		}


		iterator& operator-=(const int& k) 
		{
			iterator tmp = k;
			while (k > 0)
			{
				buf = buf->prev;
			}
			return *this;
		}

		iterator& operator+=(const int& k)
		{
			iterator tmp = k;
			while (k > 0)
			{
				buf = buf->next;
			}
			return *this;
		}

		iterator& operator-(const int& k) const {
			iterator tmp(*this);
			for (int i = 0; i < k; i++)
			{
				--tmp;
			}
			return tmp;
		}

		iterator& operator+(const int& k) const {
			iterator tmp(*this);
			for (int i = 0; i < k; i++)
			{
				++tmp;
			}
			return tmp;
		}

		Type& operator*() const
		{
			if (buf == 0)
				throw "tried to dereference an empty iterator";
			return buf->val;
		}

	private:
		Node* buf;
	};

private:
	Node* head;  //указывает на начало списка. 
	Node* tail;  //указывает на елемент, который идет за последним

	iterator head_iterator; //итератор, который всегда указывает на начало списка
	iterator tail_iterator; //итератор, который всегда указывает на элемент, который находится за последним.

public:
	Conteiner()
	{
		length = 0;
		head = new Node;
		tail = head;
		tail->next = nullptr;
		tail->prev = nullptr;

		head_iterator = iterator(head);
		tail_iterator = iterator(tail);
	}

	
	Conteiner(int len)
	{
		length = len;
		head = new Node; 
		tail = head;
		//head->prev = tail;
		//tail->next = head;
		tail->next = nullptr;
		tail->prev = nullptr;

		head_iterator = iterator(head);
		tail_iterator = iterator(tail);
		//add_front(value);
	}

	~Conteiner()
	{
		Node* node_to_delete = head;
		for (Node* i = head; i != tail;)
		{
			i = i->next;
			delete node_to_delete;
			node_to_delete = i;
		}

		delete node_to_delete;
		length = 0;
	}

	bool is_empty() { return head == tail; }


	iterator front() { return head_iterator; }
	iterator rear() { return tail_iterator; }

	//вставляем узел в начало списка
	void add_front(Type value)
	{
		if (size() < length)
		{
			Node* node_to_add = new Node(value);
			node_to_add->next = head;
			node_to_add->prev = tail;
			head->prev = node_to_add;
			head = node_to_add;
			tail->next = head;
			head_iterator = iterator(head);
		}
	}

	void add_rear(Type value)
	{
		if (size() == 0)
			add_front(value);
		else
		{
			if (size() < length)
			{
				Node* node_to_add = new Node(value);
				node_to_add->prev = tail->prev;
				tail->prev->next = node_to_add;
				node_to_add->next = tail;
				tail->prev = node_to_add;
				
			}
			else
			{
				Node* node_to_add = new Node(value);
				head = head->next;
				head->prev = tail;
				tail->next = head;
				node_to_add->prev = tail->prev;
				tail->prev->next = node_to_add;
				node_to_add->next = tail;
				tail->prev = node_to_add;
				head_iterator = iterator(head);
			}
		}
	}

	bool insert_after(Type value, const iterator& index)
	{
		for (Node* i = head; i != tail; i = i->next)
		{
			//Найден ли узел для заданного итератора
			if (i == index.buf)
			{
				Node* node_to_add = new Node(value);
				node_to_add->prev = i;
				node_to_add->next = i->next;
				i->next->prev = node_to_add;
				i->next = node_to_add;
				if (size() == length)
				{
					tail = head;
					head = head->next;
					tail_iterator = iterator(tail);
					head_iterator = iterator(head);
				}
				return true;
			}
		}
		return false;
	}

	//Удалить первый элемент списка. 
	Type remove_front()
	{
		if (is_empty())
			throw "tried to remove from an empty list";
		Node* node_to_remove = head;
		Type return_val = node_to_remove->val;
		head = node_to_remove->next;
		head->prev = tail;
		head_iterator = iterator(head);

		delete node_to_remove;
		return return_val;

	}

	Type remove_rear()
	{
		if (is_empty())
			throw "tried to remove from an empty list";

		Node* node_to_remove = tail->prev;

		if (node_to_remove->prev == 0)
		{
			return remove_front();
		}
		else
		{
			Type return_val = node_to_remove->val;
			node_to_remove->prev->next = tail;
			tail->prev = node_to_remove->prev;
			tail->prev->next = head;
			delete node_to_remove;
			return return_val;
		}
	}


	bool remove_it(iterator& index)
	{
		for (Node* i = head; i != tail; i = i->next)
		{
			//Найден ли узел для заданного итератора
			if (i == index + i.buf)
			{
				i->prev->next = i->next;
				i->next->prev = i->prev;
				delete i;
				index.buf = 0;
				return true;
			}
		}

		return false;
	}
 
	int size() const
	{
		int count = 0;
		Node* i = head;
		while ((i!= nullptr) && (i != tail))
		{
			++count;
			i = i->next;
		}
		return count;
	}

	void capacity(int len)
	{
		if (len < length)
		{
			int count = 0;
			Node* i = head;
			while (count < len)
			{
				++count;
				i = i->next;
			}
			tail = i;
			tail->next = head;
			head->prev = tail; 
			tail_iterator = iterator(tail);
			head_iterator = iterator(head);
		}
		length = len;
	}

	void print() const
	{
		for (Node* i = head; i != tail; i = i->next)
		{
			i->print_val();
		}

		std::cout << std::endl;
	}
};

#endif	
