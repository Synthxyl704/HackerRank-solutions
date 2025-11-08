#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int hourglassSum(vector<vector<int>> arr) {
    int maxSum {-63}; // minimum possible value (7 * (-9))

    // arr[row][column]
    // 3 boobs + 1 middle waist + 3 bottom ass {hourglassx}
    // a[boobs = row][ass = coloumn?] -- nah doesnt work
    
    // arr[booba][spine] + arr[booba + 1][spine + 1] + arr[booba + 2][spine + 2]
    // arr[waist + 1][spine + 1]
    for (int inx{0}; inx < 4; inx += 1) {
        /* we're gonna brute force it fuck it */
        for (int ext {0}; ext < 4; ext += 1) {
            int currentSum {  
                // 0 1 2 3
                // 4 * 4 {16}
                
                // [row][col] // start from 1st, theres 16 of them
                // [row][col + 1] (sway hand across the boobs on X-axis ie col)
                // [row][col + 2]
                // [row + 1][col + 1] (middle of her waist) middle int
                // [row + 2][col] + arr[col + 1] + arr[col + 2] (sway hand across her hips)

                // think of a hot anime girl (esdeath?)
                arr[inx][ext] + arr[inx][ext + 1] + arr[inx][ext + 2] // her chest
                + arr[inx + 1][ext + 1] // her waist 
                + arr[inx + 2][ext] + arr[inx + 2][ext + 1] + arr[inx + 2][ext + 2] // her ass
            }; // perfect harmony!!!

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    } return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
