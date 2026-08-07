#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
    // Prime factor breakdown for digits 0-9 into counts of [2, 3, 5, 7]
    const array<array<int, 4>, 10> digitFactors = {{
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    }};

    // Greedily compresses required primes [2, 3, 5, 7] into the minimum number of single digits (2-9)
    array<int, 10> getMinDigits(array<int, 4> reqPrimes) {
        int c2 = reqPrimes[0], c3 = reqPrimes[1];
        int c5 = reqPrimes[2], c7 = reqPrimes[3];

        int d9 = c3 / 2, rem3 = c3 % 2;
        int d8 = c2 / 3, rem2 = c2 % 3;
        int d6 = 0;

        if (rem2 == 1 && rem3 == 1) { 
            d6 = 1; rem2 = 0; rem3 = 0; 
        } else if (rem2 == 2 && rem3 == 1) { 
            d6 = 1; rem2 = 1; rem3 = 0; 
        }

        int d4 = rem2 / 2; 
        rem2 %= 2;

        array<int, 10> res = {0};
        res[2] = rem2; res[3] = rem3; res[4] = d4;
        res[5] = c5;   res[6] = d6;   res[7] = c7;
        res[8] = d8;   res[9] = d9;
        return res;
    }

    string constructSuffix(const array<int, 10>& counts) {
        string res = "";
        for (int d = 2; d <= 9; ++d) {
            if (counts[d] > 0) {
                res.append(counts[d], '0' + d);
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        array<int, 4> primeCounts = {0, 0, 0, 0};
        const int primes[4] = {2, 3, 5, 7};

        // Step 1: Prime factorize t
        for (int i = 0; i < 4; ++i) {
            while (t % primes[i] == 0) {
                primeCounts[i]++;
                t /= primes[i];
            }
        }

        // If t has prime factors greater than 7, no digit product can ever match it
        if (t > 1) return "-1";

        int n = num.length();
        size_t firstZero = num.find('0');

        // Step 2: Check if num itself is valid (no zeros and product divisible by t)
        if (firstZero == string::npos) {
            array<int, 4> pref = {0, 0, 0, 0};
            for (char ch : num) {
                int d = ch - '0';
                for (int k = 0; k < 4; ++k) pref[k] += digitFactors[d][k];
            }
            bool ok = true;
            for (int k = 0; k < 4; ++k) {
                if (pref[k] < primeCounts[k]) { ok = false; break; }
            }
            if (ok) return num;
        }

        // Step 3: Compute prefix prime factor counts
        vector<array<int, 4>> prefList(n + 1, {0, 0, 0, 0});
        for (int i = 0; i < n; ++i) {
            prefList[i + 1] = prefList[i];
            if (num[i] != '0') {
                int d = num[i] - '0';
                for (int k = 0; k < 4; ++k) {
                    prefList[i + 1][k] += digitFactors[d][k];
                }
            }
        }

        int limitZero = (firstZero == string::npos) ? n : static_cast<int>(firstZero);

        // Step 4: Backtrack from right to left, attempting to replace num[i] with a larger digit
        for (int i = n - 1; i >= 0; --i) {
            if (i > limitZero) continue;
            int curDigit = num[i] - '0';

            for (int nextD = curDigit + 1; nextD <= 9; ++nextD) {
                array<int, 4> needed;
                for (int k = 0; k < 4; ++k) {
                    needed[k] = max(0, primeCounts[k] - prefList[i][k] - digitFactors[nextD][k]);
                }

                array<int, 10> minDigits = getMinDigits(needed);
                int totalReqLen = 0;
                for (int d = 2; d <= 9; ++d) totalReqLen += minDigits[d];

                int availableSpace = n - 1 - i;
                if (totalReqLen <= availableSpace) {
                    string ones(availableSpace - totalReqLen, '1');
                    return num.substr(0, i) + to_string(nextD) + ones + constructSuffix(minDigits);
                }
            }
        }

        // Step 5: If no valid configuration exists at length n, expand length to (n + 1) or more
        array<int, 10> fullDigits = getMinDigits(primeCounts);
        int totLen = 0;
        for (int d = 2; d <= 9; ++d) totLen += fullDigits[d];
        int targetLen = max(n + 1, totLen);

        return string(targetLen - totLen, '1') + constructSuffix(fullDigits);
    }
};