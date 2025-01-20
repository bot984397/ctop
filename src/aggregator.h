#include <filesystem>

#include "btop_shared.hpp"
#include "btop_input.hpp"

class IAggregator {
public:
   virtual ~IAggregator() = default;
   
   virtual bool init() = 0;
   virtual void aggregate() = 0;
   virtual void process(KeyEvent ev) = 0;
};

class ProcessAggregator : public IAggregator {
private:
   std::filesystem::file_time_type passwd_access;

   vector<string> proc_list;
   string filter;

   void aggregate_details(const size_t pid);
   bool valid_proc_file(const std::string& s);
public:
   bool init() override;
   void aggregate() override;
   void process(KeyEvent ev) override; 

};
