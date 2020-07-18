#ifndef _STACK_H_
#define _STACK_H_

class UnderflowStack
{
	friend ostream& operator<<(ostream& os, const UnderflowStack& u)
	{
		return os << "Underflow!";
	}
};

template <typename T> class Stack
{
private:
	struct Elem
	{
		T info;
		Elem *next;
		Elem(const T& infoo, Elem *nextt = nullptr) : info(infoo), next(nextt)
		{

		}
	};
	Elem *top;
public:
	Stack()
	{
		top = nullptr;
	}

	friend void push(Stack& stack, T t)
	{
		Elem *e = new Elem(t, stack.top);
		stack.top = e;
	}

	friend T pop(Stack& stack)
	{
		if (!stack.top)
		{
			throw UnderflowStack();
		}
		Elem *p = stack.top;
		stack.top = stack.top->next;
		T t = p->info;
		delete p;
		return t;
	}

	bool notEmpty() const
	{
		return top;
	}
};

#endif