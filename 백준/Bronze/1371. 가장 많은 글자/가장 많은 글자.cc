#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct compare {
	bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
		// 빈도수가 같다면 오름차순(또는 원하는 순서)으로 문자 비교
		if (a.second == b.second)
			return a.first < b.first;
		// 빈도수가 큰 것이 앞에 오도록 정렬
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("sample_input.txt", "r", stdin);

	string str;
	// 일반 map으로 문자별 빈도수 카운팅
	map<char, int> letter;
	while (cin >> str) {
		for (char c : str) {
			letter[c]++;
		}
	}

	// map의 내용을 vector에 복사
	vector<pair<char, int>> vec(letter.begin(), letter.end());

	// 사용자 정의 비교자로 vector 정렬
	sort(vec.begin(), vec.end(), compare());

	// 최대 빈도수를 가진 문자들 출력 (최대 빈도수는 vec[0].second)
	int maxFrequency = vec.front().second;
	for (const auto &p : vec) {
		if (p.second == maxFrequency)
			cout << p.first;
		else
			break;
	}

	return 0;
}
