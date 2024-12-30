#pragma once
#include <unordered_map>
#include <list>
#include <string>
#include "DefaultPage.hpp"

class Cache {
public:
    explicit Cache(size_t cacheSize);

    DefaultPage getPage(size_t pageNumber);
    DefaultPage getSlowPage(size_t pageNumber);

    void printList() const;
private:
    size_t maxSizez_;
    std::list<DefaultPage> list_;
    std::unordered_map<size_t, typename std::list<DefaultPage>::iterator> cache_;
};

#include "Cache.ipp"