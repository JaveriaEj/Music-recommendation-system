#include <iostream>
#include <string>
using namespace std;

class Playlist;

class Admin {
public:
    void add_song(string songs[], int &index) {
        if (index>=30) {
            cout<<"Playlist is full, cannot add more songs.\n";
            return;
        }
        cout<<"Enter the song name, artist, and duration: ";
        cin.ignore();
        getline(cin, songs[index]);
        index++;
        cout<<"Song added successfully.\n";
    }
    void action() {
        cout<<"Admin-specific action.\n";
    }
    
    friend void resetPlaylist(Playlist &playlist);
};

class Playlist {
protected:
    string songs[30];
    int current_index;
public:
    Playlist() : current_index(21) {
        songs[0]="Bado_badi by Chaht fateh (duration: 2min)";
        songs[1]="Lover by Taylor Swift (duration: 2min)";
        songs[2]="G.O.A.T by Diljit Dosanjh (duration: 2min)";
        songs[3]="Baarish by Ash King (duration: 2min)";
        songs[4]="Isq Risk by Chahet Fateh (duration: 2min)";
        songs[5]="Cheap Thrills by Taylor Swift (duration: 2min)";
        songs[6]="Unstoppable by Sia (duration 3min)";
        songs[7]="Kar har maidan fateh by Sukhwinder Goshaal (duration: 1min)";
        songs[8]="Let me Down slowly by Alec Benjamin (duration: 3min)";
        songs[9]="Yeh Raatein Ye mausam by Kishore Kumar (duration: 2.34 min)";
        songs[10]="Moonrise by Guru Randhawa (duration: 1.67min)";
        songs[11]="Spain by Thiarajxtt (duration: 2 min)";
        songs[12]="Moonlight By Harnoor (duration: 3.1 min)";
        songs[13]="Baarish by Ash King (duration: 2 min)";
        songs[14]="We Rollin By Subh (duration: 2 min)";
        songs[15]="Afterhours by Thiarajxtt (duration: 4 min)";
        songs[16]="Mercy by Badshah (duration: 1 min)";
        songs[17]="Blankspace by Taylor Swift (duration: 3 min)";
        songs[18]="Down Bad by Taylor Swift (duration: 2min)";
        songs[19]="O Yarra by Abdul Hanan (duration: 2.2 min)";
        songs[20]="Attention by Charlie Puth (duration: 2 min)";
        for(int i = 21; i < 30; i++) {
            songs[i]=" ";
        }
    }

    void display_all_songs() {
        for(int i = 0; i < 30; i++) {
            if(songs[i] != " ") {
                cout<<"-> "<<songs[i]<<endl;
            }
        }
    }
    
    friend void resetPlaylist(Playlist &playlist); 
};

void resetPlaylist(Playlist &playlist) {
    playlist.current_index = 0;
    cout<<"Playlist has been reset. Current index is now "<<playlist.current_index<<".\n";
}

class PatternPrinter {
public:
    void printPattern() {
        for (int i = 0; i < 19; i++) {
            cout<<"*";
        }
        cout<<endl;

        cout<<"WELCOME"<<endl;

        for(int i = 0; i < 19; i++) {
            cout<<"*";
        }
        cout<<endl;
    }
};

class Person {
public:
    virtual void action() = 0; 
};

class User : public Person {
private:
    string mood;
    string genre;
    string weather;
public:
    User() {
        mood = " ";
        genre = " ";
        weather = " ";
    }
    void action() override {
        cout<<"User-specific action.\n";
    }
};

