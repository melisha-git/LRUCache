#include "Cache.hpp"

#include <memory>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

Cache::Cache(size_t cacheSize) : maxSizez_(cacheSize) {

}

DefaultPage* Cache::getPage(size_t pageNumber) {
    DefaultPage* currPage;
    if (!cache_.count(pageNumber)) {
        currPage = getSlowPage(pageNumber);
    }
    else {
        auto it = cache_[pageNumber];
        currPage = it->second;
        if (it != list_.end()) {
            list_.erase(it);
            cache_.erase(pageNumber);
        }
    }
    list_.push_front({pageNumber, currPage});
    cache_[pageNumber] = list_.begin();
    while (list_.size() > maxSizez_) {
        size_t lastPage = list_.back().first;
        list_.pop_back();
        cache_.erase(lastPage);
    }
    return list_.front().second;
}

DefaultPage* Cache::getSlowPage(size_t pageNumber) {
    std::cout << "Slow get page\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::shared_ptr<DefaultPage> page = std::make_shared<DefaultPage>(pageNumber);
    page->setContent("");
    return page.get();
}

void Cache::printList() const {
    for (const auto& pageNumber : list_) {
        std::cout << pageNumber.first << "|";
    }
    std::cout << std::endl;
}