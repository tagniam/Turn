#include "../include/Common.h"
#include "../include/StoreGreetings.h"

#include <string>

std::string random_greeting() {
    size_t index = Common::RandomInt(0, static_cast<int>(STORE_GREETINGS.size())-1);
    return STORE_GREETINGS[index];
}
