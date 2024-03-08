#include<iostream>

template <typename T>
class Stack {
	private:
		int MAXSIZE = 10;
		int size = 0;

		class Node {
			public:
				T data;
				Node* next;

				Node(T d, Node* n) {
					data = d;
					next = n;
				}
		};

		Node* head = nullptr;
	public:
		void Push(T item) {
			if (!IsFull()) {
				Node* curr = new Node (item, head);
				head = curr;
				size++;
			} else {
				std::cout << "Error: Stack is full." << std::endl;
			}
		}

		void Pop() {
			if (!IsEmpty()) {
				Node* tmp = head;
				head = head->next;
				size--;
				delete tmp;
			} else {
				std::cout << "Error: Stack is empty." << std::endl;
			}
		}

		T Top() {
			try {
				T topItem;
				if (!IsEmpty()) {
					topItem = GetTop();
				} else {
					throw(topItem);
					//throw runtime_error("Cannot call Top on an empty Stack.");
				}
			}

			catch (T nonItem) {
				std::cout << "Error: Cannot call Top on an empty Stack" << std::endl;
			}
		}

		bool IsEmpty() {
			if (size == 0) {
				return true;
			} else {
				return false;
			}
		}

		bool IsFull() {
			if (size < MAXSIZE) {
				return false;
			} else {
				return true;
			}
		}

		//Function to display Stack
		void PrintStack() {
			Node* curr = head;
			if (head != nullptr){
				std::cout  << "Stack data: (" << curr->data;
				while (curr->next != nullptr){
					std::cout << ", " << curr->next->data;
					curr = curr->next;
				}
				std::cout << ")" << std::endl;
			}
			else {
				std::cout << "The stack is empty" << std::endl;
			}
		}

		//function to return a Stack in the reversed order
		Stack<T> RevStack() {
			Stack<T> reversed;
			
			Reverse(reversed);
			return reversed;
		}

	private:
		//function to take item in original stack and copy the top item to reversed stack and pop until empty
		void Reverse(Stack<T>& rev) {
			if(!IsEmpty()) {
				T item;

				item = GetTop();
				Pop();
				rev.Push(item);
				Reverse(rev);
			}
		}

		T GetTop() {
			return head->data;
		}
		
};
