#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class JobRecord
{
public:

    JobRecord(int start_year, int end_year, const string &company_name, string qualification) :
     mStartYear{start_year}, mLastYear{end_year}, mCompanyName{company_name}, mqualification{qualification}
{

}
    int job_start () {return mStartYear; }
    int job_end () {return mLastYear; }
protected:
    int mStartYear, mLastYear;
    string mCompanyName, mqualification;
};

class CV: public JobRecord
{
public:
    CV(const string &name, int birthYear, const string &skills,
       int start_year, int end_year, const string &company_name, string qualification) :
       JobRecord(start_year, end_year, company_name, qualification), mName{name}, mBirthYear{birthYear}, mSkills{skills}
    {

    }

    bool isValid(vector<string> &vec) const
    {
    vector<string> :: iterator it = find(vec.begin(), vec.end(), mqualification);
    if (it == vec.end() ) {cout << "Invalid qualification, choose one of the given: " << endl; return false; }
     else return !mName.empty() && ((mBirthYear > 1970) && (mBirthYear < 1995))
            && !mSkills.empty();!mCompanyName.empty() && ((mStartYear > 1960) && (mLastYear > 1960)); !mqualification.empty();
    }
    void print() const
    {
            cout << mName << " (" << mBirthYear << ")" << endl;
            cout << "=====================" << endl;
            cout << "Skills: " << mSkills << endl;
            cout << "Started working in " << mStartYear << " and finished in " << mLastYear << endl;
            cout << "Company: " << mCompanyName << endl;
            cout << "Worked as a: " << mqualification << endl;
            cout << endl;
    }

private:
    string mName;
    int mBirthYear;
    string mSkills;
};

int main()
{
    cout << "Write your data in this order: Full name, birth, skills, start working, end working, previous company, position" << endl;
    cout << endl;
    cout << "OH, and by the way, there are 3 optional positions: junior developer, developer, senior software developer" << endl;
vector<string> qual_vec {"junior developer", "developer", "senior software developer"};

    CV johnsCV {"John Jonson", 1978,"C++, Java", 1994, 2000, "Global", "junior developer"};
    CV dansCV("Dan Davidson", 1988, "C++, Java", 1994, 2000, "Global", "developer");
    CV bohdanCV ("Bohdan Dmyrtyk", 1994, "C++, Objective-C", 2010, 2015, "Lviv POlitech", "junior developer");
vector<CV> resume_list {johnsCV, dansCV, bohdanCV};
for ( auto& cv: resume_list)
{
    int wbeg = cv.job_start();
    int wend = cv.job_end();
    int experience = wend - wbeg;
    if (experience >=5 ) {
    if (cv.isValid(qual_vec))
    {
        cv.print();
    }
    else cout << "ERROR: CV is invalid" << endl;
    }
}
    return 0;
}

