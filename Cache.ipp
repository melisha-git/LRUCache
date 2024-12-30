#include "Cache.hpp"

#include <memory>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

Cache::Cache(size_t cacheSize) : maxSizez_(cacheSize) {

}

DefaultPage Cache::getPage(size_t pageNumber) {
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

DefaultPage Cache::getSlowPage(size_t pageNumber) {
    std::cout << "Slow get page\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    DefaultPage page(pageNumber);
    page.setContent("");
    return page;
}

void Cache::printList() const {
    for (const auto& page : list_) {
        std::cout << page.getContent() << "|";
    }
    std::cout << std::endl;
}