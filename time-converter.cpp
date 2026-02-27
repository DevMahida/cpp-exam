#include <iostream>

using namespace std;

class TimeConverter
{
public:

    void sToH()
    {
        int seconds;

        cout << "Enter the time in seconds : ";
        cin >> seconds;

        int ss = seconds % 60;

        int second = seconds / 60;
        int mm = second % 60;
        int hh = second / 60;

        if (ss == 0)
        {
            cout << "HH:MM:SS => " << hh << ":" << mm << ":" << "00";
        }
        else if (ss / 10 == 0)
        {
            cout << "HH:MM:SS => " << hh << ":" << mm << ":" << ss * 10;
        }
        else
        {
            cout << "HH:MM:SS => " << hh << ":" << mm << ":" << ss;
        }
    }

    void hToS()
    {
        int hh, mm, ss;

        cout << "Enter hours : ";
        cin >> hh;
        cout << "Enter minutes : ";
        cin >> mm;
        cout << "Enter seconds : ";
        cin >> ss;

        int seconds = (hh * 3600) + (mm * 60) + ss;

        cout << "total secods : " << seconds;
    }
};

int main()
{
    int num;
    TimeConverter t1;

    cout << "press 1 for seconds to HH:MM:SS." << endl;
    cout << "press 2 for HH:MM:SS to seconds." << endl;
    cout << "Enter Your Choice: ";
    cin >> num;

    switch (num)
    {
    case 1:
        t1.sToH();
        break;

    case 2:
        t1.hToS();
        break;

    default:
        break;
    }

    return 0;
}
