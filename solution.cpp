#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

long long decode_base(const string& value, int base) {
    return stoll(value, nullptr, base);
}

double lagrange_interpolation_constant(const vector<pair<int, long long>>& points) {
    double c = 0;
    int k = points.size();
    for (int i = 0; i < k; ++i) {
        int xi = points[i].first;
        long long yi = points[i].second;
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

long long find_constant_term(map<string, map<string, string>>& test_case) {
    map<string, string> keys = test_case["keys"];
    int n = stoi(keys["n"]);
    int k = stoi(keys["k"]);
    
    vector<pair<int, long long>> points;
    for (auto& [key, value] : test_case) {
        if (key != "keys" && points.size() < k) {
            int x = stoi(key);
            int base = stoi(value["base"]);
            long long y = decode_base(value["value"], base);
            points.emplace_back(x, y);
        }
    }
    
    double constant_term = lagrange_interpolation_constant(points);
    return static_cast<long long>(constant_term);
}

int main() {
    map<string, map<string, string>> test_case = {
        {"keys", {{"n", "9"}, {"k", "6"}}},
        {"1", {{"base", "10"}, {"value", "28735619723837"}}},
        {"2", {{"base", "16"}, {"value", "1A228867F0CA"}}},
        {"3", {{"base", "12"}, {"value", "32811A4AA0B7B"}}},
        {"4", {{"base", "11"}, {"value", "917978721331A"}}},
        {"5", {{"base", "16"}, {"value", "1A22886782E1"}}},
        {"6", {{"base", "10"}, {"value", "28735619654702"}}},
        {"7", {{"base", "14"}, {"value", "71AB5070CC4B"}}},
        {"8", {{"base", "9"}, {"value", "122662581541670"}}},
        {"9", {{"base", "8"}, {"value", "642121030037605"}}}
    };
    
    long long constant_term = find_constant_term(test_case);
    cout << "Constant term: " << constant_term << endl;
    return 0;
}
