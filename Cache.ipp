#include "Cache.hpp"

#include <memory>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

template <typename Page>
Cache<Page>::Cache(size_t cacheSize) : maxSizez_(cacheSize) {

}

template <typename Page>
Page Cache<Page>::getPage(size_t pageNumber) {
    auto hit = cache_.find(pageNumber);
    if (hit == cache_.end()) {
        if (maxSizez_ == list_.size()) {
            cache_.erase(list_.back().getPageNumber());
            list_.pop_back();
        }
        list_.push_front(getSlowPage(pageNumber));
        cache_[pageNumber] = list_.begin();
    } else {
        auto elem = hit->second;
        if (elem != list_.begin()) {
            list_.splice(list_.begin(), list_, elem, std::next(elem));
        }
    }
    return list_.front();
}

template <typename Page>
Page Cache<Page>::getSlowPage(size_t pageNumber) {
    std::cout << "Slow get page\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Page page(pageNumber);
    return page;
}

template <typename Page>
void Cache<Page>::printList() const {
    for (const auto& page : list_) {
        std::cout << page.getPageNumber() << "|";
    }
    std::cout << std::endl;
}