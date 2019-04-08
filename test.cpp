#include <iostream>
#include <fstream> //file stream
#include <sstream> //string stream

using namespace std;

struct Student{
	//ID, name, major
	int ID;
	string name;
	string major;
	Student(){}
	Student(int id, string n, string m){
		ID = id;
		name = n;
		major = m;
	}
};

int main(){
	//array of Students
	//this will be populated with file data
	Student allStudents[10];
	//streams
	ifstream myfile("students.txt");

  cout<<"First we will print the String Stream"<<endl<<endl;
	if(myfile.is_open()){
		//read the file
		string line;
		int counter = 0;
		while(getline(myfile, line)){
			cout<<line<<endl;
			//string stream - include sstream
			stringstream ss;
			//write line string into string stream
			ss<<line;
			string item;

			getline(ss, item, ',');
			allStudents[counter].ID = stoi(item);
			//how do I read name?
			getline(ss, item, ',');
			allStudents[counter].name = item;

			getline(ss, item);
			allStudents[counter].major = item;

			counter++;

		}

	}else{
		cout<<"error"<<endl;
	}
	//verify contents of allStudents array
  cout<<endl<<endl<<"Now, we will print the contents of the array"<<endl<<endl;
	for(int i = 0; i < 10; i++){
		cout<<allStudents[i].ID<<" "<<allStudents[i].name<<" "<<allStudents[i].major<<endl;
	}
}
