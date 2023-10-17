#include <bits/stdc++.h>
using namespace std;

class disjointset{
	vector<int> rank , parent , size;
public:
	disjointset(int n){
		rank.resize(n+1 , 0);
		size.resize(n+1 , 0);
		parent.resize(n+1);
		for(int i=0;i<=n;i++) parent[i] = i;
	}

	int findUparent(int node){
		if(node == parent[node]) return node;
		return parent[node] = findUparent(parent[node]);
	}

	void UnionByRank(int u , int v){
		int ultimateparent_u = findUparent(u);
		int ultimateparent_v = findUparent(v);

		if(ultimateparent_u == ultimateparent_v) return;
		
		if(rank[ultimateparent_u] < rank[ultimateparent_v]){
			parent[ultimateparent_v] = ultimateparent_u;
		}
		else if(rank[ultimateparent_u] > rank[ultimateparent_v]){
			parent[ultimateparent_u] = ultimateparent_v;
		}
		else{
			rank[ultimateparent_u]++;
			parent[ultimateparent_v] = ultimateparent_u;
		}
	}
	
	void UnionBySize(int u , int v){
		int ultimateparent_u = findUparent(u);
		int ultimateparent_v = findUparent(v);

		if(ultimateparent_u == ultimateparent_v) return;

		if(size[ultimateparent_u] < size[ultimateparent_v]){
			parent[ultimateparent_u] = ultimateparent_v;
			size[ultimateparent_v] += size[ultimateparent_u];
		}
		else{
			parent[ultimateparent_v] = ultimateparent_u;
			size[ultimateparent_u] += size[ultimateparent_v];
		}
	}
};
int main() {
	disjointset ds(7);
	ds.UnionBySize(1 , 2);
	ds.UnionBySize(2 , 3);
	ds.UnionBySize(4 , 5);
	ds.UnionBySize(6 , 7);
	ds.UnionBySize(5 , 6);

	if(ds.findUparent(3) != ds.findUparent(7)){
		cout<<"NO"<<endl;
	}
	else cout<<"YES"<<endl;

	ds.UnionBySize(3 , 7);
	if(ds.findUparent(3) != ds.findUparent(7)){
		cout<<"NO"<<endl;
	}
	else cout<<"YES"<<endl;

	return 0;
}
