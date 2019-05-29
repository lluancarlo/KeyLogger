#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

namespace Helper{
    template <class T>

    std::string ToString(const T &);

    struct DateTime{
        DateTime(){
            time_t ms;
            time(&ms);
            struct tm *info = localtime(&ms);
            D = info->tm_mday;
            M = info->tm_mon+1;
            Y = 1900 + info->tm_year;
            h = info->tm_hour;
            m = info->tm_min;
            s = info->tm_sec;
        }

        DateTime(int D, int M, int Y, int h, int m, int s) : D(D), M(M), Y(Y), h(h), m(m), s(s) {}
        DateTime(int D, int M, int Y) : D(D), M(M), Y(Y), h(0), m(0), s(0) {}

        DateTime Now() const{
            return DateTime();
        }

        int D, M, Y, h, m, s;

        std::string GetDateString() const{
            return std::string( D<10?"0":"") + ToString(D)+
                    std::string(D<10?".0":"") + ToString(M) + "." +
                    ToString(Y);
        }

        std::string GetTimeString(const std::string &sep = ":") const {
            return std::string( h<10?"0":"") + ToString(h) + sep +
                    std::string( m<10?"0":"") + ToString(m) + sep +
                    std::string( s<10?sep:"") + ToString(s);
        }

        std::string GetDateTimeString( const std::string &sep = ":") const {
            return GetDateString() + " " + GetTimeString(sep);
        }
    };

    template <class T>
    std::string ToString(const T &e){
        std::ostringstream s;
        s << e;
        return s.str();
    }

    void WriteAppLog( const std::string &s){
        std::ofstream file("AppLog.txt", std::ios::app);
        file << "[" << Helper::DateTime().GetDateTimeString() << "]" <<
        "\n" << s << std::endl << "\n";
        file.close();
    }
}

#endif // HELPER_H
