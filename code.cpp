#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    wstring s = L"ナンジブンガクトカガクノチカラヲシンジヨ";
    wstring t = L"ジョウホウブンセキシテカイゼンアクション";
    int len_s = s.size();
    int len_t = t.size();

    // 最長共通部分列の長さを求める
    // dp[i][j] := sの前i文字とtの前j文字のみを見た時の最長共通部分列
    vector dp(len_s + 1, vector<int>(len_t + 1, 0));

    for (int i = 0; i < len_s; i++) {
        for (int j = 0; j < len_t; j++) {
            dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);

            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
        }
    }

    // 最長共通部分列を後ろから復元する
    wstring answer = L"";
    int s_index = len_s - 1, t_index = len_t - 1;
    while (s_index >= 0 and t_index >= 0) {
        if (s[s_index] == t[t_index]) {
            answer += s[s_index];
            s_index--;
            t_index--;
        }

        else if (dp[s_index + 1][t_index + 1] == dp[s_index][t_index + 1]) {
            s_index--;
        }

        else {
            t_index--;
        }
    }
  
    // 後ろからの復元なので最後に反転
    reverse(answer.begin(), answer.end());

    wcout << L"answer is ... " << answer << endl;
}
