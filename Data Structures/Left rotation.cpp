#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> rotateLeft(int d, vector<int> arr) {
    // [1, 2, 3, 4 ,5]
    // int d {2}
    // [2, 3, 4, 5, 1] -> [3, 4, 5, 1, 2]
    
    // s1 - plop out a[i0]
    // s2 - shift arr[iXs] left
    // s3 - plop in a[i0] at a[--arr.size()]
    
    std::vector<int> outputArr(arr.size());
    
    for (int inx {0}; inx < d; inx += 1) {
        int tempVar {arr[0]};
        
        for (int ext {0}; ext < arr.size(); ext += 1) {
            arr[ext] = arr[ext + 1];
            // arr[0] = arr[1];
            // arr[1] = arr[2];
            // arr[2] = arr[3];
            // ...
        }
        
        arr[(arr.size() - 1)] = tempVar;
    }
    
    return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = rotateLeft(d, arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
