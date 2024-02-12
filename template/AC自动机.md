# AC自动机

```c++
struct Trie {
	int id[27], cnt, fail;
} t[N];
void Build(string &s) {
	int now = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!t[now].id[s[i] - 'a']) t[now].id[s[i] - 'a'] = ++cnt;
		now = t[now].id[s[i] - 'a'];
	}
	t[now].cnt++;
}
void Fail() {
	queue <int> q;
	for (int i = 0; i < 26; i++) {
		int v = t[0].id[i];
		if (v != 0) {
			t[v].fail = 0;
			q.push(v);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; i++) {
			int v = t[u].id[i];
			if (v != 0) {
				t[v].fail = t[t[u].fail].id[i];
				q.push(v);
			}
			else t[u].id[i] = t[t[u].fail].id[i];
		}
	}
}
string s;
int ans;
void Query() {
	int now = 0;
	for (int i = 0; i < s.size(); i++) {
		now = t[now].id[s[i] - 'a'];
		for (int to = now; to; to = t[to].fail) {
			if (t[to].cnt == -1) break;
			ans += t[to].cnt;
			t[to].cnt = -1;
		}
	}
}


```