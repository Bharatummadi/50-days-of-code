#define LL long long

#define MAXCHAR 26

class Node {
    public:
    int link;
    int t[MAXCHAR];
    int len, cnt;
    Node() {
        link = -1;
        for (int i = 0; i < MAXCHAR; ++i) {
            t[i] = -1;
        }
        len = -1;
        // d = sg = 0;
        cnt = 1;
    }
    Node(Node *a) {
        link = a->link;
        memcpy(t, a->t, sizeof(a->t));
        cnt = 0;
    }
};

class SAM {
public:
    int rt, last;
    int ndn;
    int ans;
    int ansIdx;
    vector<Node> nd;
    vector<vector<int> > nodes;
    
    vector<int> ml, ff, tt, idg;

    int newNode(Node *a = NULL) {
        if (!a) {
            nd.push_back(Node());
        } else {
            nd.push_back(Node(a));
        }
        return ndn++;
    }

    void pushLen(int idx) {
        if (nd[idx].len >= nodes.size()) {
            nodes.push_back(vector<int>());
        }
        nodes[nd[idx].len].push_back(idx);
    }
    void push(int c) {
        int cur = newNode();
        nd[cur].len = nd[last].len + 1;
        pushLen(cur);
        int v;
        for (v = last; (v != -1) && (nd[v].t[c] == -1); v = nd[v].link) {
            nd[v].t[c] = cur;
        }
        if (v != -1) {
            int p = v;
            int q = nd[v].t[c];
            if (nd[p].len + 1 == nd[q].len) {
                nd[cur].link = q;
            } else {
                int clone = newNode(&nd[q]);
                nd[clone].len = nd[p].len + 1;
                pushLen(clone);
                nd[cur].link = clone; nd[q].link = clone;
                for (int u = p; (u != -1) && (nd[u].t[c] == q); u = nd[u].link) {
                    nd[u].t[c] = clone;
                }
            }
        } else {
            nd[cur].link = rt;
        }
        last = cur;
    }
    SAM(string &s) {
        nodes.clear();
        nd.clear();
        ndn = 0;
        rt = newNode();
        nd[rt].len = 0; nd[rt].link = -1;
        pushLen(rt);
        last = rt;
        for (int i = 0; i < s.length(); ++i) {
            int c = s[i] - 'a';
            push(c);
        }
        ans = 0;
        ansIdx = -1;
    }
    void getCnt() {
        for (int i = nodes.size() - 1; i >= 0; --i) {
            for (int j = 0; j < nodes[i].size(); ++j) {
                int cur = nodes[i][j];
                if (nd[cur].cnt > 1) {
                    // ans = max(ans, (LL)(nd[cur].cnt) * (LL)(nd[cur].len));
                    // ans = max(ans, nd[cur].len);
                    if (nd[cur].len > ans) {
                        ans = nd[cur].len;
                        ansIdx = cur;
                    }
                }
                if (nd[cur].link == -1) {
                    continue;
                }
                nd[nd[cur].link].cnt += nd[cur].cnt;
            }
        }
    }
    void dfs(int cur) {
        vector<int> newC;
        for (int c = 0; c < MAXCHAR; ++c) {
            int t = nd[cur].t[c];
            if (t != -1) {
                if (ml[cur] + 1 > ml[t]) {
                    ml[t] = ml[cur] + 1;
                    ff[t] = cur;
                    tt[t] = c;
                }
                --idg[t];
                if (idg[t] == 0) {
                    newC.push_back(t);
                }
            }
        }
        for (int i = 0; i < newC.size(); ++i) {
            dfs(newC[i]);
        }
    }
    string dp() {
        ml = vector<int>(ndn, -1);
        ff = vector<int>(ndn, -1);
        tt = vector<int>(ndn, -1);
        
        idg = vector<int>(ndn, 0);
        for (int i = 0; i < ndn; ++i) {
            for (int c = 0; c < MAXCHAR; ++c) {
                if (nd[i].t[c] != -1) {
                    ++idg[nd[i].t[c]];
                }
            }
        }
        ml[0] = 0;
        dfs(0);
        
        string res = "";
        for (int p = ansIdx; p != 0; p = ff[p]) {
            res.push_back('a' + tt[p]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    string longestDupSubstring(string S) {
        SAM *sam = new SAM(S);
        sam->getCnt();
        if (sam->ansIdx == -1) {
            return "";
        }
        // cout << sam->ans << endl;
        return sam->dp();
    }
};
