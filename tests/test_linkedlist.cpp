#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "linkedList.hpp"

TEST_CASE("empty list has size 0"){
    LinkedList<int> l;
    REQUIRE(l.size() == 0);
}

TEST_CASE("size reflects number of pushed elements"){
    LinkedList<int> l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    REQUIRE(l.size() == 3);
}

TEST_CASE("at retrieves correct values"){
    LinkedList<int> l;
    l.pushBack(10);
    l.pushBack(20);
    l.pushBack(30);
    REQUIRE(l.at(0) == 10);
    REQUIRE(l.at(1) == 20);
    REQUIRE(l.at(2) == 30);
}

TEST_CASE("pushBack increases size and values accessible"){
    LinkedList<int> l;
    l.pushBack(5);
    l.pushBack(7);
    REQUIRE(l.size() == 2);
    REQUIRE(l.at(0) == 5);
    REQUIRE(l.at(1) == 7);
}

TEST_CASE("out_of_range for bad indices"){
    LinkedList<int> l;
    l.pushBack(1);
    REQUIRE_THROWS_AS(l.at(1), std::out_of_range);
    REQUIRE_THROWS_AS(l.at(100), std::out_of_range);
}

TEST_CASE("Poziom 1: insertAt") {
    LinkedList<int> l;
    l.pushBack(10);
    l.pushBack(20);
    l.pushBack(40);

    l.insertAt(5,0);
    REQUIRE(l.at(0) == 0);

    l.insertAt(30, 3);
    REQUIRE(l.at(3) == 30);

    l.insertAt(50, 10);
    REQUIRE(l.at(5) == 50);
}


TEST_CASE("Poziom 1: erase")    {
    LinkedList<int> l;
    l.pushBack(10);
    l.pushBack(20);
    l.pushBack(40);
    l.pushBack(60);

    l.erase(2);
    REQUIRE(l.at(2) == 60);

    l.erase(0);
    REQUIRE(l.at(0) == 20);

    REQUIRE_THROWS_AS(l.erase(51), std::out_of_range);
}

TEST_CASE("Poziom 1: countOccurences")  {
    LinkedList<int> l;
    l.pushBack(10);
    l.pushBack(10);
    l.pushBack(10);
    l.pushBack(60);
    l.pushBack(60);

    REQUIRE(l.countOccurrences(10) == 3);
    REQUIRE(l.countOccurrences(60) == 2);
    REQUIRE(l.countOccurrences(420) == 0);
}

TEST_CASE("Poziom 2: reverse")  {
    LinkedList<int> l;
    l.pushBack(10);
    l.pushBack(10);
    l.pushBack(10);
    l.pushBack(60);
    l.pushBack(60);

    l.reverse();

    REQUIRE(l.at(0) == 60);
    REQUIRE(l.at(1) == 60);
    REQUIRE(l.back() == 10);
}

TEST_CASE("Poziom 2: split (in half)")  {
    LinkedList<int> l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(4);
    l.pushBack(5);
    l.pushBack(10);
    l.pushBack(20);
    l.pushBack(30);
    l.pushBack(40);
    l.pushBack(50);

    LinkedList<int> other = l.split();

    REQUIRE(l.size() == 5);
    REQUIRE(other.size() == 5);
    REQUIRE(l.back() == 5);
    REQUIRE(other.at(0) == 10);
    REQUIRE(other.at(4) == 50);
}

TEST_CASE("Poziom 2: middle")   {
    LinkedList<int> l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(4);
    l.pushBack(5);

    REQUIRE(l.middle() == 3);

    l.pushBack(10);
    l.pushBack(20);
    l.pushBack(30);
    l.pushBack(40);
    l.pushBack(50);

    REQUIRE(l.middle() == 10);
}

