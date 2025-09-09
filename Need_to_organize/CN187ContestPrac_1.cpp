#include <bits/stdc++.h> 
using namespace std;
int goodnessScore(string S) {
    // Write your code here.
        map<char, vector<char>> letterHashTables;

    for (char ch : S) {
        if (isalpha(ch)) {
            char key = tolower(ch); // Normalize key
            letterHashTables[key].push_back(ch); // Store original character
        }
    }

    // Step 2: Initialize global goodness score
    int goodness_score = 0;

    // Step 3: Traverse each hash table
    for (const auto& entry : letterHashTables) {
        char letter = entry.first;
        const vector<char>& chars = entry.second;

        int upper_count = 0, lower_count = 0;

        for (char ch : chars) {
            if (isupper(ch)) upper_count++;
            else if (islower(ch)) lower_count++;
        }

        // Step 4: Apply goodness score rule
        if (upper_count > lower_count) {
            goodness_score += 1;
        } else if (upper_count < lower_count) {
            goodness_score -= 1;
        }

        // Print debug info for this letter's table
        cout << "Letter '" << letter << "': uppercase=" << upper_count
             << ", lowercase=" << lower_count
             << " -> goodness_score now = " << goodness_score << endl;
    }

    // Final output
    cout << "\nFinal Goodness Score: " << goodness_score << endl;
    return goodness_score;
}

int main()
{
    string k = "AABae";
    int score = goodnessScore(k);
    cout<<score;
    return 0;
}




