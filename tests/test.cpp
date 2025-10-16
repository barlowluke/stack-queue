#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "algos.hpp"

TEST_CASE("Testing removeDuplicates function") {
    REQUIRE(removeDuplicates("abbaca") == "ca");
    REQUIRE(removeDuplicates("abccba") == "");
    REQUIRE(removeDuplicates("") == "");
    REQUIRE(removeDuplicates("abcde") == "abcde");
    REQUIRE(removeDuplicates("aaaaa") == "a");
    REQUIRE(removeDuplicates("aaaa") == "");
    REQUIRE(removeDuplicates("1122334455") == "");
    REQUIRE(removeDuplicates("abbaa") == "a");
}

TEST_CASE("Testing clean_backspace_string function") {
    REQUIRE(clean_backspace_string("ab<c") == "ac");
    REQUIRE(clean_backspace_string("ab<<") == "");
    REQUIRE(clean_backspace_string("a<<b<<") == "");
    REQUIRE(clean_backspace_string("<") == "");
    REQUIRE(clean_backspace_string("<<a") == "a");
    REQUIRE(clean_backspace_string("a<bc<d") == "bd");
}

TEST_CASE("Testing stack_contains_restore function") {

    SECTION("S={1,2,3,4,5}; Q={}; x=5") {
        std::stack<int> S;
        S.push(5);
        S.push(4);
        S.push(3);
        S.push(2);
        S.push(1);
        std::queue<int> Q;
        const int x = 5;
        REQUIRE(stack_contains_restore(S, Q, x));
    }

    SECTION("S={1,2,3,4,5}; Q={}; x=1") {
        std::stack<int> S;
        S.push(1);
        S.push(2);
        S.push(3);
        S.push(4);
        S.push(5);
        std::queue<int> Q;
        const int x = 1;
        REQUIRE(stack_contains_restore(S, Q, x));
    }

    SECTION("S={1,2,3,4,5}; Q={}; x=3") {
        std::stack<int> S;
        S.push(1);
        S.push(2);
        S.push(3);
        S.push(4);
        S.push(5);
        std::queue<int> Q;
        const int x = 3;
        REQUIRE(stack_contains_restore(S, Q, x));
    }

    SECTION("S={1,2,3,4,5}; Q={}; x=10") {
        std::stack<int> S;
        S.push(1);
        S.push(2);
        S.push(3);
        S.push(4);
        S.push(5);
        std::queue<int> Q;
        const int x = 10;
        REQUIRE(!stack_contains_restore(S, Q, x));
    }

    SECTION("S={1,2,3,4,5}; Q={1}; x=3") {
        std::stack<int> S;
        S.push(1);
        S.push(2);
        S.push(3);
        S.push(4);
        S.push(5);
        std::queue<int> Q;
        Q.push(1);
        const int x = 3;
        REQUIRE_THROWS_AS(stack_contains_restore(S, Q, x), std::invalid_argument);
    }

    SECTION("S={}; Q={}; x=5") {
        std::stack<int> S;
        std::queue<int> Q;
        const int x = 5;
        REQUIRE(!stack_contains_restore(S, Q, x));
    }

    SECTION("S={5}; Q={}; x=5") {
        std::stack<int> S;
        S.push(5);
        std::queue<int> Q;
        const int x = 5;
        REQUIRE(stack_contains_restore(S, Q, x));
    }

    SECTION("S={5}; Q={}; x=10") {
        std::stack<int> S;
        std::queue<int> Q;
        const int x = 10;
        REQUIRE(!stack_contains_restore(S, Q, x));
    }

}