TEST_CASE("Poziom 2: splitAt")  {
    LinkedList<int> l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(4);
    l.pushBack(5);
    l.pushBack(10);
    l.pushBack(20);
    l.pushBack(30);
    l.pushBack(40);
    l.pushBack(50);

    LinkedList<int> other = l.split(4);

    REQUIRE(l.size() == 4);
    REQUIRE(other.size() == 6);
    REQUIRE(l.back() == 4);
    REQUIRE(other.at(0) == 5);
    REQUIRE(other.at(4) == 40);
}

TEST_CASE("Poziom 2: splitAfterIndex"){
    LinkedList<int> l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(4);
    l.pushBack(5);
    l.pushBack(10);
    l.pushBack(20);//7
    l.pushBack(30);//hed
    l.pushBack(40);
    l.pushBack(50);

    LinkedList<int> other = l.split(7);

    REQUIRE(other.front() == 30);
    REQUIRE(l.size() == 7);
    REQUIRE(l.back() == 20);
}

TEST_CASE("Poziom 3: mergeSortedLists") {
    LinkedList<int> l1;
    l1.pushBack(1);
    l1.pushBack(3);
    l1.pushBack(5);
    l1.pushBack(7);
    l1.pushBack(9);
    l1.pushBack(11);
    l1.pushBack(13); 
    l1.pushBack(15); 
    l1.pushBack(17);
    l1.pushBack(19);

    LinkedList<int> l2;
    l2.pushBack(0);
    l2.pushBack(2);
    l2.pushBack(4);
    l2.pushBack(20);

    LinkedList<int> other = other.mergeSortedLists(l1, l2);

    REQUIRE(other.front() == 0);
    REQUIRE(other.size() == 14);
    REQUIRE(other.back() == 20);
}

TEST_CASE("Poziom 3: mergeSort - empty and single") {
    LinkedList<int> l;
    l.mergeSort();
    REQUIRE(l.size() == 0);

    l.pushBack(42);
    l.mergeSort();
    REQUIRE(l.size() == 1);
    REQUIRE(l.front() == 42);
    REQUIRE(l.back() == 42);
}

TEST_CASE("Poziom 3: mergeSort - sorts unsorted list") {
    LinkedList<int> l;
    l.pushBack(3);
    l.pushBack(1);
    l.pushBack(4);
    l.pushBack(2);
    l.pushBack(5);

    l.mergeSort();

    REQUIRE(l.size() == 5);
    REQUIRE(l.at(0) == 1);
    REQUIRE(l.at(1) == 2);
    REQUIRE(l.at(2) == 3);
    REQUIRE(l.at(3) == 4);
    REQUIRE(l.at(4) == 5);
    REQUIRE(l.front() == 1);
    REQUIRE(l.back() == 5);
}

TEST_CASE("Poziom 3: mergeSort - duplicates") {
    LinkedList<int> l;
    l.pushBack(5);
    l.pushBack(1);
    l.pushBack(3);
    l.pushBack(5);
    l.pushBack(2);
    l.pushBack(1);

    l.mergeSort();

    REQUIRE(l.size() == 6);
    REQUIRE(l.at(0) == 1);
    REQUIRE(l.at(1) == 1);
    REQUIRE(l.at(2) == 2);
    REQUIRE(l.at(3) == 3);
    REQUIRE(l.at(4) == 5);
    REQUIRE(l.at(5) == 5);
}

TEST_CASE("Poziom 3: mergeSort - reverse order") {
    LinkedList<int> l;
    for (int i = 10; i >= 1; --i) l.pushBack(i);

    l.mergeSort();

    REQUIRE(l.size() == 10);
    REQUIRE(l.front() == 1);
    REQUIRE(l.back() == 10);
    for (int i = 0; i < 10; ++i) REQUIRE(l.at(i) == i + 1);
}

TEST_CASE("Poziom 3: hasCycle") {
    LinkedList<int> l;
    for (int i = 1; i <= 5; ++i) l.pushBack(i);
    REQUIRE(!l.hasCycle());

    // create a cycle by connecting tail to node at index 2
    l.createCycle();
    REQUIRE(l.hasCycle());
}
