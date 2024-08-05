#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	T value;
	Node* next;
	Node* prev;

	Node(T value, Node* next = nullptr, Node* prev = nullptr) : value{ value }, next{ next }, prev{ prev }
	{}
};

template <typename T>
class doublell
{
private:
	int size;
	Node<T>* head;
	Node<T>* tail;
public:
	doublell() : size{ 0 }, head{ nullptr }, tail{ nullptr }
	{}

	~doublell()
	{
		Node<T>* current = head;

		while (current != nullptr)
		{
			Node<T>* tmp = current;
			current = current->next;
			delete tmp;
		}

		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void AddToHead(T value)
	{
		Node<T>* newNode = new Node<T>(value, head);
		if (head != nullptr) {
			head->prev = newNode;
		}
		else {
			tail = newNode;
		}
		head = newNode;
		size++;
	}
	void AddToTail(T value)
	{
		if (!head)
		{
			head = new Node<T>(value);
			tail = head;
			size++;
			return;
		}

		Node<T>* newNode = new Node<T>(value);
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		size++;

	}

	void DeleteFromHead() {
		if (size == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			size = 0;
			return;
		}

		Node<T>* tmp = head;
		head = head->next;
		delete tmp;
		size--;
	}
	void DeleteFromTail() {
		if (size == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			size = 0;
			return;
		}
		Node<T>* tmp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete tmp;
		size--;
	}

	void DeleteAll() {
		Node<T>* current = head;
		while (current!=nullptr)
		{
			Node<T>* temp = current;
			current = current->next;
			delete temp;
		}
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void Show() {
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}cout << endl;
	}

	void AddTo(T value, int ind) {
		Node<T>* newNode = new Node<T>(value);

		if (ind == 0) {
			newNode->next = head;
			if (head != nullptr) {
				head->prev = newNode;
			}
			head = newNode;
			if (size == 0) {
				tail = newNode;
			}
		}
		else if (ind == size) {
			newNode->prev = tail;
			if (tail != nullptr) {
				tail->next = newNode;
			}
			tail = newNode;
			if (size == 0) {
				head = newNode;
			}
		}
		else
		{
			Node<T>* temp = head;
			for (int i = 0; i < ind - 1; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next->prev = newNode;
			temp->next = newNode;
		}
		size++;
	}
	void deleteFrom(int ind) {
		if (ind == 0) {
			Node<T>* temp = head;
			head = head->next;
			if (head != nullptr) {
				head->prev = nullptr;
			}
			else {
				tail = nullptr;
			}
			delete temp;
		}
		else if (ind == size - 1) {
			Node<T>* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete temp;
		}
		else {
			Node<T>* temp = head;
			for (int i = 0; i < ind; i++) {
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}

		size--;
	}

	int FindV(T value) {
		Node<T>* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->value==value)
			{
				return ++i;
			}
			current = current->next;
		}
		return NULL;
	}
	int FindandSwap(T valueF, T valueS) {
		Node<T>* current = head;
		int coutofswaps = 0;
		while (current!=nullptr)
		{
			if (current->value==valueF)
			{
				current->value = valueS;
				coutofswaps++;
			}
			current = current->next;
		}
		return coutofswaps;
	}
};


int main()
{
	doublell<int> list;
	list.AddToHead(2);
	list.AddToHead(3);
	list.AddToTail(1);
	list.AddToTail(0);
	list.Show();
	list.DeleteFromHead();
	list.DeleteFromTail();
	list.Show();
	list.AddTo(10, 1);
	list.Show();
	list.deleteFrom(1);
	list.Show();
	cout << "index of value : " << list.FindV(1) << endl;
	list.AddToHead(3);
	list.AddToHead(3);
	list.AddToHead(3);
	list.Show();
	cout << "cout of swap" << list.FindandSwap(3, 0) << endl;
	list.Show();
}