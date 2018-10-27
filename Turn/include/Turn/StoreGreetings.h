#ifndef STOREGREETINGS_H
#define STOREGREETINGS_H

#include <string>
#include <vector>

const std::vector<std::string> STORE_GREETINGS {
  "Come on in and buy something!",
  "Buy somethin', would ya?",
  "No refunds!",
  "Window shopping is free, but it doesn't pay my bills!",
  "You break it, you buy it!",
  "We've got what you need!",
  "We're happy to separate you from your money!"
};

std::string random_greeting();

#endif // STOREGREETINGS_H
