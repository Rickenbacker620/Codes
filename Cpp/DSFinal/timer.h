#include <chrono>
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::chrono::steady_clock;
using std::chrono::time_point;

class Timer
{
  public:
    Timer()
    {
        start = steady_clock::now();
        cout << "-------------------------" << endl;
    }
    ~Timer()
    {
        auto end = steady_clock::now();
        auto duration = std::chrono::duration<double>(end - start);
        cout << "Time passed:" << std::fixed << std::setprecision(5) << duration.count() << 's' << endl;
        cout << endl;
    }

  private:
    std::chrono::time_point<std::chrono::steady_clock> start;
};