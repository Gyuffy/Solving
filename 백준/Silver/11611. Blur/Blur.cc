#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int w, h, b;
	cin >> w >> h >> b;

	// 초기 이미지는 0 또는 1로 구성됨.
	vector<vector<long long>> grid(h, vector<long long>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> grid[i][j];
		}
	}

	// b번 블러링 처리
	for (int iter = 0; iter < b; iter++) {
		vector<vector<long long>> newGrid(h, vector<long long>(w, 0));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				long long sum = 0;
				// 3×3 영역 순회 (wrap-around 적용)
				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1; dj++) {
						int ni = (i + di + h) % h;
						int nj = (j + dj + w) % w;
						sum += grid[ni][nj];
					}
				}
				newGrid[i][j] = sum; // 새 픽셀 값 = sum / 9, 하지만 분모는 모두 동일하므로 분자만 저장
			}
		}
		grid = newGrid;
	}

	// 최종 이미지의 모든 픽셀 분자 값의 집합의 크기를 계산.
	set<long long> shades;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			shades.insert(grid[i][j]);
		}
	}

	cout << shades.size() << "\n";
	return 0;
}
