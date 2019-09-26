#include "BlogPost.h"

std::string BlogPost::getTitle() {
    return title;
}

std::string BlogPost::getText() {
    return text;
}


void BlogPost::setTitle(std::string title) {
    BlogPost::title = title;
}

void BlogPost::setText(std::string text) {
    BlogPost::text = text;
}

void BlogPost::setPublicationDate(std::string publicationDate) {
    BlogPost::publicationDate = publicationDate;
}

void BlogPost::setAuthorName(std::string authorName) {
    BlogPost::authorName = authorName;
}
