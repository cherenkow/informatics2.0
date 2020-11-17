#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
    tail = head = nullptr;
    count = 0;

    Node* temp = list.head;
    while (temp != nullptr)
    {
        addToTail(temp->data);
        temp = temp->next;
    }
}

LinkedList::~LinkedList()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        Node* node = temp;
        temp = temp->next;
        delete node;
    }
}

bool LinkedList::indexValid(int index)
{
    return (index >= 0 && index < count);
}

int LinkedList::length()
{
    return count;
}

bool LinkedList::addToHead(int element)
{
    if (head == nullptr) 
    {
        head = tail = new Node(element);
    }
    else
    {
        head = new Node(element, head);
    }
    ++count;
    return true;
}

bool LinkedList::addToTail(int element)
{
    if (tail == nullptr) 
    {
        head = tail = new Node(element);
    }
    else 
    {
        tail->next = new Node(element);
        tail = tail->next;
    }
    ++count;
    return true;
}

int LinkedList::extractHead() {
    if (head == nullptr) {
        return -1;
    }
    Node* temp = head;
    Node* node = temp;
    int k = head->data;
    head = temp->next;
    delete node;
    count--;
    return k;
}

int LinkedList::extractTail() {
    if (tail == nullptr) {
        return -1;
    }
    Node* temp = head;
    for (int i = 1; i < count - 1; ++i) {
        temp = temp->next;
    }
    Node* node = temp->next;
    int k = node->data;
    delete node;
    temp->next = nullptr;
    tail = temp;
    return k;
}

int LinkedList::extract(int index) {
    if (!indexValid(index)) {
        return -1;
    }
    if (index==0) {
        return extractHead();
    }
    if (index == count-1) {
       return extractTail();
    }
    Node* temp = head;
    for (int i = 1; i < index; ++i) {
        temp = temp->next;
    }
    Node* node = temp->next;
    int k = node->data;
    temp->next = node->next;
    delete node;
    count--;
    return k;
}

void LinkedList::operator-= (int index) {
    extract(index);
}

LinkedList& LinkedList::operator= (const LinkedList list) {
    if (head !=nullptr) {
        while (head != nullptr) {
            extractHead();
        }
    }
    Node* temp = list.head;
    count = 0;
    for (int i = 1; i < count; ++i){
        addToTail(temp->data);
        temp = temp->next;
    }
return *this; 
}

bool LinkedList::add(int index, int element)
{
    if (index == 0)
    {
        return addToHead(element);
    }
    if (index == count)
    {
        return addToTail(element);
    }
    if (!indexValid(index))
    {
        return false;
    }

    Node* temp = head;
    for (int i = 0; i < index - 1; ++i)
    {
        temp = temp->next;
    }
    temp->next = new Node(element, temp->next);
    ++count;

    return true;
}

int LinkedList::get(int index)
{
    if (!indexValid(index))
    {
        return -1;
    }
    if (index == 0)
    {
        return head->data;
    }
    if (index == count - 1)
    {
        return tail->data;
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;

}

bool LinkedList::set(int index, int element)
{
    if (!indexValid(index))
    {
        return false;
    }
    if (index == 0)
    {
        head->data = element;
    }
    else if (index == count - 1)
    {
        tail->data = element;
    }
    else
    {
        Node* temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        temp->data = element;
    }
    return true;
}

int& LinkedList::operator[](int index)
{
    if (head == nullptr)
    {
        addToHead(0);
        return head->data;
    }
    if (index <= 0)
    {
        return head->data;
    }
    if (index >= count)
    {
        addToTail(0);
        return tail->data;
    }
    if (index == count - 1)
    {
        return tail->data;
    }
    Node* temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}

int LinkedList::indexOf(int element) {
    if (head == nullptr) {
        return -1;
    }
    if (count == 1 && head->data == element) {
        return 0;
    }
    Node* temp = head;
    int k = 0;
    for (int i = 1; i < count; ++i) {
        if (temp->data == element) {
            return k;
        }
        k++;
        temp = temp->next;
    }
    return -1;
}

bool LinkedList::contains(int element) {
    return (indexOf(element) != -1 ? true : false);

}

bool LinkedList::swap(int index1, int index2) {

    if (index1 == index2 || count == 1) {
        return true;
    }
    if (!indexValid(index1) || !indexValid(index2) || head == nullptr) {
        return false;
    }
    Node* temp1 = head;
    Node* temp2 = head;
    for (int i = 1; i < index1; ++i) {
        temp1 = temp1->next;
    }
    for (int i = 1; i < index2; ++i) {
        temp2 = temp2->next;
    }
    Node* node1 = temp1;
    Node* node2 = temp2;
    temp1 = temp1->next;
    temp2 = temp2->next;

    Node* node11 = node1;
    Node* node22 = temp2;
    node1->next = node2->next;
    temp2->next = temp1->next;
    node2->next = node11->next;
    temp1->next = node22->next;
    return true;

}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
    stream << "[" << list.count << "]{";
    if (list.head == nullptr)
    {
        stream << "EMPTY";
    }
    else
    {
        Node* temp = list.head;
        while (temp != nullptr)
        {
            stream << temp->data;
            if (temp->next != nullptr)
            {
                stream << ", ";
            }
            temp = temp->next;
        }
    }
    stream << "}";
    return stream;
}

