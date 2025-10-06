//
//  main.cpp
//  Lab 19
//
//  Created by Nafi on 10/5/25.
//
//COSMC 210|Mehraj Hasan Nafi
// IDE used: XCode

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Review {
    float rating;
    string comment;
    Review *next;
};

class Movie {
private:
    string title;
    Review *head;
public:
    Movie(string t) : title(t), head(nullptr) {}
    
    ~Movie() {
        while (head){
            Review *temp = head;
            head =  head->next;
            delete temp;
        }
    }
    
    void review(float rating, string &comment) {
            Review *newNode = new Review{rating, comment, nullptr};
            if (!head = nullptr) {
                head = newNode;
            } else {
                Review *temp = head;
                while (temp->next)
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    
    void output() {
        int count = 0;
        float total = 0;
        Review *temp = head;
        while (temp) {
            total += temp->rating;
            count++;
            temp = temp->next;
        }

        float avg = (count > 0) ? total / count : 0;

        cout << "Movie: " << title
             << " (Average Rating: " << fixed << setprecision(1) << avg << "\n";
            temp = head;
        count = 0;
        while (temp) {
            cout << "    > Review #" << ++count
                 << ": " << temp->comment
                 << " [" << fixed << setprecision(1) << temp->rating << endl;
            
            temp = temp->next;
        }
        cout << endl;
    }
};

float ran() {
    int r = rand() % 41 + 10;
    return r / 10.0f;
}

int main() {
    srand(time(0));

    vector<Movie> movies;
    movies.emplace_back("My Little Pony");
    movies.emplace_back("Sofia the First");
    movies.emplace_back("Titanic");
    movies.emplace_back("The Notebook");

    ifstream file("review.txt");
        if (!file) {
            cerr << "Could not open review.txt\n";
            return 1;
        }

        vector<string> comments;
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                comments.push_back(line);
            }
        }
        file.close();

        int num = 0;
        for (auto &movie : movies) {
            for (int i = 0; i < 3 && num < (int)comments.size(); i++) {
                float rating = ran();
                movie.review(rating, comments[num]);
                num++;
            }
        }

        for (auto &movie : movies)
            movie.output();

        return 0;
    }


