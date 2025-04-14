#include "Sequence.h"
#include <cassert>

namespace cs_sequence {
	Sequence::Sequence() {
		headPtr = tailPtr = cursor = precursor = nullptr;
		numItems = 0;
	}

	Sequence::Sequence(const Sequence& source) {
		copy(source);
	}

	Sequence::~Sequence() {
		clear();
	}

	Sequence& Sequence::operator=(const Sequence& source) {
		if (this != &source) {
			clear();
			copy(source);
		}
		return *this;
	}

	void Sequence::copy(const Sequence& source) {
		if (source.headPtr == nullptr) {
			headPtr = tailPtr = cursor = precursor = nullptr;
			numItems = 0;
			return;
		}

		//Perform a copy on the head
		node* copyHead = new node;
		this->headPtr = copyHead;
		this->headPtr->data = source.headPtr->data;
		this->headPtr->next = nullptr;

		//Copy the Nodes in the Sequence
		int cursorindex = 0;
		int currindex = 0;
		node* source_cursor = source.headPtr->next;
		node* newnode_precursor = copyHead;

		while (source_cursor != nullptr) {
			node* newnode = new node;
			newnode->data = source_cursor->data;
			newnode->next = nullptr;
			//link nodes together
			newnode_precursor->next = newnode;
			//update index
			currindex++;
			//find the source's cursor index
			if (source_cursor == source.cursor) {
				cursorindex = currindex;
			}
			//prepare for another node
			newnode_precursor = newnode;
			source_cursor = source_cursor->next;
		}
		//copy the tail
		this->tailPtr = newnode_precursor;

		//copy numItems
		this->numItems = source.numItems;

		//copy cursor over
		if (source.cursor != nullptr) {
			this->cursor = headPtr;
			for (int i = 0; i < cursorindex; i++) {
				this->precursor = cursor;
				cursor = cursor->next;
			}
			if (this->cursor == headPtr) {
				this->precursor = nullptr;
			}
		}
		else {
			this->cursor = nullptr;
			this->precursor = nullptr;
		}
	}

	void Sequence::clear() {
		node* current = headPtr;

		while (current != nullptr) {
			node* nextNode = current->next;
			delete current;
			current = nextNode;
		}

		headPtr = tailPtr = cursor = precursor = nullptr;
		numItems = 0;
	}

	void Sequence::start() {
		cursor = headPtr;
		precursor = nullptr;
	}

	void Sequence::advance() {
		assert(is_item() == true);
		precursor = cursor;
		if (cursor->next == nullptr) {
			cursor = nullptr;
		}
		else {
			cursor = cursor->next;
		}
	}

	void Sequence::insert(const value_type& entry) {

		node* new_node = new node;
		new_node->data = entry;
		numItems++;

		if (cursor == headPtr || cursor == nullptr) { // insert at front (or into empty list).
			new_node->next = headPtr;                 // precursor remains nullptr.
			headPtr = new_node;
			if (numItems == 1) {
				tailPtr = new_node;
			}
		}
		else {                                       // inserting anywhere else
			new_node->next = cursor;                   // tailPtr, headPtr and precursor don't change.
			precursor->next = new_node;
		}

		cursor = new_node;
	}

	Sequence::size_type Sequence::size() const {
		return numItems;
	}

	bool Sequence::is_item() const {
		return cursor != nullptr;
	}

	Sequence::value_type Sequence::current() const {
		assert(is_item());
		return cursor->data;
	}

	void Sequence::attach(const value_type& entry) {
		node* newnode = new node;
		newnode->data = entry;
		newnode->next = nullptr;  // Initially set newnode's next to nullptr

		// Case 1: The sequence is empty
		if (this->headPtr == nullptr) {
			this->headPtr = newnode;
			this->tailPtr = newnode;
			this->cursor = newnode;
			this->precursor = nullptr;
		}
		// Case 2: No current item (cursor is nullptr) - attach to the end
		else if (this->cursor == nullptr) {
			this->tailPtr->next = newnode;
			this->precursor = this->tailPtr;
			this->tailPtr = newnode;
			this->cursor = newnode;
		}
		// Case 3: The cursor is at the tail - also attach at the end
		else if (this->cursor == this->tailPtr) {
			this->tailPtr->next = newnode;
			this->precursor = this->tailPtr;
			this->tailPtr = newnode;
			this->cursor = newnode;
		}
		// Case 4: Attaching in the middle of the sequence
		else {
			node* successor = this->cursor->next;
			this->cursor->next = newnode;
			newnode->next = successor;
			this->precursor = this->cursor;
			this->cursor = newnode;
		}

		this->numItems++;  // Increment the count of items in the sequence
	}

	void Sequence::remove_current() {
		assert(is_item());  // Ensure there's a current item to remove

		// Case 1: Removing the first item (cursor == headPtr)
		if (this->cursor == headPtr) {
			if (this->numItems == 1) {
				// If it's the only item, manually clear without calling clear()
				delete this->cursor;
				this->headPtr = this->tailPtr = this->cursor = this->precursor = nullptr;
			}
			else {
				node* successor = this->cursor->next;
				delete this->cursor;
				this->cursor = successor;
				this->headPtr = this->cursor;  // Update headPtr to new first item
				this->precursor = nullptr;  // No precursor for the new head
			}
		}
		// Case 2: Removing a middle or last item
		else {
			node* successor = this->cursor->next;
			this->precursor->next = successor;  // Link precursor to successor

			// If cursor was at tailPtr, update tailPtr
			if (this->cursor == this->tailPtr) {
				this->tailPtr = this->precursor;  // Precursor becomes the new tail
			}

			delete this->cursor;  // Free the removed node
			this->cursor = successor;  // Update cursor to successor
		}

		// Decrement number of items
		numItems--;
	}

}