#pragma once

#include <string>

class DefaultPage {
public:
    explicit DefaultPage(size_t pageNumber, const std::string& content = "") : pageNumber_(pageNumber), content_(std::move(content)) {

    }

    virtual void setContent(std::string content) {
        content_ = content;
        if (content_.empty()) {
            setDefaultContent();
        }
    }

    virtual std::string getContent() const {
        return content_;
    }

    virtual size_t getPageNumber() const {
        return pageNumber_;
    }

private:
    void setDefaultContent() {
        content_ = std::to_string(pageNumber_);
    }
    size_t pageNumber_;
    std::string content_;
};