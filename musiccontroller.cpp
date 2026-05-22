#include<iostream>
#include<chrono>
#include<thread>
#include<vector>
#include<windows.h>

using namespace std;

struct Note
{
    int frequency;
    int duration;
    int delay;
};

class MusicController
{
    public:
    vector<Note> Notes;

    //adds note
    int mark = 0;
    int addNote(int frequency, int duration, int delay)
    {
        cin >> frequency >> duration >> delay;
        Note newNote = { frequency, duration, delay };
        Notes.push_back(newNote);
        mark = 1;

        return mark;
        return Notes.size() - 1;
    }

    //play note
    void playNote(int i)
    {
        if (i < 0 || i >= Notes.size())
        {
            cout << "Invalid note index." << endl;

            return;
        }else
        {
        const auto& Note = Notes[i];
        Beep(Note.frequency, Note.duration);
        Sleep(Note.delay);
        }
    }
};