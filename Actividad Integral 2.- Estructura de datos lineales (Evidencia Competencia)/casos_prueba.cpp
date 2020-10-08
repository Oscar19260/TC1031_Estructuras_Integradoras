#include <iostream>
#include "list.h"

using namespace std; 

int main(){
    List<string> l1;
    string ans;
    l1.add("Oscar");
    ans = "[Oscar]";
    cout<< "1 " << (!ans.compare(l1.toString()) ? "success\n" : "fail\n");
    l1.add("Pepe");
    l1.add("Carlos");
    l1.add("Benjamin");
    ans = "[Oscar, Pepe, Carlos, Benjamin]";
    cout<< "2 " << (!ans.compare(l1.toString()) ? "success\n" : "fail\n");
    cout <<"3 " <<  ("Carlos" == l1.find("Carlos") ? "success\n" : "fail\n");
	cout <<"4 " <<  ("-1" == l1.find("Juan") ? "success\n" : "fail\n");

    l1.remove("Oscar");
	ans = "[Pepe, Carlos, Benjamin]";
	cout << "5 " <<	(!ans.compare(l1.toString()) ? "success\n" : "fail\n");

	l1.remove("Carlos");
	ans = "[Pepe, Benjamin]";
	cout << "6 " <<	(!ans.compare(l1.toString()) ? "success\n" : "fail\n");

    l1.remove("Ester");
	ans = "[Pepe, Benjamin]";
	cout << "7 " <<	(!ans.compare(l1.toString()) ? "success\n" : "fail\n");

    return 0;
}