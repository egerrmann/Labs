#ifndef LAB_1__STUDENT_H_
#define LAB_1__STUDENT_H_
#include "iostream"
#include "string"
#include "memory"

using namespace std;

class Student {
 public:
  friend istream& operator>> (istream& fin, Student& st);
  friend ostream& operator<< (ostream& fout, const shared_ptr<Student> &ptr);
  string getFirstName() const;
  string getLastName() const;
  string getImiaPaBacku() const;
  string getEducationalLevel() const;
  short int getCourse() const;
  long int getId() const;
 private:
  string firstName;
  string lastName;
  string imiaPaBacku;
  string educationLevel;
  short int course;
  string kursa;
  long int id;
};
#endif //LAB_1__STUDENT_H_
