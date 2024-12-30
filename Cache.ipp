#include "Cache.hpp"

template<typename Page>
Cache<Page>::Cache(size_t cacheSize) : maxSizez_(cacheSize) {

}

template<typename Page>
Page Cache<Page>::getPage(size_t pageNumber) {
    Page currPage;
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

template<typename Page>
Page Cache<Page>::getSlowPage(size_t pageNumber) {
    std::cout << "Slow get page\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Page ans = std::to_string(pageNumber);
    return ans;
}

template<typename Page>
void Cache<Page>::printList() const {
    for (const auto& pageNumber : list_) {
        std::cout << pageNumber.first << "|";
    }
    std::cout << std::endl;
}