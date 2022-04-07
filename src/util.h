#ifndef UTIL_H
#define UTIL_H

#include <cmdline.h>
#include <string.h>
#include <string>
#include <vector>

void split(const std::string &s, std::vector<std::string> &result,
           const std::string &delimiters = " ");

cmdline::parser initCmdLineParser(int argc, char *argv[]);

#endif