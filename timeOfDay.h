#pragma once
#include <iostream>
namespace ParkSeohee2114012
{
    class timeOfDay
    {
        int hour;
        int minute;
        void testHour() {
            if (hour < 0 || hour>23) {
                std::cout << "invalid hour\n";
                std::exit(1);
            }
        }
        void testMinute() {
            if (minute < 0 || minute >59) {
                std::cout << "invalid minute\n";
                std::exit(1);
            }
        }
    public:
        timeOfDay(int h = 0, int m = 0):hour{h}, minute{m}{testHour();testMinute();}
        void input() {
            std::cout << "Enter hour(0~23): "; std::cin >> hour; testHour();
            std::cout << "Enter minute(0~59): "; std::cin >> minute; testMinute();
        }
        void setHour(int h) {hour = h; testHour();}
        void setMinute(int m) { minute = m; testMinute();}
        void print() const  {
          os << std::setw(2) << std::setfill('0') << hour << ":";
          os << std::setw(2) << std::setfill('0') << minute;
        }
        
                // if (hour < 10) std::cout << "0";
                // std::cout << hour << ":"; 
                // if (minute < 10) std::cout << "0";
                // std::cout << minute;}
        int getHour() const {return hour;}
        int getMinute() const {return minute;}

     timeOfDay operator++()
      {
        ++minute; //0~59
        if (minute == 60) { minute = 0; ++hour;}
        if (hour == 24) {hour = 0;}
        return *this;
      }
      timeOfDay operator++(int)
      {
        timeOfDay temp{*this};
        ++(*this);
        return temp;
      } 
      timeOfDay& operator+=(int m)
      {
        std::cout << *this << std::endl;
        minute += m ;
        if (minute >= 60) { hour +=minute/60;  minute %= 60;} 
        if (hour >= 24) {hour %= 24;}
        return *this;
      }
      friend std::istream& operator>>(std::istream& is, timeOfDay& t)
      {
        //std::cin (input()) --> is
        std::cout << "Enter hour(0~23): "; is >> t.hour; t.testHour();
        std::cout << "Enter minute(0~59): "; is >> t.minute; t.testMinute();
        return is;
      } 
      friend std::ostream& operator<<(std::ostream& os, const timeOfDay& t)
      { //std::cout (print()) -->os
        //std::cout (print()) --> os
        //if (t.hour < 10) os << "0"; os << t.hour << ":";
        //if (t.minute < 10) os << "0"; os << t.minute;
        os.width(2);
        os.fill('0');
        os << t.hour << ":";
        return os;
      }
      friend bool operator==(const timeOfDay& t1, const timeOfDay& t2)
      {
        return t1.hour == t2.hour && t1.minute == t2.minute;
      }
      friend timeOfDay operator+(const timeOfDay& t1, const timeOfDay& t2)
      {//59+1
        int minute1{t1.minute + t1.hour*60};
        int minute2{t2.minute + t2.hour*60};
        int totalMinute{minute1 + minute2};
        int newHour{totalMinute/60}; //0~23
        if (newHour >= 24) newHour = newHour %24;
        int newMinute{totalMinute%60};
        return timeOfDay{newHour, newMinute};};
      };
    };


// 3. alarm.h: alarm 클래스 정의
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언: timeOfDay형 wakeTime, bool형 inActive
// public 멤버함수 인라인으로 정의
// -생성자: 모든 멤버변수 초기화, 기본값 설정
// -print: 표준스트림출력으로 멤버변수들 출력, hour:minute alarm is on/off 형식
// -wakeTime의 접근함수를 참조형식으로 구현

// 4. main.cpp: 테스트
// 1의 본인이름학번의 네임스페이스 안에 비멤버함수 compareTimeOfDay 정의: 매개변수는 const timeOfDay 참조형 2개, 매개변수 멤버들이 모두 같은지를 비교
// -main
// alarm 클래스형 객체1 선언, print함수 호출
// alarm 클래스형 객체2 초기값을 넣어서 선언, print함수 호출
// 비멤버함수 compareTimeOfDay를 호출하여 그 리턴값이 true면 same, false면 different를 표준스트림으로 출력
