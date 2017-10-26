#include "../include/Common.h"
#include "../include/StoreGreetings.h"

#include <random>
#include <string>

std::string random_greeting() {
    std::random_device rand;
    std::default_random_engine rand_eng(rand());
    std::uniform_int_distribution<int> uniform_dist(0, STORE_GREETINGS.size());
    size_t index = uniform_dist(rand_eng);
    return STORE_GREETINGS[index];
}
