#include "Student.h"

using namespace std;

istream &operator>>(istream &fin, Student &st) {
  fin >> st.lastName >> st.firstName >> st.imiaPaBacku
      >> st.educationLevel >> st.course >> st.kursa >> st.id;
  return fin;
}
 short int Student::getCourse() const {
  return this->course;
}
string Student::getFirstName() const {
  return this->firstName;
}
string Student::getLastName() const {
  return this->lastName;
}
string Student::getImiaPaBacku() const {
  return this->imiaPaBacku;
}
string Student::getEducationalLevel() const {
  return this->educationLevel;
}
long int Student::getId() const {
  return this->id;
}
ostream &operator<<(ostream &fout, const shared_ptr<Student> &ptr)  {
  fout << ptr->getLastName() << " " << ptr->getFirstName() << " " << ptr->getImiaPaBacku()
       << " " << ptr->getEducationalLevel() << " " << ptr->getCourse() << " kursa " << ptr->getId();
  return fout;
}
