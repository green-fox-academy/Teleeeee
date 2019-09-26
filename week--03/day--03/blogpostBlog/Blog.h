#ifndef BLOGPOSTBLOG_BLOG_H
#define BLOGPOSTBLOG_BLOG_H
#include "iostream"
#include "vector"
#include "BlogPost.h"

class Blog {
public:

    void addBlogPostToTheList(BlogPost & object);
    void deleteBlogPost(int objectIndex);
    void updateBlogPost(int, BlogPost&);

private:

    std::vector<BlogPost*> _blogPostList;

};


#endif //BLOGPOSTBLOG_BLOG_H
