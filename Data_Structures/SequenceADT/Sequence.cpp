#include "Sequence.h"
#include <cassert>

namespace cs_sequence {
	Sequence::Sequence() {
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
}