#include<iostream>
#include<chrono>
#include<thread>
#include<vector>
#include<windows.h>
#ifndef MUSICCONTROLLER_H
#define MUSICCONTROLLER_H
#ifndef NOTE_H
#define NOTE_H

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

        return Notes.size() - 1, mark;
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

    int reset()
    {
        Notes.clear();
        mark = 0;
        return mark;
    }

    int getNoteCount()
    {
        return Notes.size();
    }

    int removeNote(int i)
    {
        if (i < 0 || i >= Notes.size())
        {
            cout << "Invalid note index." << endl;

            return -1;
        }else
        {
            Notes.erase(Notes.begin()+i);
            if(Notes.size() == 0)
            {
                mark = 0;
                return mark;
            }
        }
        return Notes.size();
    }

    int addNoteFromFile(int frequency, int duration, int delay)
    {
        Note newNote = { frequency, duration, delay };
        Notes.push_back(newNote);
        mark = 1;
        
        return Notes.size() - 1, mark;
    }
};

#endif
#endif