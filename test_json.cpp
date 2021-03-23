#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
using json = nlohmann::json;
	
int main()
{
	cout<<"Json test"<<endl;

	json j;
	j["name"]="castor";
	j["sex"]="male";
	j["age"]=12;

	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

    std::string str = "";
	for (size_t j = 0; j < v.size(); ++j) {
	str += std::to_string(v[j]) + (j + 1 < v.size() ? ", " : "");
	}
	j["vec"] = str;

	cout << j.dump(2) << endl;

	json j2 = json::array();
	j2.push_back(j);
	j2.push_back(j);
	cout << j2.dump(2) << endl;
	
	return 0;
}