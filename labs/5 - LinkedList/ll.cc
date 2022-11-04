#include "ll.h"
#include <cstdlib>
#include <iostream>

LinkedList::Link::Link(unsigned data, Link *pnext)
  : m_uiData(data), m_pNext(pnext)
{

}

/*LinkedList::Link() : m_pHead(nullptr)
{
  
}*/

LinkedList::~LinkedList()
{
  unsigned num;
  while(remove(num));
}

LinkedList::LinkedList() : m_pHead(nullptr)
{

}

bool LinkedList::insert(unsigned uiData) {
    m_pHead = new Link(uiData, m_pHead);
    return true;
}

bool LinkedList::remove(unsigned &pData) {
    if (!m_pHead)				// Empty list?
		return false;				// Indicate failure.

    Link *temp = m_pHead;			// Point to the first node.
    m_pHead = m_pHead -> m_pNext;
    pData = temp -> m_uiData;
    delete temp;
    return true;
}

std::ostream& operator << (std::ostream &out, const LinkedList &l) {
	LinkedList::Link *temp = l.m_pHead;
	while (temp -> m_pNext) {
		out << temp -> m_uiData << ' ';
		temp = temp -> m_pNext;
	}
	return out << temp -> m_uiData << '\n';
}

