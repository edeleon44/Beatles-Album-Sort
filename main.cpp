/*
 * Author: DeLeon Edward Jr
 * Date: April 20, 2021
 * Assignment: Beatles Album List Sort
 * Note:
 *      1. I had to go back and create object in the vactor in order to look at each song..
 *      2. once object.sort ---> we needed to albus.pushback(object) --> find and push the object to vector "albums"
 *      3. I still have a open file prblem on different OS systems. Look into it..
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Album {
   private:
       string albumName;
       string releaseDate;
       string genre;
       vector<string> songs;
   public :
       void setAlbumName(string);
       void setReleaseDate(string);
       void setGenre(string);
       void pushSong(string);
       string getAlbumName();
       string getReleaseDate();
       string getGenre();
       vector<string> getSongs();
      
       void sortSongs();
};

void Album :: setAlbumName(string albumName) {
   this -> albumName = albumName;
}

void Album :: setReleaseDate(string releaseDate) {
   this -> releaseDate = releaseDate;
}

void Album :: setGenre(string genre) {
   this -> genre = genre;
}

void Album :: pushSong(string song) {
   songs.push_back(song);
}

string Album :: getAlbumName() {
   return albumName;
}

string Album :: getReleaseDate() {
   return releaseDate;
}

string Album :: getGenre() {
   return genre;
}

vector<string> Album :: getSongs() {
   return songs;
}

void Album :: sortSongs() {
   sort(songs.begin(), songs.end());
}

bool alphabetCompare(Album a, Album b) {
   return a.getAlbumName() < b.getAlbumName();
}

void display(Album object) {
   cout << "Album Name: " << object.getAlbumName() << "\n";
   cout << "Release Date: " << object.getReleaseDate() << "\n";
   cout << "Genre: " << object.getGenre() << "\n";
   cout << "Songs: \n";
   vector<string> songs = object.getSongs();
   for (int i = 0; i < songs.size(); ++i) {
       cout << "\t" << i + 1 << " " << songs[i] << "\n";
   }
   cout << "==============" << "\n\n";
}

int main() {
   string s;
   freopen("Beatles.rtf", "r", stdin);
   vector<Album> albums;
   while (getline(cin, s)) {
       Album object;
       object.setAlbumName(s);
       while (getline(cin, s)) {
           if (s[0] == '=') {
               break;
           }
           if (s.substr(0, 8) == "Released") {
               object.setReleaseDate(s.substr(8));
           } else if (s.substr(0, 5) == "Genre") {
               object.setGenre(s.substr(5));
           } else {
               for (int i = 0; i < s.size(); ++i) {
                   if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                       object.pushSong(s.substr(i));
                       break;
                   }
               }
           }
       }
       object.sortSongs();
       albums.push_back(object);
   }
    sort(albums.begin(), albums.end(), alphabetCompare);

    for (int i = 0; i < albums.size(); ++i) {
        display(albums[i]);
    }
  
}
