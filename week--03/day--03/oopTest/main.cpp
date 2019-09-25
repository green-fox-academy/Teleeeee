#include <iostream>
#include "cmake-build-debug/Rectangle.h"
#include "cmake-build-debug/postIt.h"
#include "cmake-build-debug/BlogPost.h"
#include "cmake-build-debug/Animals.h"

int main() {
    {
    Rectangle rect1;

    rect1.setX1(5);
    rect1.setY1(5);
    rect1.setX2(10);
    rect1.setY2(10);

    Rectangle rect2(3, 5, 17, 10);


    std::cout << rect1.area() << std::endl;
    std::cout << rect2.area() << std::endl;
}

    //Post It
    {
    postIt Idea1;
    Idea1.setBackgroundColor(0);
    Idea1.setText("Idea1");
    Idea1.setTextColor(1);

    postIt Awesome;

    Awesome.setTextColor(1);
    Awesome.setText("Awesome");
    Awesome.setTextColor(2);

    postIt Superb;

    Superb.setTextColor(3);
    Superb.setText("Superb!");
    Superb.setTextColor(5);

    BlogPost firstBlogPost;

    firstBlogPost.setText("Lorem ipsum dolor sit amet.");
    firstBlogPost.setTitle("Lorem Ipsum");
    firstBlogPost.setAuthorName("John Doe");
    firstBlogPost.setPublicationDate("2000.05.04.");

    BlogPost secondBlogPost{};

    secondBlogPost.setText("A popular long-form, stick-figure-illustrated blog about almost everything.");
    secondBlogPost.setTitle("Wait but why");
    secondBlogPost.setAuthorName("Tim Urban");
    secondBlogPost.setPublicationDate("2010.10.10.");


    BlogPost thirdBlogPost{};

    thirdBlogPost.setText("Daniel Hanley, a cybersecurity engineer at IBM,"
                          " doesn’t want to be the center of attention."
                          " When I asked to take his picture outside one of IBM’s New York City offices,"
                          " he told me that he wasn’t really into the whole organizer profile thing.");
    thirdBlogPost.setTitle("One Engineer Is Trying to Get IBM to Reckon With Trump");
    thirdBlogPost.setAuthorName("William Turton");
    thirdBlogPost.setPublicationDate("2017.03.28.");

}
    Animals cat;

    cat.drink();
    cat.drink();
    cat.drink();
    cat.drink();
    cat.play();
    cat.eat();

    std::cout << "The hunger of the cat is " <<cat.getHunger() << std::endl;
    std::cout << "The thirst of the cat is " <<cat.getThirst() << std::endl;



    return 0;
}