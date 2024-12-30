#pragma once

#include <string>

class DefaultPage {
public:
    explicit DefaultPage(size_t pageNumber) : pageNumber_(pageNumber) {

    }

    virtual void setContent(std::string content) {
        content_ = content;
        if (content_.empty()) {
            setDefaultContent();
        }
    }

    std::string getContent() const {
        return content_;
    }

private:
    virtual void setDefaultContent() {
        content_ = std::to_string(pageNumber_);
    }
    size_t pageNumber_;
    std::string content_;
};