#include "helper.hpp"

int input_file_line=1;
int source_file_line=1;
std::string source_file="input source file";

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



uint64_t dec_to_uint64(const char* number){
    uint64_t result;
    stringstream ss;
    ss << number;
    ss>>result;
    return result;
}

uint64_t hex_to_uint64(const char* number){
    uint64_t result;
    stringstream ss;
    ss <<hex<< number;
    ss>>result;
    return result;
}

uint64_t oct_to_uint64(const char* number){
    uint64_t result;
    stringstream ss;
    ss <<oct<< number;
    ss>>result;
    return result;
}

double64_t to_double64(const char* number){
    double64_t result;
    stringstream ss;
    ss << number;
    ss>>result;
    return result;
}


