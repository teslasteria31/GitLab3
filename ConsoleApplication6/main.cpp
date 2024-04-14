#include <iostream>
#include <fstream>

#include "MusicaLibrary.h"
#include "functions.h"

using namespace std;
using namespace functions;

int main() {

    MusicLibrary* arr = nullptr;
    string YN;
    bool toggle = true;
    int n{}, m{}, d_id{}, s_id{}, c_id{}, option{};

    // greating moment

    greeting();

    while (toggle) {

        // navigation pannel

        select_an_option();
        cin >> option;

        switch (option) {
        case 1:

            // create and record elements to array
            creating:

            cout << "\n|Enter how much songs would you like to record: ";
            cin >> n;
            if (n < 1) return 0;
            
            arr = create(n);

            break;

        case 2:
            // add new elements to array

            if (n < 1) {
                cout << "\n|You didn't create an array yet, please, create a new one" << endl;
                goto creating;
                
            }

            cout << "\n|Enter how much songs would you like to add: ";
            cin >> m;
            if (m < 1) return 0;

            arr = addMusicLibrary(arr, n, m);

            break;
        case 3:

            // print db array in terminal 

            if (n < 1) {
                cout << "\n|You didn't create an array yet, please, create a new one" << endl;
                goto creating;
            }

            print_arr(arr, n);
            break;

        case 4:

            // search

            if (n < 1) {
                cout << "\n|You didn't create an array yet, please, create a new one" << endl;
                goto creating;
            }

            cout << "\n|Enter ID of searching element: ";
            cin >> s_id;

            searchID(arr, n, s_id);
            break;

        case 5:

            //delete

            if (n < 1) {
                cout << "\n|You didn't create an array yet, please, create a new one" << endl;
                goto creating;
            }

            print_arr(arr, n);
            
            cout << "|Enter ID of deleting element: ";
            cin >> d_id;

            arr = deleteID(arr, n, d_id);
            break;

        case 6:

            // change

            if (n < 1) {
                cout << "\n|You didn't create an array yet, please, create a new one" << endl;
                goto creating;
            }

            cout << "\n|Enter ID of changing element: ";
            cin >> c_id;

            arr = changeID(arr, n, c_id);
            break;

        case 7:

            // load to file

            if (arr == nullptr) {
                cout << "\n| Array is empty\n";
            }
            save(arr, n);
            cout << "\n|Your data has been saved to file";
            break;

        case 8:

            // load from file

            arr = load(n);
            cout << "|Loaded " << n << " song(s)\n" << endl;
            if (!arr) {
                cout << "An array is empty" << endl;
                return 0;
            }
            for (int i = 0; i < n; i++) {
                cout << "|id: " << i << " |Title:" << arr[i].getTitle() << endl;
                cout << "|id: " << i << " |Artist:" << arr[i].getArtist() << endl;
                cout << "|id: " << i << " |Album:" << arr[i].getAlbum() << endl;
            }
            delete[] arr;
            break;

        default:
            toggle = false;
            exit();

            break;
        }

        // Continue cycle or break it

        cout << "\n|Would you like to continue? [Y/N]" << endl;
        cin >> YN;

        if (YN == "Y") { toggle = true; system("cls"); }
        else  { toggle = false; }
    }

    if (arr != nullptr) {
        delete[] arr;
    }
    exit();
    return 0;
}