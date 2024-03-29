#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
/*
 * The variable names in this file use a naming convention called
 * Hungarian Notation (https://en.wikipedia.org/wiki/Hungarian_notation)
 * that I’m not really in love with, but you see it here & there,
 * so you should know what it is.  Microsoft seems to like it.
 *
 * The leading “m_” indicates that this is a member variable.
 * It’s a member—part of the class.
 *
 * The letters after the “m_” indicate the type of the variable.
 * For example, “ui” means unsigned int, “p” means pointer, etc.
 *
 * After that, comes the real name of the variable, capitalized
 * to distinguish it from the type information.
 *
 * Therefore, m_uiData is an unsigned int member variable named “data”.
 *
 * Personally, I view it as not worth the trouble.  It gets in the
 * way of reading the code.
 */

class LinkedList {
  public:
  LinkedList();
  ~LinkedList();
    void initialize();
    bool insert(unsigned uiData);
    bool remove(unsigned &rdata);

  private:
    struct Link {
		unsigned m_uiData;
		Link *m_pNext;
		Link(unsigned uiData, Link *pNext);
    } *m_pHead;
  friend std::ostream & operator << (std::ostream &, const LinkedList &);
};

#endif /* LINKED_LIST_H */