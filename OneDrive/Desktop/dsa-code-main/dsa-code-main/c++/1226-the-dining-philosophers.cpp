#include <mutex>
#include <vector>
#include <functional>
using namespace std;

class DiningPhilosophers {
private:
    vector<mutex> forks; // one mutex per fork

public:
    DiningPhilosophers() : forks(5) { // 5 forks for 5 philosophers
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        // To avoid deadlock, always pick up lower-numbered fork first
        if (left < right) {
            forks[left].lock();
            forks[right].lock();
        } else {
            forks[right].lock();
            forks[left].lock();
        }

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        forks[left].unlock();
        forks[right].unlock();
    }
};