#pragma once
#include <unordered_map>
#include <list>
#include <memory>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

template <typename Page = std::string, typename Id = int>
class Cache {
public:
    explicit Cache(size_t cacheSize);

    Page getPage(Id id);
    Page getSlowPage(Id id);

    void printList() const;
private:
    size_t maxSizez_;
    std::list<std::pair<Id, Page>> list_;
    std::unordered_map<Id, typename std::list<std::pair<Id, Page>>::const_iterator> cache_;
};

#include "Cache.ipp"