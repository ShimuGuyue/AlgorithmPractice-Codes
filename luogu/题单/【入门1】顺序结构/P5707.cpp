#include <iostream>

int main(void)
{
    int s, v;
    std::cin >> s >> v;
    int time(10);
    time += s % v ? s / v + 1 : s / v;
    int m(time % 60);
    int h(m ? time / 60 + 1 : time / 60);
    if (m == 0)
    {
        m = 60;
        --h;
    }
    int hour(8 - h);
    int min(60 - m);
    if (hour < 0)
        hour = 24 + hour;
    std::cout << (hour < 10 ? "0" : "") << hour << ":" 
              << (min < 10 ? "0" : "") << min << std::endl;
    return 0;
}