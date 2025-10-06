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
        while temp {
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

