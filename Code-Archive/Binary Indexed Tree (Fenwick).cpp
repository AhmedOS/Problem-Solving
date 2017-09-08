//Reference: http://zobayer.blogspot.com.eg/2013/11/various-usage-of-bit.html

//Must be 1-Indexed

//Basic Functions
void update(long long fen[], int idx, long long val){
    for(int i = idx; i <= n; i += (i & -i))
        fen[i] += val;
}
long long query(long long fen[], int idx){
    long long ret = 0;
    for(int i = idx; i; i -= (i & -i)) //remove first one bit
        ret += fen[i];
    return ret;
}

//Update an Index - Query a Range (update via the basic function)
long long query_range(long long fen[], int s, int e) {
	return query(fen, e) - query(fen, s - 1);
}

//Update a Range - Query an Index (query via the basic function)
void update_range(long long fen[], int s, int e, long long val) {
	update(fen, s, val);
	update(fen, e + 1, -val);
}

//Update a Range - Query a Range (two Fenwick trees are needed)
void update_rr(long long fen[], long long fen2[], int s, int e, long long val) {
	update(fen, s, val);
	update(fen, e + 1, -val);
	update(fen2, s, val * (s - 1));
	update(fen2, e + 1, -val * e);
}
long long query_rr(long long fen[], long long fen2[], int idx){
    return query(fen, idx) * idx - query(fen2, idx);
}
