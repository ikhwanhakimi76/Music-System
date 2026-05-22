#include<iostream>
#include<chrono>
#include<thread>
#include<vector>
#include<windows.h>
#include "musiccontroller.cpp"

using namespace std;


int main()
{
    MusicController musicController;
    int a;
    int f; int d; int de;
    for(;;)
    {
        cin >> a;
        switch(a)
        {
        case 1:
            musicController.addNote(f, d, de);
            break;
        case 2:
            if(musicController.mark == 0)
            {
                cout << "No notes here :(" << endl;
            }else
            {
                for(int i = 0; i < musicController.Notes.size(); i++)
                {
                    musicController.playNote(i);
                }
            }
            break;
        }

    }

    return 0;
}