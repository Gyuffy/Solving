#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

// 여러 구분자를 기준으로 문자열 토큰 분리 함수
vector<string> tokenize(const string &s, const string &delims) {
	vector<string> tokens;
	string token;
	for (char c : s) {
		if (delims.find(c) != string::npos) {
			if (!token.empty()) {
				tokens.push_back(token);
				token.clear();
			}
		}
		else {
			token.push_back(c);
		}
	}
	if (!token.empty()) {
		tokens.push_back(token);
	}
	return tokens;
}

int getAnswer(const string &a, const string &b) {
	// 첫번째 문자열 a를 ":, "를 구분자로 토큰화하여 key-value 쌍을 저장
	vector<string> tokensA = tokenize(a, ":, ");
	unordered_map<string, int> hm;
	for (size_t i = 0; i + 1 < tokensA.size(); i += 2) {
		hm[tokensA[i]] = stoi(tokensA[i + 1]);
	}

	// 두번째 문자열 b를 "| "를 구분자로 토큰화하여 각각의 그룹 처리
	vector<string> groups = tokenize(b, "| ");
	int answer = numeric_limits<int>::max();

	for (const string &group : groups) {
		// 각 그룹 내의 토큰들을 "& "를 구분자로 토큰화
		vector<string> tokensGroup = tokenize(group, "& ");
		int groupMax = -1;
		for (const string &token : tokensGroup) {
			groupMax = max(groupMax, hm[token]);
		}
		answer = min(answer, groupMax);
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	cin.ignore(); // 개행 문자 제거
	while (tc--) {
		string a, b;
		getline(cin, a);
		getline(cin, b);
		cout << getAnswer(a, b) << "\n";
	}

	return 0;
}
