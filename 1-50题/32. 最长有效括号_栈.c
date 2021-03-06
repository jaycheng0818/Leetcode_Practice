int longestValidParentheses(char* s) {
	int maxans = 0, n = strlen(s);
	int stk[n + 1], top = -1;
	stk[++top] = -1;
	
	for (int i = 0; i < n; i++) {
		// '(' 下标入栈
		// ')' 栈顶元素出栈
		if (s[i] == '(') {
			stk[++top] = i;
		} else {
			--top;
			if (top == -1) {
				stk[++top] = i;
			} else {
				maxans = fmax(maxans, i - stk[top]);
			}
		}
	}
	return maxans;
}