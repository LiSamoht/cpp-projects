#pragma once
#ifndef SEQUENCE H
#define SEQUENCE_H
#include<cstddef>

namespace cs_sequence {
	class Sequence {
	public:
		typedef int value_type;
		typedef std::size_t size_type;

		Sequence();
		// postcondition: The Sequence has been initialized to an empty Sequence.

		Sequence(const Sequence& source);

		~Sequence(); 

		Sequence& operator=(const Sequence& source);

		void start();
		// postcondition: The first item in the Sequence becomes the current item (but if the 
		// Sequence is empty, then there is no current item).

		void advance();
		// precondition: is_item() returns true
		// Postcondition: If the current item was already the last item in the Sequence, then there 
		// is no longer any current item. Otherwise, the new current item is the item immediately after 
		// the original current item.

		void insert(const value_type& entry);
		// Postcondition: A new copy of entry has been inserted in the Sequence before the 
		// current item. If there was no current item, then the new entry has been inserted at the 
		// front. In either case, the new item is now the current item of the Sequence.

		void attach(const value_type& entry);
		// Not required this week
		// Postcondition: A new copy of entry has been inserted in the Sequence after the current 
		// item. If there was no current item, then the new entry has been attached to the end of 
		// the Sequence. In either case, the new item is now the current item of the Sequence.

		void remove_current();
		// Not required this week
		// Precondition: is_item returns true. 
		// Postcondition: The current item has been removed from the Sequence.  If the item removed 
		// was the last item in the Sequence, then there is now no current item.  Otherwise, the item
		// that was after the removed item is now the current item.


		size_type size() const;
		// Postcondition: Returns the number of items in the Sequence.

		bool is_item() const;
		// Postcondition: A true return value indicates that there is a valid "current" item that
		// may be retrieved by the current member function (listed below). A false return value
		// indicates that there is no valid current item.

		value_type current() const;
		// Precondition: is_item() returns true
		// Postcondition: The current item in the Sequence is returned.
	private:
		struct node {
			value_type data;
			node* next;
		};
		node* headPtr;
		node* tailPtr;
		node* cursor;
		node* precursor;
		size_type numItems;
		void copy(const Sequence& source);
		void clear();
	};

}

#endif