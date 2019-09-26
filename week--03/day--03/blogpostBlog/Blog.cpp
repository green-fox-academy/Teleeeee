//
// Created by User on 26/09/2019.
//

#include "Blog.h"

void Blog::addBlogPostToTheList(BlogPost & object){
    _blogPostList.emplace_back(&object);
}

void Blog::deleteBlogPost(int objectIndex){
    if(0 < objectIndex < _blogPostList.size()) {
        _blogPostList.erase(_blogPostList.begin() + objectIndex);
    }
}
void Blog::updateBlogPost(int objectIndex , BlogPost& object){
    if(0 < objectIndex < _blogPostList.size()) {
        _blogPostList.erase(_blogPostList.begin() + objectIndex);
        _blogPostList.emplace(_blogPostList.begin() + objectIndex, &object);
    }
}
