#include <iostream>
#include <windows.h>
#include <fstream>
#include "main.hpp"
#include "musiccontroller.cpp"

using namespace std;

class FileManager
{
    public:
    void SaveToFile(const string& filename, const MusicController& musicController)
    {
        ofstream openFile(filename);
        if (!openFile)
        {
            cout << "nuh uh not opening cuh" << endl;
            return;
        }else
        {
            for (const auto& note : musicController.Notes)
            {
                openFile << note.frequency << " " << note.duration << " " << note.delay << endl;
            }
        }
    }

    void LoadFromFile(const string& filename, MusicController& musicController)
    {
        ifstream openFile(filename);
        if (!openFile)
        {
            cout << "nuh uh not opening cuh" << endl;
            return;
        }else
        {
            musicController.reset();
        }

        int frequency;
        int duration;
        int delay;

        while(openFile >> frequency >> duration >> delay)
        {
            musicController.addNoteFromFile(frequency, duration, delay);
        }
    } 
};
