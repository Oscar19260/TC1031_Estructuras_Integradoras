#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "bst.h"

using namespace std;

int main(int argc, char* argv[]) {
	BST<string> bst;
	string ans;

	bst.add("a01705544@itesm.mx");
	ans =	"\na01705544@itesm.mx\n";
	cout << " 1 " <<(!ans.compare(bst.inorder()) ? "success\n" : "fail\n");

	bst.add("a01705690@itesm.mx");
	bst.add("a01706443@itesm.mx");
	bst.add("a01706543@itesm.mx");
	bst.add("dedehoh809@gmail.com");
	bst.add("coxonot273@outlook.com");

	ans = "\na01705544@itesm.mx\na01705690@itesm.mx\na01706443@itesm.mx\na01706543@itesm.mx\ncoxonot273@outlook.com\ndedehoh809@gmail.com\n";
	cout << " 2 " <<(!ans.compare(bst.inorder()) ? "success\n" : "fail\n");

    bst.remove("coxonot273@outlook.com");
    ans = "\na01705544@itesm.mx\na01705690@itesm.mx\na01706443@itesm.mx\na01706543@itesm.mx\ndedehoh809@gmail.com\n";
	cout << " 3 " <<(!ans.compare(bst.inorder()) ? "success\n" : "fail\n");
	cout << " 4 " <<(0 == bst.find("semeha7191@gmail.com") ? "success\n" : "fail\n");
    cout << " 5 " <<(1 == bst.find("a01705544@itesm.mx") ? "success\n" : "fail\n");
}