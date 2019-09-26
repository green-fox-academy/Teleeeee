#ifndef OOPTEST_BLOGPOST_H
#define OOPTEST_BLOGPOST_H


#include <string>

class BlogPost {

public:

    std::string getTitle();
    std::string getText();

private:
    std::string title;
public:
    void setTitle(std::string title);

    void setText(std::string text);

    void setPublicationDate(std::string publicationDate);

    void setAuthorName(std::string authorName);

private:
    std::string text;
    std::string publicationDate;
    std::string authorName;

};


#endif //OOPTEST_BLOGPOST_H
