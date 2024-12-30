#pragma once
#include <unordered_map>
#include <list>
#include <memory>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

template <typename Page = std::string>
class Cache {
public:
    explicit Cache(size_t cacheSize);

    Page getPage(size_t pageNumber);
    Page getSlowPage(size_t pageNumber);

    void printList() const;
private:
    size_t maxSizez_;
    std::list<std::pair<size_t, Page>> list_;
    std::unordered_map<size_t, typename std::list<std::pair<size_t, Page>>::const_iterator> cache_;
};

#include "Cache.ipp"