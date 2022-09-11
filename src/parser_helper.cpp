#include "parser_helper.h"

void ParserHelper::parseInitFile(std::ifstream &stream, Parts& parts) {
    std::string line;
    
}

bool ParserHelper::containsAnyChar(const std::string &str, const std::vector<char> &vec) {
    for (size_t i = 0; i < str.size(); i++) {
        char chr = str[i];
        for (const auto &j : vec){
            if (j == chr) return true;
        }
        
    }
    
    return false;
}