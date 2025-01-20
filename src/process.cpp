#include <filesystem>
#include <fstream>
#include <string>
#include <algorithm>

#include "aggregator.h"

class ProcessInformation {
private:
   size_t pid;
   string name;
   string user;
   string cmdline;
public:
   void signal(int sig) {

   }
};

bool ProcessAggregator::init() {
   return true;
}

void ProcessAggregator::aggregate() {
   for (const auto &d: std::filesystem::directory_iterator("/proc")) {

      const string pidstr = d.path().filename();
      size_t pid, read;
      
      try {
         pid = stoul(pidstr, &read);
      } catch (std::exception& e) {
         continue;
      }
      if (read != pidstr.length()) continue;
   }
}

void ProcessAggregator::process(KeyEvent ev) {
   
}

/// Internal member functions

bool ProcessAggregator::valid_proc_file(const std::string& s) {
   return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) {
         return !std::isdigit(c); }) == s.end();
}

void ProcessAggregator::aggregate_details(const size_t pid) {
   std::ifstream filp;

}
