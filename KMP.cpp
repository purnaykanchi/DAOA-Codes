#include <iostream>
#include <vector>
void computeLPS(std::string pattern, std::vector<int>& lps) {
    int m = pattern.size();
    int len = 0;
    lps[0] = 0;
    for (int i = 1; i < m; i++) {
        while (len > 0 && pattern[i] != pattern[len])
            len = lps[len - 1];
        if (pattern[i] == pattern[len]) {
            len++;
        }
        lps[i] = len;
    }
}
std::vector<int> searchKMP(std::string text, std::string pattern) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> lps(m);
    std::vector<int> result;
    computeLPS(pattern, lps);
    int i = 0;
    int j = 0;    
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}int main() {
    std::string txt = "AABAACAADAAABAABA";
    std::string pat = "AABA";
    std::vector<int> positions = searchKMP(txt, pat);    
    if (!positions.empty()) {
        std::cout << "Pattern found at positions:";
        for (int pos : positions) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Pattern not found." << std::endl;
    }
    return 0;
}