#include<iostream>
#include<chrono>
#include<thread>
#include<vector>
#include<windows.h>
#include "musiccontroller.cpp"
#include "filecontroller.cpp"
#include "main.hpp"

using namespace std;


int main()
{
    MusicController musicController;
    
    int a;
    int f; int d; int de;
    for(;;)
    {
        mainDisplay();
        cin >> a;
        switch(a)
        {
        case 1:
        {
            musicController.addNote(f, d, de);
            break;
        }
        case 2:
        {
            musicController.display();
            cout << musicController.getNoteCount() << " Notes" << endl;
            break;
        }
        case 3:
        {
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
        case 4:
        {
            removeDisplay();
            int choice;
            cin >> choice;
            switch(choice)
            {
                case 1:
                    musicController.reset();
                    cout << "Notes reset!" << endl;
                    break;
                case 2:
                    musicController.removeNote(musicController.Notes.size() - 1);
                    cout << "Last note removed!" << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
                break;
            }
            break;
        }
        case 5:
        {
            FileManager fileManager;
            string filename;
            cin >> filename;
            fileManager.SaveToFile(filename, musicController);
            break;
        }
        case 6:
        {
            FileManager fileManager;
            string filename;
            cin >> filename;
            musicController.reset();
            fileManager.LoadFromFile(filename, musicController);
            break;
        }
        default:
            cout << "not valid gng" << endl;
        break;
        }

    }

    return 0;
}