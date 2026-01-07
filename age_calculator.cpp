#include<iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 400 == 0) ||
           (year % 4 == 0 && year % 100 != 0);
}

//  Days in each month calculation 
int daysInMonth(int month, int year) {
    if (month == 2)
        if(isLeapYear(year)) 
        return 29;
        else{
        return 28;
        }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}

int main() {

// Dates input and its validation 
    int bd,bm,by;
    int td,tm,ty;
    int ad,am,ay;
    char slash;
    cout << "Enter you DOB i.e(Dd-Mm-Yyyy)" << endl;
    cin >> bd>>slash>>bm>>slash>>by;
    
    cout << "Enter todays date i.e(Dd-Mm-Yyyy)" << endl;
    cin >> td>>slash>>tm>>slash>>ty;

    if(ty<by or (bd>31 or bd<1) or (bm>12 or bm<1)
            or (td>31 or td<1) or (tm>12 or tm<1))
    {
        cout << "Invalid input...." << endl;
        return 0;
    }
    
// Days calculation    
    if(td<bd) {
        tm -= 1;
        if(tm==0){
            tm=12;
            ty--;
        }
        td += daysInMonth(tm,ty);
        ad = td-bd;
    }
    else {
        ad = td-bd;
    }
    
//  Months calculation   
    if(tm<bm) {
        tm += 12;
        ty -= 1;
        am = tm-bm;
    }
    else {
        am = tm-bm;
    }
    
// Years Calculation    
    ay = ty-by;
    if(ay>0)
    
// display calculated age    
    cout <<"\n"<< ay<<" Years "<<am<<" Months "<<ad<<" days" << endl;
    else
    cout <<"\n"<<am<<" Months "<<ad<<" days" << endl;
    
// Total Days Calculation ( age in days )    
    int days;
    if(ay>0) {
        for(int j=by+1; j<ty; j++) {
            for(int i=1; i<=12; i++) {
                days += daysInMonth(i,j);
            }
        }
        for(int i=bm+1; i<=12; i++) {
            days += daysInMonth(i,by);
        }
        for(int i=tm-1; i>0; i--) {
            days += daysInMonth(i,ty);
        }
        int  initial = daysInMonth(bm,by) - bd;
        days += initial;
        int  lasts = td;
        days += lasts;
        // days are calcuted but i will display in a sequence 
    }
    else {
        if(tm-bm<1){
            for(int i=bm+1; i<=12; i++) {
                days += daysInMonth(i,by);
            }
            for(int i=tm-1; i>0; i--) {
                days += daysInMonth(i,ty);
            }
        }
        else{
            for(int i=bm+1; i<=tm-1; i++) {
                days += daysInMonth(i,by);
            }
        }    
        int  initial = daysInMonth(bm,by) - bd;
        days += initial;
        int  lasts = td;
        days += lasts;
        // days are calcuted but i will display in a sequence 
    }
    
// Total months Calculation (age in months)
    am += ay*12;
    cout << am<<" Months " <<ad<<" days"<< endl;    
    
// Total Weeks Calculation    
    int weeks,rday;
    weeks = days/7;
    rday = days % 7;
    if(rday>0)
    cout << weeks<<" weeks " << rday <<" days"<<endl;
    else
    cout << weeks<<" weeks " << endl;
    
// days display
    cout << days<<" Days" << endl;    
    
// Age in hours,minutes and seconds    
    long int hours,min,sec;
    hours= days*24;
    min= hours*60;
    sec= min*60;
    cout << hours<<" hours" << endl;
    cout << min<<" minutes" << endl;
    cout << sec<<" seconds" << endl;
    
    return 0;
}