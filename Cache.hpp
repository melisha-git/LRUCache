#pragma once
#include <unordered_map>
#include <list>
#include <string>

template <typename Page>
class Cache {
public:
    explicit Cache(size_t cacheSize);

    Page getPage(size_t pageNumber);
    Page getSlowPage(size_t pageNumber);

    void printList() const;
private:
    size_t maxSizez_;
    std::list<Page> list_;
    std::unordered_map<size_t, typename std::list<Page>::iterator> cache_;
};

#include "Cache.ipp"