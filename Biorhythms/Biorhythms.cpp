#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <math.h> 

#define PI 3.141592653590f
class Biorhythms
{
public:

    Biorhythms(int BirthDay, int BirthMonth, int BirthYear,
               int CurrentDay, int CurrentMonth, int CurrentYear){

        Birth_Day = BirthDay;
        Birth_Month = BirthMonth;
        Birth_Year = BirthYear;

        Current_Day = CurrentDay;
        Current_Month = CurrentMonth;
        Current_Year = CurrentYear;

    }

    void Main(){
        Diff_Days = GetDiffernce();

        Remainder();

        // gets the percentage for each type
        Percent_28 = 50.0f * sin(((2.0f * PI) / 28.0f) * ((float)Remainder_28)) + 50.0f;
        Percent_23 = 50.0f * sin(((2.0f * PI) / 23.0f) * ((float)Remainder_23)) + 50.0f;
        Percent_33 = 50.0f * sin(((2.0f * PI) / 33.0f) * ((float)Remainder_33)) + 50.0f;

        AveragePercent = GetAvg();
        
        PrintData();
    }

private:

    void PrintData() {
        std::cout << "Your emotional percentage was: " << Percent_28 << std::endl;
        std::cout << "Your physical percentage was: " << Percent_23 << std::endl;
        std::cout << "Your intellectual percentage was: " << Percent_33 << std::endl;
        std::cout << "Your overall average percentage was: " << AveragePercent << std::endl;
    }

    float GetAvg() {
        float sum = Percent_28 + Percent_23 + Percent_33;
        return sum / 3.0f;
    }

    int GetDiffernce(){
        struct std::tm b = { 0,0,0, Current_Day, Current_Month, Current_Year + 100 };
        struct std::tm a;
        if (Birth_Year < 25)
        {
            a = { 0,0,0,Birth_Day, Birth_Month, Birth_Year + 100 };
        }
        else {
            a = { 0,0,0,Birth_Day, Birth_Month, Birth_Year };
        }
        std::time_t x = std::mktime(&a);
        std::time_t y = std::mktime(&b);
        if (x != (std::time_t)(-1) && y != (std::time_t)(-1))
        {
            double difference = std::difftime(y, x) / (60 * 60 * 24);
            return difference;
        }
    }

    void Remainder() {

        Remainder_28 = (Diff_Days % 28) - 1;
        Remainder_23 = (Diff_Days % 23) - 1;
        Remainder_33 = (Diff_Days % 33) - 1;
    }

    float AveragePercent;

    float Percent_28;
    float Percent_23;
    float Percent_33;

    int Remainder_28;    
    int Remainder_23;
    int Remainder_33;

    int Diff_Days;

    int Current_Day;
    int Current_Month;
    int Current_Year;
    
    int Birth_Day;
    int Birth_Month;
    int Birth_Year;
};

int main()
{
    int day_born, month_born, year_born, day_check, month_check, year_check;
    std::cout << "What day date were you born on?" << std::endl;
    std::cout << "example: for 14 September 2004, input 14" << std::endl;
    std::cin >> day_born;
    std::cout << std::endl;

    std::cout << "What month date were you born on?" << std::endl;
    std::cout << "example: for 14 September 2004, input 9" << std::endl;
    std::cin >> month_born;
    std::cout << std::endl;

    std::cout << "What year date were you born on?" << std::endl;
    std::cout << "example: for 14 September 2004, input 4" << std::endl;
    std::cin >> year_born;
    std::cout << std::endl;


    std::cout << "What day date would you like to check?" << std::endl;
    std::cout << "example: for 14 May 2022, input 14" << std::endl;
    std::cin >> day_check;
    std::cout << std::endl;

    std::cout << "What month date would you like to check?" << std::endl;
    std::cout << "example: for 14 May 2022, input 5" << std::endl;
    std::cin >> month_check;
    std::cout << std::endl;

    std::cout << "What year date would you like to check?" << std::endl;
    std::cout << "example: for 14 September 2022, input 22" << std::endl;
    std::cin >> year_check;
    std::cout << std::endl;

    Biorhythms MainBio(day_born, month_born, year_born, day_check, month_check, year_check);
    MainBio.Main();
    int n;
    std::cin >> n;
}

