#include "Cache.hpp"

int main() {
    Cache c(5);

    c.getPage(1);
    c.printList();
    c.getPage(2);
    c.printList();
    c.getPage(3);
    c.printList();
    c.getPage(4);
    c.printList();
    c.getPage(5);
    c.printList();
    c.getPage(6);
    c.printList();
    c.getPage(2);
    c.printList();
    c.getPage(4);
    c.printList();
    c.getPage(7);
    c.printList();
    c.getPage(8);
    c.printList();
    c.getPage(5);
    c.printList();
    c.getPage(3);
    c.printList();
    return 0;
}