#include <iostream>
using namespace std;
using Function = void(*)();
class Task
{
public:
    void(**func)();
    int operation_time;
    int tick;
    bool muted;
    virtual void init_memory()
    {

    }


    Task()
    {

    }

    Task(void(**funcs)(), int ticks) : Task()
    {
        tick = ticks;
        func = funcs;
        operation_time = 0;
        muted = false;
    }

    bool Getmute()
    {
        return this->muted;
    }

    void Pause()
    {
        this->muted = true;
    }

    void Continue()
    {
        this->muted = false;
    }

    int Getlocaltime()
    {
        return operation_time;
    }

    Function Do()
    {
        increase();
        return func[operation_time - 1];
    }

    void increase()
    {
        if (operation_time < tick)
        {
            operation_time++;
        }
        else
        {
            operation_time = 1;
        }
    }
};

class Scheduler
{
private:
    Task* task;
    int global_time;
    int operation_time;

public:
    Scheduler() {};
    Scheduler(Task* tasks)
    {
        global_time = 0;
        operation_time = 0;
        task = tasks;
    }

    Function Do()
    {
        increase();
        return task[operation_time - 1].Do();
    }

    void increase()
    {
        bool is = false;
        while (!is)
        {
            if (operation_time < sizeof(task) - 1)
            {
                operation_time++;
                //cout << "Scheduler opp time = " << operation_time << endl;
            }
            else
            {
                operation_time = 1;
            }

            if (!(task[operation_time - 1].Getmute()))
            {
                is = true;
            }
            else
            {
                is = false;
            }
        }
    }
};

void Task21()
{
    cout << "Task2.1" << endl;
}

void Task22()
{
    cout << "Task2.2" << endl;
}

void Task11()
{
    cout << "Task1.1" << endl;
}

void Task12()
{
    cout << "Task1.2" << endl;
}

void Task13()
{
    cout << "Task1.3" << endl;
}

void Task31()
{
    cout << "Task3.1" << endl;
}

void Task32()
{
    cout << "Task3.2" << endl;
}

void Task33()
{
    cout << "Task3.3" << endl;
}

void Task34()
{
    cout << "Task3.4" << endl;
}

void Task35()
{
    cout << "Task3.5" << endl;
}

void Task36()
{
    cout << "Task3.6" << endl;
}

int main(void)
{
    void(*curr)();
    int c = 0;
    void(*func[2])() = { Task21,Task22 };
    Task task(func, 2);

    void(*funcc[3])() = { Task11,Task12,Task13 };
    Task task1(funcc, 3);

    void(*funccc[6])() = { Task31,Task32,Task33,Task34,Task35,Task36 };
    Task task2(funccc, 6);

    Task tasks[3] = { task1,task,task2 };
    Scheduler scheduler(tasks);
    cout << "First iteration:\n" << endl;
    for (int i = 0; i < 30; i++)
    {
        curr = scheduler.Do();
        curr();
    }
    cout << "Second iteration:\n" << endl;
    tasks[2].Pause();
    cin >> c;
    for (int i = 0; i < 30; i++)
    {
        curr = scheduler.Do();
        curr();
    }
    cout << "Third iteration:\n" << endl;
    tasks[2].Continue();

    for (int i = 0; i < 30; i++)
    {
        curr = scheduler.Do();
        curr();
    }
}
