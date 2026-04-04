class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col = n / rows;
        string ans = "";
        for (int i=0;i<col;i++){
            int k = 0, j = i;

            while (k < rows && j < col) {
                ans += encodedText[k * col + j];
                k++;
                j++;
            }
        }
        int end = ans.find_last_not_of(' ');
        if (end == string::npos) return "";
        return ans.substr(0, end + 1);
    }
};