#include "util.h"
#include "cmdline.h"

void split(const std::string &s, std::vector<std::string> &result,
           const std::string &delimiters) {
  result.clear(); // Clear all elements in the previous result

  std::string::size_type lastPos = s.find_first_not_of(delimiters, 0);
  std::string::size_type pos = s.find_first_of(delimiters, lastPos);
  while (std::string::npos != pos || std::string::npos != lastPos) {
    result.push_back(s.substr(lastPos, pos - lastPos));
    lastPos = s.find_first_not_of(delimiters, pos);
    pos = s.find_first_of(delimiters, lastPos);
  }
}

cmdline::parser initCmdLineParser(int argc, char **argv) {
  // Add command line options to the programme.
  cmdline::parser parser;
  parser.add<std::string>("path", 'p', "the path of the input data file", true,
                          "");
  // Parse the args in the command line
  parser.parse_check(argc, argv);

  return parser;
}