#include "helper.hpp"

int input_file_line=1;
int source_file_line=1;
std::string source_file="program input file";

void process_prep_include(const std::string& content){
  stringstream ss;
  ss<<content;
  std::string out;
  ss>>out;
  ss>>out;
  source_file_line = atoi(out.c_str())-1;
  ss>>source_file;
  source_file = source_file.substr(1, source_file.size()-2);
}



