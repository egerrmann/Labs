#include <iostream>
#include <fstream>
#include <memory>
#include <iterator>
#include <string>
#include <regex>
#include "Student.h"

using namespace std;

int main() {
  ifstream fin ("input.txt");
  string temp;
  vector <string> studentsCollection;
  while (getline(fin, temp)) {
    studentsCollection.push_back(temp);
    temp.clear();
  }
  fin.close();
  ofstream fout ("output.txt");
  regex expression(R"(^(\D+)\d+(\D+)\d+(\D+)\d+(\D+)\d+(\d)\D+\d+(\d{8})$)");
  for (int i = 0; i < studentsCollection.size(); ++i) {
    fout << regex_replace(studentsCollection[i], expression,
                          "$1 $2 $3 $4 $5 kursa $6") << endl;
  }
  fout.close();
  ifstream in ("output.txt");
  vector<Student> students;
  vector<shared_ptr<Student>> ptrVectorOfStudents(studentsCollection.size());
  copy(istream_iterator<Student>(in), istream_iterator<Student>(),
      back_inserter(students));
  for (int i = 0; i < studentsCollection.size(); ++i) {
    ptrVectorOfStudents[i] = make_shared<Student>(students[i]);
  }
  cout << "What minimal course is required? Insert number..." << endl;
  int minimalCourse;
  cin >> minimalCourse;
  auto condition = remove_if(ptrVectorOfStudents.begin(),
                             ptrVectorOfStudents.end(),
                             [minimalCourse](const shared_ptr<Student> &st)
                             { return st->getCourse() < minimalCourse; });
  ptrVectorOfStudents.erase(condition, ptrVectorOfStudents.end());
  sort(ptrVectorOfStudents.begin(), ptrVectorOfStudents.end(),
       [](shared_ptr<Student> &st1, shared_ptr<Student> &st2) {
         if (st1->getLastName() != st2->getLastName()) {
           return st2->getLastName() > st1->getLastName();
         } else {
           if (st1->getFirstName() != st2->getFirstName()) {
             return st2->getFirstName() > st1->getFirstName();
           }
           if (st1->getFirstName() == st2->getFirstName()) {
             if (st1->getImiaPaBacku() != st2->getImiaPaBacku()) {
               return st2->getImiaPaBacku() > st1->getImiaPaBacku();
             }
           }
         }
  });
  ostream_iterator<shared_ptr<Student>> out_it (cout, "\n");
  copy(ptrVectorOfStudents.begin(), ptrVectorOfStudents.end(), out_it);
  while (true) {
    cout << "Insert your last name, first name and imia pa backu" << endl;
    string ln, fn, ipb;
    cin >> ln >> fn >> ipb;
    string fio = ln + " " + fn + " " + ipb;
    string compare;
    for (int i = 0; i < ptrVectorOfStudents.size(); ++i) {
      compare = ptrVectorOfStudents[i]->getLastName() + " " +
          ptrVectorOfStudents[i]->getFirstName() + " " +
          ptrVectorOfStudents[i]->getImiaPaBacku();
      if (fio == compare) {
        cout << ptrVectorOfStudents[i]->getId() << endl;
        break;
      }
      if (i == ptrVectorOfStudents.size() - 1){
        cout << "Incorrect data" << endl;
      }
    }
  }
  return 0;
}