class DisplayUpdate : public Playlist {
public:
    void happy_songs() {
        for(int i = 0; i <= 4; i++) {
            cout<<"-> "<<songs[i]<<endl;
        }
    }
    void motivation() {
        for (int i = 5; i <= 7; i++) {
            cout << "-> " << songs[i] << endl;
        }
    }
    void night() {
        for(int i = 8; i <= 13; i++) {
            cout<<"-> "<<songs[i]<<endl;
        }
    }
    void pop() {
        for(int i = 14; i <= 20; i++) {
            cout<<"-> "<<songs[i]<<endl;
        }
    }
    void display_all_songs() {
        for(int i = 0; i < 30; i++) {
            if (songs[i] != " ") {
                cout<<"-> "<<songs[i]<<endl;
            }
        }
    }
    void add_song_to_playlist() {
        Admin admin_obj;
        admin_obj.add_song(songs, current_index);
    }
};

class Login {
private:
    string person;
    string username;
    int psdU, psdA;
public:
    int password;
    Login(string a, string d) {
        person = a;
        username = d;
        psdU = 123;
        psdA = 321;
    }
void func() {
    if (person == "user") {
        cout << "Your username is: " << username << "_108 \n";
        cout << "Your password is 123" << endl;
        do {
            cout << "Now Enter The provided password\n";
            cin >> password;
            if (psdU == password) {
                cout << "You have successfully logged in as a user. \n";
                break;
            }
            else {
                cout << "Invalid password. Try again.\n";
            }
        } while (true);
    }
    else if (person == "admin") {
        cout << "Your username is: " << username << "_admin \n";
        cout << "Your password is 321" << endl;
        do {
            cout << "Now Enter The provided password\n";
            cin >> password;
            if (psdA == password) {
                cout << "You have successfully logged in as an admin. \n";
                break;
            }
            else {
                cout << "Invalid password. Try again.\n";
            }
        } while (true);
    }
}
    
};

class A {
    Login a;
    DisplayUpdate objp;
public:
    A(string per, string usnme) : a(per, usnme) {}
    void loginfun() {
        a.func();
    }
    void display_playlist(string mood, string genre, string weather) {
        if ((mood == "happy" || mood == "motivated") && weather == "sunny" && (genre == "comedy" || genre == "desi")) {
            objp.happy_songs();
            objp.motivation();
        }
        else if ((mood == "happy" || mood == "gloomy" || mood == "depressed") && (weather == "rainy" || weather == "windy" || weather == "sunny") && (genre == "comedy" || genre == "fresh finds" || genre == "depressed" || genre == "pop music")) {
            objp.night();
            objp.pop();
        } else {
            objp.display_all_songs();
        }
    }
    void add_songs_to_playlist() {
        objp.add_song_to_playlist();
    }
    void display_all_songs() {
        objp.display_all_songs();
    }
    void reset_playlist() {
        resetPlaylist(objp); 
    }
};

int main() {
    string per, usnme, weather, mood, genre;
    PatternPrinter printer;
    printer.printPattern();

    cout<<"Enter your user type (either user or admin):\n";
    cin>>per;
    cout<<"Enter your username: \n";
    cin>>usnme;
    A obja(per, usnme);
    obja.loginfun();

    if (per == "admin") {
        int choice;
        do {
            cout<<"1. Add songs\n2. Display all songs\n3. Reset playlist\n4. Exit\nEnter your choice: ";
            cin>>choice;
            switch (choice) {
                case 1:
                    obja.add_songs_to_playlist();
                    break;
                case 2:
                    obja.display_all_songs();
                    break;
                case 3:
                    obja.reset_playlist();
                    break;
                case 4:
                    cout<<"Exiting...\n";
                    break;
                default:
                    cout<<"Invalid choice. Try again.\n";
            }
        } while(choice != 4);
    }
    else if(per == "user") {
        cout<<"Enter mood (happy, gloomy, depressed, motivated):\n";
        cin>>mood;
        cout<<"Enter genre (pop music, desi, comedy, fresh finds):\n";
        cin>>genre;
        cout<<"Enter weather (sunny, rainy, windy):\n";
        cin>>weather;

        User userobj;
        obja.display_playlist(mood, genre, weather);
    }

    return 0;
}
