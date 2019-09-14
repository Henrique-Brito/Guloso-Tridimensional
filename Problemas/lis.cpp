//LIS sem duplicata

vector<int> v;

template<typename T> int lis(vector<T> &v){
	vector<T> ans;
	for (T t : v){
		auto it = lower_bound(ans.begin(), ans.end(), t);
		if (it == ans.end()) ans.push_back(t);
		else *it = t;
	}
	return ans.size();
}

//LIS com duplicata

vector<int> v;

template<typename T> int lis(vector<T> &v){
	vector<T> ans;
	for (T t : v){
		auto it = upper_bound(ans.begin(), ans.end(), t);
		if (it == ans.end()) ans.push_back(t);
		else *it = t;
	}
	return ans.size();
}
