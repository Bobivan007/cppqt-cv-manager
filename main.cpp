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
    int experience () { int exp = mLastYear - mStartYear; return exp; }
    int job_start () const {return mStartYear; }
    int job_end () const {return mLastYear; }
    string get_comp() const {return mCompanyName; }
    string get_qual() const {return mqualification; }
    bool isValid() const
    {
     return !mCompanyName.empty() && ((mStartYear > 1960) && (mLastYear > 1960)) && !mqualification.empty();
    }
protected:
    int mStartYear, mLastYear;
    string mCompanyName, mqualification;
};

class CV
{
public:
    CV(const string &name, int birthYear, const string &skills) : mName{name}, mBirthYear{birthYear}, mSkills{skills}
    {

    }

    bool isValid() const
    {
         return !mName.empty() && ((mBirthYear > 1970) && (mBirthYear < 1995)) && !mSkills.empty();
    }

    void print() const
    {
            cout << mName << " (" << mBirthYear << ")" << endl;
            cout << "=====================" << endl;
            cout << "Skills: " << mSkills << endl;
            vector<JobRecord>::const_iterator it = mPreviousjob.begin();
            for (; it != mPreviousjob.end(); ++it)
            {
                cout << "Began in " << it->job_start() << " and ended in " << it->job_end() << endl << "In company: "<< it->get_comp()
                     << endl << "Worked as " << it->get_qual() << endl;
            }
            cout << endl;
    }
void addJobRecord (const JobRecord &obj)
{
    if (obj.isValid() )
    {
     mPreviousjob.push_back(obj);
    }
}
int Total_experience ()
{
    int sum_exp {0};
    vector<JobRecord>::iterator it = mPreviousjob.begin();
   for (; it != mPreviousjob.end(); ++it)
   {
     sum_exp += it->experience();
   }
   return sum_exp;
}

int siz () const {return mPreviousjob.size(); }
protected:
    string mName;
    int mBirthYear;
    string mSkills;
    vector<JobRecord> mPreviousjob;
};


int main()
{
JobRecord jfirstj {1991, 2001, "Global", "junior developer"};
JobRecord jsecondj {2001, 2002, "Global", "junior developer"};
    CV johnsCV {"John Jonson", 1978,"C++, Java"};
    if (jfirstj.isValid() && jsecondj.isValid())
    { johnsCV.addJobRecord(jfirstj);
      johnsCV.addJobRecord(jsecondj); }

JobRecord dfirstj {1994, 2000, "Global", "junior developer"};
JobRecord dsecondj {1994, 2000, "Global", "junior developer"};
    CV dansCV("Dan Davidson", 1988, "C++, Java");
    if (dfirstj.isValid() && dsecondj.isValid())
    { dansCV.addJobRecord(dfirstj);
      dansCV.addJobRecord(dfirstj); }

vector<CV> resume_list {johnsCV, dansCV};
int min_exp {5};
for ( auto& cv: resume_list)
{
    int sum_ex = cv.Total_experience();
    if (cv.isValid() && sum_ex >= min_exp)
        cv.print();
 }
    return 0;
}

