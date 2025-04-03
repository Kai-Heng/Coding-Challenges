/* Enter your macros here */

#define INF 100000000
#define FUNCTION(arg1, arg2) 
#define maximum(arg1, arg2) if(arg1 < arg2) arg1 = arg2
#define minimum(arg1, arg2) if(arg1 > arg2) arg1 = arg2
#define foreach(arg1, arg2) for(int i = 0; i < n; i++)
#define io(arg) cin >> v
#define toStr(arg) "Result ="

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}