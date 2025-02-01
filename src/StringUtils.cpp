#include "StringUtils.h"

namespace StringUtils{

std::string slice(const std::string &str, ssize_t start, ssize_t end) {
    ssize_t length = str.length();
    if (start < 0) start += length;
    if (end <= 0) end += length;
    if (end > length) end = length;
    if (start >= end || start >= length) return "";
    return str.substr(start, end - start);
}

std::string Capitalize(const std::string &str) {
    if (str.empty()) return "";
    std::string result = str;
    result[0] = toupper(result[0]);
    for (size_t i = 1; i < result.length(); ++i) {
        result[i] = tolower(result[i]);
    }
    return result;
}

std::string Upper(const std::string &str) {
    std::string result = str;
    for (char &c : result) {
        c = toupper(c);
    }
    return result;
}

std::string Lower(const std::string &str) {
    std::string result = str;
    for (char &c : result) {
        c = tolower(c);
    }
    return result;
}

std::string LStrip(const std::string &str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : str.substr(start);
}

std::string RStrip(const std::string &str) {
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string Strip(const std::string &str) {
    return RStrip(LStrip(str));
}

std::string Center(const std::string &str, int width, char fill) {
    if (str.length() >= width) return str;
    int padding = width - str.length();
    int left_padding = padding / 2;
    int right_padding = padding - left_padding;
    return std::string(left_padding, fill) + str + std::string(right_padding, fill);
}

std::string LJust(const std::string &str, int width, char fill) {
    if (str.length() >= width) return str;
    return str + std::string(width - str.length(), fill);
}


std::string RJust(const std::string &str, int width, char fill) {
    if (str.length() >= width) return str;
    return std::string(width - str.length(), fill) + str;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) {
    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(old, pos)) != std::string::npos) {
        result.replace(pos, old.length(), rep);
        pos += rep.length();
    }
    return result;
}

std::vector<std::string> Split(const std::string &str, const std::string &splt) {
    std::vector<std::string> result;
    if (splt.empty()) {
        size_t start = 0;
        size_t end = str.find_first_of(" \t\n\r\f\v");
        while (end != std::string::npos) {
            if (start != end) {
                result.push_back(str.substr(start, end - start));
            }
            start = end + 1;
            end = str.find_first_of(" \t\n\r\f\v", start);
        }
        if (start < str.length()) {
            result.push_back(str.substr(start));
        }
    } else {
        size_t start = 0;
        size_t end = str.find(splt);
        while (end != std::string::npos) {
            result.push_back(str.substr(start, end - start));
            start = end + splt.length();
            end = str.find(splt, start);
        }
        result.push_back(str.substr(start));
    }
    return result;
}

std::string Join(const std::string &str, const std::vector<std::string> &vect) {
    std::string result;
    for (size_t i = 0; i < vect.size(); ++i) {
        result += vect[i];
        if (i != vect.size() - 1) {
            result += str;
        }
    }
    return result;
}

std::string ExpandTabs(const std::string &str, int tabsize) {
    std::string result;
    size_t col = 0;
    for (char c : str) {
        if (c == '\t') {
            int spaces = tabsize - (col % tabsize);
            result.append(spaces, ' ');
            col += spaces;
        } else {
            result += c;
            ++col;
        }
    }
    return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) {
    std::string l = left;
    std::string r = right;
    if (ignorecase) {
        l = Lower(left);
        r = Lower(right);
    }
    size_t m = l.length();
    size_t n = r.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    for (size_t i = 0; i <= m; ++i) {
        for (size_t j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (l[i - 1] == r[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[m][n];
}

};