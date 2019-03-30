#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi goal;
string c[4] {"U", "D", "R", "L"};
int N,
	dx[4] {0, 0, 1, -1},
	dy[4] {-1, 1, 0, 0};
map<vvi, int> visit;

class State
{
public:
	int x, y, cost;
	vvi board;
	string step = "";
	friend bool operator > (const State& l, const State& r) {
		return l.cost > r.cost;
	};
};

void printState(vvi state)
{
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			cout<<state[i][j]<<' ';
		}
		cout<<endl;
	}
}

int manhattanDist(vvi state)
{
	int dist = 0;
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			if (state[i][j] != 0) {
				int y = state[i][j]/N;
				int x = state[i][j]-y*N;
				int diff = abs(i-y) + abs(j-x);
				dist += diff;
			}
		}
	}
	return dist;
}

State AStar(State init)
{
	priority_queue<State, vector<State>, greater<vector<State>::value_type>> pq;
	pq.push(init);
	visit[init.board] = 0;
	while (!pq.empty()) {
		State current = pq.top();
		pq.pop();
		if (current.board == goal)
			return current;
		for (int i=0;i<4;i++) {
			int nx = current.x + dx[i],
				ny = current.y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				State next = current;
				next.step += c[i];
				swap(next.board[next.y][next.x], next.board[ny][nx]);
				next.x = nx;
				next.y = ny;
				next.cost = manhattanDist(next.board) + next.step.length(); // f(n) = h(n) + g(n)
				if (visit.find(next.board) == visit.end() || visit[next.board] > next.step.length()) {
					visit[next.board] = next.step.length();
					pq.push(next);
				}
			}
		}
	}
	return init;
}

int main()
{
	cout<<"Insert Puzzle Size (nxn) : ";
	cin>>N;
	cout<<"Insert Initial State :\n";
	State init;
	for (int i=0;i<N;i++) {
		goal.push_back(vi());
		init.board.push_back(vi());
		for (int j=0;j<N;j++) {
			if (!i && !j) goal[i].push_back(0);
			else goal[i].push_back(i*N+j);
			int temp;
			cin>>temp;
			init.board[i].push_back(temp);
			if (temp == 0) {
				init.x=j;init.y=i;
			}
		}
	}
	init.cost = manhattanDist(init.board);
	cout<<endl;
	State end = AStar(init);
	if (end.board == goal) {
		cout<<"Step: "<<end.step.length()<<endl<<"Solution: "<<end.step<<endl;
	}
	else cout<<"Cannot found the solution";
}
