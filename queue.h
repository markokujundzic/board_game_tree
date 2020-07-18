#ifndef QUEUE_H_
#define QUEUE_H_

class UnderflowQueue
{
	friend ostream& operator<<(ostream& os, const UnderflowQueue& u)
	{
		return os << "Underflow!";
	}
};

template<typename T> class Queue
{
private:
	struct Elem
	{
		T info;
		Elem* next;
		Elem(T infoo, Elem* nextt = nullptr) : info(infoo), next(nextt)
		{

		}
	};
	Elem *front, *rear;

public:
	Queue()
	{
		front = rear = nullptr;
	}

	bool notEmpty() const
	{
		return front;
	}

	friend void insert(Queue& q, T t)
	{
		Elem* n = new Elem(t);
		if (!q.notEmpty())
		{
			q.front = q.rear = n;
		}
		else
		{
			q.rear = q.rear->next = n;
		}
	}

	friend T remove(Queue& q)
	{
		if (!q.notEmpty())
		{
			throw UnderflowQueue();
		}
		Elem* temp = q.front;
		q.front = q.front->next;
		T t = temp->info;
		delete temp;
		return t;
	}
};
#endif