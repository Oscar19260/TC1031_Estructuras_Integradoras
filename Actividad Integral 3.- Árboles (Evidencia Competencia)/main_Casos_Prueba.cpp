#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "bst.h"

using namespace std;

int main(int argc, char* argv[]) {
	BST<int> bst;
	string ans;

	bst.add(10);
	ans =	"\n10\n";
	cout << " 1 " <<(!ans.compare(bst.inorder()) ? "success\n" : "fail\n");

	bst.add(12);
	bst.add(8);
	bst.add(110);
	bst.add(112);
	bst.add(18);

	ans = "\n8 10 12 18 110 112\n";
	cout << " 2 " <<(!ans.compare(bst.inorder()) ? "success\n" : "fail\n");

    bst.remove(18);
    ans = "\n8 10 12 110 112\n";
	cout << " 3 " <<(!ans.compare(bst.inorder()) ? "success\n" : "fail\n");
	cout << " 4 " <<(0 == bst.find(13) ? "success\n" : "fail\n");
    cout << " 5 " <<(1 == bst.find(10) ? "success\n" : "fail\n");
}