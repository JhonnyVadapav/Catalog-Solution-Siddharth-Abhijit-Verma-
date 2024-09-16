#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int decode_base(const string& value, int base) {
    return stoi(value, nullptr, base);
}

double lagrange_interpolation_constant(const vector<pair<int, int>>& points) {
    double c = 0;
    int k = points.size();
    for (int i = 0; i < k; ++i) {
        int xi = points[i].first;
        int yi = points[i].second;
        double term = yi;
        for (int j = 0; j < k; ++j) {
            if (i != j) {
                int xj = points[j].first;
                term *= 0 - xj;
                term /= (xi - xj);
            }
        }
        c += term;
    }
    return c;
}

int find_constant_term(map<string, map<string, string>>& test_case) {
    map<string, string> keys = test_case["keys"];
    int n = stoi(keys["n"]);
    int k = stoi(keys["k"]);
    
    vector<pair<int, int>> points;
    for (auto& [key, value] : test_case) {
        if (key != "keys" && points.size() < k) {
            int x = stoi(key);
            int base = stoi(value["base"]);
            int y = decode_base(value["value"], base);
            points.emplace_back(x, y);
        }
    }
    
    double constant_term = lagrange_interpolation_constant(points);
    return static_cast<int>(constant_term);
}

int main() {
    map<string, map<string, string>> test_case = {
        {"keys", {{"n", "4"}, {"k", "3"}}},
        {"1", {{"base", "10"}, {"value", "4"}}},
        {"2", {{"base", "2"}, {"value", "111"}}},
        {"3", {{"base", "10"}, {"value", "12"}}},
        {"6", {{"base", "4"}, {"value", "213"}}}
    };
    
    int constant_term = find_constant_term(test_case);
    cout << "Constant term: " << constant_term << endl;
    return 0;
}
