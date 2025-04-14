#ifndef NODE_H
#define NODE_H

namespace cs_set {

    template<class ItemType>
    class Node {
    private:
        ItemType item;
        Node<ItemType>* next;

    public:
        Node(const ItemType& anItem = ItemType(), Node<ItemType>* nextNodePtr = nullptr);
        void setItem(const ItemType& anItem);
        void setNext(Node<ItemType>* nextNodePtr);
        ItemType getItem() const;
        Node<ItemType>* getNext() const;
    };
}

#endif
