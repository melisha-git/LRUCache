#include "Cache.hpp"

template<typename Page, typename Id>
Cache<Page, Id>::Cache(size_t cacheSize) : maxSizez_(cacheSize) {

}

template<typename Page, typename Id>
Page Cache<Page, Id>::getPage(Id id) {
    Page currPage;
    if (!cache_.count(id)) {
        currPage = getSlowPage(id);
    }
    else {
        auto it = cache_[id];
        currPage = it->second;
        if (it != list_.end()) {
            list_.erase(it);
            cache_.erase(id);
        }
    }
    list_.push_front({id, currPage});
    cache_[id] = list_.begin();
    while (list_.size() > maxSizez_) {
        Id lastId = list_.back().first;
        list_.pop_back();
        cache_.erase(lastId);
    }
    return list_.front().second;
}

template<typename Page, typename Id>
Page Cache<Page, Id>::getSlowPage(Id id) {
    std::cout << "Slow get page\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Page ans = std::to_string(id);
    return ans;
}

template<typename Page, typename Id>
void Cache<Page, Id>::printList() const {
    for (const auto& id : list_) {
        std::cout << id.first << "|";
    }
    std::cout << std::endl;
}