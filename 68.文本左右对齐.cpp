#include <iostream>
#include <string>
#include <vector>

class Solution{
    public:
        std::vector<std::string> fullJustify(std::vector<std::string>& words,int maxWidth){
            std::vector<std::string> res;
    int i = 0;
    while (i < words.size()) {
        int j = i + 1;
        int len = words[i].size();
        while (j < words.size() && len + words[j].size() + j - i - 1 <= maxWidth) {
            len += words[j].size();
            j++;
        }
        std::string line = words[i];
        int space = maxWidth - len;
        if (j == words.size() || j - i == 1) {
            for (int k = i + 1; k < j; k++) {
                line += " " + words[k];
            }
            line += std::string(maxWidth - line.size(), ' ');
        } else {
            int numSlots = j - i - 1;
            int spacePerSlot = space / numSlots;
            int extraSpace = space % numSlots;
            for (int k = i + 1; k < j; k++) {
                line += std::string(spacePerSlot + (extraSpace > 0 ? 1 : 0), ' ') + words[k];
                if (extraSpace > 0) extraSpace--;
            }
        }
        res.push_back(line);
        i = j;
    }
    return res;
        }
};


int main(){



    return 0;
}